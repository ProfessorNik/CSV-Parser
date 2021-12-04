//
// Created by nikol on 29.11.2021.
//

#ifndef LAB_4_CSVLINEPARSER_H
#define LAB_4_CSVLINEPARSER_H

#include <tuple>
#include <string>
#include <sstream>
#include <utility>
#include "CSVParserParametrs/CSVCellMaker.h"

template <class... Args>
class CSVLineParser {
public:
    void parse(){
        while (!eof()) {
            flag = true;
            std::tuple<Args...> cells;
            parseCell<0>(cells);
            table.push_back(cells);
        }
    }
    const std::vector<std::tuple<Args...> > &getTable() const {
        return table;
    }


    explicit CSVLineParser(std::shared_ptr<CSVCellMaker> maker, std::ifstream& file) : maker(std::move(maker)), file(file){
        it = line.begin();
    }



private:
    std::string line;

    std::string::iterator it;
    std::shared_ptr<CSVCellMaker> maker;
    std::ifstream& file;
    std::vector<std::tuple<Args...> > table;
    bool flag{};

    char getNextCharacter(){
        if(it == line.end()) {
            std::getline(file, line);
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
        while (flag && !eof()){
            auto ch = getNextCharacter();
            maker->push(ch);
            if(maker->hasCellMade()) {
                pushValue<n>(cells, maker->getCellValue());
                parseCell<n+1>(cells);
            }
            else if(maker->hasRowEnd()){
                pushValue<n>(cells, maker->getCellValue());
                flag = false;
            }
        }
    }

    template<size_t n>
    void pushValue(std::tuple<Args...>& cells, const std::string& str) {
        try {
            std::istringstream stream(str);
            stream.exceptions(std::istringstream::failbit);
            stream >> std::get<n>(cells);
        }catch (...){
            std::cout << "stream error" <<std::endl;
        }
    }

    template<size_t n>
    [[noreturn]] typename std::enable_if<(n >= sizeof...(Args))>::type parseCell(std::tuple<Args...>& cells){
        throw std::invalid_argument("bad argument");
    }

};

template<class charT, class trT, class T>
typename std::enable_if<(std::is_same_v<T, std::string>), typename std::basic_istringstream<charT, trT>&>::type
        operator>>(std::basic_istringstream<charT, trT>& st, T& t){
    t = st.str();
    return st;
}


#endif //LAB_4_CSVLINEPARSER_H
