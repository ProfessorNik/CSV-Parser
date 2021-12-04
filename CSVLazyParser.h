//
// Created by nikol on 29.11.2021.
//

#ifndef LAB_4_CSVLAZYPARSER_H
#define LAB_4_CSVLAZYPARSER_H

#include <tuple>
#include <string>
#include <sstream>
#include <utility>
#include "CSVParserParametrs/CSVCellMaker.h"
#include "CSVLazyParseException.h"
#include "CSVParserParametrs/CellMakeException.h"

template <class... Args>
class CSVLazyParser {
public:
    explicit CSVLazyParser(std::shared_ptr<CSVCellMaker> maker, std::ifstream& file) : maker(std::move(maker)), file(file){
        it = line.begin();
    }

    void parse(){
        while (!eof()) {
            //этот флаг нужнен для выхода из цикла в функции parseCell(cells); т.к. для сборки каждой
            //следующей ячейки вызывается функция parseCell<n + 1>(cells) рекурсивно, нужно выйти из всех
            //предыдущих циклов откуда она вызвалась
            hasNotEscape = true;
            std::tuple<Args...> cells;
            parseCell<0>(cells);
            table.push_back(cells);
        }
    }
    const std::vector<std::tuple<Args...> > &getTable() const noexcept{
        return table;
    }


private:
    std::string line;

    std::string::iterator it;
    std::shared_ptr<CSVCellMaker> maker;
    std::ifstream& file;
    std::vector<std::tuple<Args...> > table;
    int numLine = 0;
    bool hasNotEscape{};

    char getNextCharacter(){
        if(it == line.end()) {
            numLine++;
            try {
                std::getline(file, line);
            }catch(const std::ios_base::failure& ex){
                throw CSVLazyParseException("last line is empty(delete enter from the end file)", numLine, 0);
            }
            line.push_back('\n');
            it = line.begin();
        }
        return *(it++);
    }

    bool eof(){
        return it == line.end() && file.eof();
    }

    template<size_t n>
    typename std::enable_if<(n < sizeof...(Args))>::type parseCell(std::tuple<Args...>& cells){
        while (hasNotEscape && !eof()){
            auto ch = getNextCharacter();
            try {
                maker->push(ch);
            } catch (const CellMakeException& ex){
                throw CSVLazyParseException(ex.what(), numLine, n + 1);
            }
            if(maker->hasCellMade()) {
                pushValue<n>(cells, maker->getCellValue());
                parseCell<n+1>(cells);
            }
            else if(maker->hasRowEnd()){
                pushValue<n>(cells, maker->getCellValue());
                hasNotEscape = false;
            }
        }
    }

    template<size_t n>
    [[noreturn]] typename std::enable_if<(n >= sizeof...(Args))>::type parseCell(std::tuple<Args...>& cells){
        throw CSVLazyParseException("number column in file more than allowable", numLine, n + 1);
    }

    template<size_t n>
    void pushValue(std::tuple<Args...>& cells, const std::string& str) {
        try {
            std::istringstream stream(str);
            stream.exceptions(std::istringstream::failbit);
            stream >> std::get<n>(cells);
        }catch (std::istringstream::failure &ex){
            throw CSVLazyParseException("type cell not valid", numLine, n + 1);
        }
    }



};

template<class charT, class trT, class T>
typename std::enable_if<(std::is_same_v<T, std::string>), typename std::basic_istringstream<charT, trT>&>::type
        operator>>(std::basic_istringstream<charT, trT>& st, T& t){
    t = st.str();
    return st;
}


#endif //LAB_4_CSVLAZYPARSER_H
