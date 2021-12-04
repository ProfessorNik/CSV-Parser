//
// Created by nikol on 30.11.2021.
//

#ifndef LAB_4_CELLMAKEEXCEPTION_H
#define LAB_4_CELLMAKEEXCEPTION_H

#include <exception>
#include <string>
#include <utility>
#include "../CSVException.h"

class CellMakeException : public CSVException{
public:
    explicit CellMakeException(std::string msg) : CSVException(std::move(msg)) {}
};


#endif //LAB_4_CELLMAKEEXCEPTION_H
