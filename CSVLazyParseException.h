//
// Created by nikol on 04.12.2021.
//

#ifndef LAB_4_CSVLAZYPARSEEXCEPTION_H
#define LAB_4_CSVLAZYPARSEEXCEPTION_H


#include "CSVException.h"
#include <string>
#include <utility>

class CSVLazyParseException : public CSVException {
public:
    CSVLazyParseException(std::string msg, int row, int column)
        : CSVException(std::move(msg)), row(row), column(column){}

    [[nodiscard]] int getRow() const noexcept{
        return row;
    }

    [[nodiscard]] int getColumn() const noexcept{
        return column;
    }

private:
    int row;
    int column;
};


#endif //LAB_4_CSVLAZYPARSEEXCEPTION_H
