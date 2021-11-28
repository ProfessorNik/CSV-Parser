//
// Created by nikol on 26.11.2021.
//

#include "CSVParser.h"
#include <iostream>

template<class... Args>
CSVParser<Args...>::CSVParser(const std::string &fileName, int skipFirstLinesCount) {
    customizeInputStream(fileName);
    parseFile();
}


template<class... Args>
void CSVParser<Args...>::customizeInputStream(const std::string &fileName) {
    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    file.open(fileName);
}

template<class... Args>
CSVParser<Args...>::~CSVParser() {
    file.close();
}

template<class... Args>
typename CSVParser<Args...>::InputIterator CSVParser<Args...>::begin() {
    //goToBeginningFile();
    return CSVParser::InputIterator(table.begin());
}

template<class... Args>
void CSVParser<Args...>::goToBeginningFile() {
    file.clear();
    file.seekg(0);
    for(int i = 0; i < skipFirsLinesCount; i++){
        std::string str;
        std::getline(file, str);
    }
}

template<class... Args>
CSVParser<Args...>::InputIterator::InputIterator(typename std::vector<std::tuple<Args...>>::iterator it) {
    this->it = it;
}

template<class... Args>
typename CSVParser<Args...>::InputIterator::value_type CSVParser<Args...>::InputIterator::operator*() const {
    return *it;
}


template<class... Args>
typename CSVParser<Args...>::InputIterator CSVParser<Args...>::end() {
    return CSVParser::InputIterator(table.end());
}

template<class... Args>
void CSVParser<Args...>::parseFile() {
    goToBeginningFile();
    while (!file.eof()){
        table.push_back(readNextLine());
    }
}

template<class... Args>
std::tuple<Args...> CSVParser<Args...>::readNextLine() {
    std::string str;
    std::getline(file, str);
    std::tuple<Args...> cells;
    auto it = str.begin();
    int numCell = 0;
    std::string timeLine;
    for(const char& sym : str){
        if(numCell >= sizeof...(Args)){
            throw std::invalid_argument("bad argument");
        }
        if(sym == ','){
            std::get<1>(cells) = timeLine;
            timeLine.clear();
            numCell++;
        } else{
            timeLine.push_back(sym);
        }
    }
    const int b = numCell;
    //std::get<b>(cells) = timeLine;
    return cells;
}

template<class... Args>
CSVParser<Args...>::InputIterator::InputIterator(const CSVParser::InputIterator &other) {
    this->it = other.it;
}

template<class... Args>
bool CSVParser<Args...>::InputIterator::operator==(const CSVParser::InputIterator &other) {
    return this->it == other.it;
}

template<class... Args>
bool CSVParser<Args...>::InputIterator::operator!=(const CSVParser::InputIterator &other) {
    return this->it != other.it;
}

template<class... Args>
typename CSVParser<Args...>::InputIterator &CSVParser<Args...>::InputIterator::operator++() {
    it++;
    return *this;
}

//template<class... Args>
//typename CSVParser<Args...>::InputIterator CSVParser<Args...>::InputIterator::operator++(int) const {
//    InputIterator tmp = *this;
//    ++(*this);
//    return tmp;
//
//}

template class CSVParser<std::string, std::string>;
template class CSVParser<int, std::string>;