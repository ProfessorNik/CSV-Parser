//
// Created by nikol on 04.12.2021.
//

#ifndef LAB_4_CSVEXCEPTION_H
#define LAB_4_CSVEXCEPTION_H

#include <exception>
#include <string>

class CSVException : public std::exception {
public:
    explicit CSVException(std::string msg) : msg(std::move(msg)) {}

    [[nodiscard]] const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_USE_NOEXCEPT override { return msg.c_str(); }

private:
    std::string msg;
};


#endif //LAB_4_CSVEXCEPTION_H
