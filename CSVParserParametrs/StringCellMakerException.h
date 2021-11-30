//
// Created by nikol on 30.11.2021.
//

#ifndef LAB_4_STRINGCELLMAKEREXCEPTION_H
#define LAB_4_STRINGCELLMAKEREXCEPTION_H

#include <exception>
#include <string>
#include <utility>

class StringCellMakerException : public std::exception{
public:
    explicit StringCellMakerException(std::string msg) : msg(std::move(msg)) {}

    const char* what() { return msg.c_str(); }
private:
    std::string msg;
};


#endif //LAB_4_STRINGCELLMAKEREXCEPTION_H
