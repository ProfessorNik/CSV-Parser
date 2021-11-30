//
// Created by nikol on 29.11.2021.
//

#ifndef LAB_4_CSVLINEPARSER_H
#define LAB_4_CSVLINEPARSER_H

#include <tuple>
#include <string>
#include <sstream>

template <class... Args>
class CSVLineParser {
public:
    void parse(){
        it = line.begin();
        parseCell<0>();
    }
    const std::tuple<Args...> &getRow() const {
        return cells;
    }


    explicit CSVLineParser(const std::string& line){
        this->line = line;
    }

private:
    std::string line;
    std::tuple<Args...> cells;
    std::string::iterator it;

    template<size_t n>
    typename std::enable_if<(n < sizeof...(Args))>::type parseCell(){
        std::string timeLine;
        if(it == line.end()){
            pushValue<n>(timeLine);
        }
        while(it != line.end()){
            if(*it == ','){
                pushValue<n>(timeLine);
                ++it;
                parseCell<n+1>();
            } else {
                timeLine.push_back(*it);
                it++;
                if(it == line.end()){
                    pushValue<n>(timeLine);
                }
            }
        }
    }
    template<size_t n>
    void pushValue(const std::string& str){
        std::stringstream stream(str);
        stream.exceptions(std::stringstream::failbit);
        stream >> std::get<n>(cells);
    }

    template<size_t n>
    typename std::enable_if<(n >= sizeof...(Args))>::type parseCell(){
        throw std::invalid_argument("bad argument");
    }



};


#endif //LAB_4_CSVLINEPARSER_H
