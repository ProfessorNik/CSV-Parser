//
// Created by nikol on 04.12.2021.
//

#ifndef LAB_4_CSVPARSEEXCEPTION_H
#define LAB_4_CSVPARSEEXCEPTION_H


#include "CSVException.h"

class CSVParseException : public CSVException{
public:
    CSVParseException(std::string msg, int row, int column)
    : CSVException(msg), row(row), column(column){}

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


#endif //LAB_4_CSVPARSEEXCEPTION_H
