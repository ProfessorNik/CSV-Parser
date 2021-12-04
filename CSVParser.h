//
// Created by nikol on 26.11.2021.
//

#ifndef LAB_4_CSVPARSER_H
#define LAB_4_CSVPARSER_H

#include <string>
#include <fstream>
#include <memory>
#include <utility>
#include <vector>
#include "CSVLazyParser.h"
#include "CSVParserParametrs/CSVCellMaker.h"
#include "CSVParserParametrs/CSVStringCellMaker.h"
#include "CSVParseException.h"


template<class... Args>
class CSVParser {
public:
    explicit CSVParser(const std::string& fileName, int skipFirstLinesCount = 0) : maker(new CSVStringCellMaker), skipFirsLinesCount(skipFirstLinesCount){
        customizeInputStream(fileName);
        parseFile();
    }
    explicit CSVParser(const std::string& fileName, std::shared_ptr<CSVCellMaker> maker, int skipFirstLinesCount = 0):maker(std::move(maker)), skipFirsLinesCount(skipFirstLinesCount){
        customizeInputStream(fileName);
        parseFile();
    }

    virtual ~CSVParser() {
        file.close();
    }

    struct InputIterator{
        typedef typename std::tuple<Args...> value_type;
        typedef value_type& reference;
        typedef value_type* pointer;
        typedef std::input_iterator_tag iterator_category;

        explicit InputIterator(typename std::vector<std::tuple<Args...> >::iterator it){
            this->it = it;
        }
        InputIterator(const InputIterator& other){
            this->it = other.it;
        }

        InputIterator& operator++() {
            it++;
            return *this;
        }

        InputIterator operator++(int) const{
            InputIterator tmp = *this;
            ++(*this);
            return tmp;
        }

        value_type operator*() const{
            return *it;
        }

        bool operator==(const InputIterator& other) {
            return this->it == other.it;
        }
        bool operator!=(const InputIterator& other) {
            return this->it != other.it;
        }

    private:
        typename std::vector<std::tuple<Args...> >::iterator it;
    };

    InputIterator begin(){
        return CSVParser::InputIterator(table.begin());
    }

    InputIterator end(){
        return CSVParser::InputIterator(table.end());
    }

private:
    std::shared_ptr<CSVCellMaker> maker;
    std::vector<std::tuple<Args...>> table;
    std::ifstream file;
    int skipFirsLinesCount{};

    void customizeInputStream(const std::string& fileName){
        try {
            file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            file.open(fileName);
        }catch(const std::ifstream::failure& ex) {
            throw CSVParseException(std::string("file ") + fileName + std::string(" isn't open"), 0, 0);
        }
    }

    void skipFirstLines(){
        for(int i = 0; i < skipFirsLinesCount; i++){
            std::string str;
            std::getline(file, str);
        }
    }

    void parseFile() {
        try {
            skipFirstLines();
            CSVLazyParser<Args...> parser(maker, file);
            parser.parse();
            table = parser.getTable();
        } catch (const CSVLazyParseException& ex){
            throw CSVParseException(ex.what(), ex.getRow() + skipFirsLinesCount, ex.getColumn());
        }
    }
};



#endif //LAB_4_CSVPARSER_H
