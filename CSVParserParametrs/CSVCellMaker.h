//
// Created by nikol on 30.11.2021.
//

#ifndef LAB_4_CSVCELLMAKER_H
#define LAB_4_CSVCELLMAKER_H

#include <string>

class CSVCellMaker {
public:
    virtual bool hasCellMade() = 0;
    virtual bool hasRowEnd() = 0;
    virtual void push(char value) = 0;
    virtual std::string getCellValue() = 0;
};


#endif //LAB_4_CSVCELLMAKER_H
