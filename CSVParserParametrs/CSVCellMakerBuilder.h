//
// Created by nikol on 03.12.2021.
//

#ifndef LAB_4_CSVCELLMAKERBUILDER_H
#define LAB_4_CSVCELLMAKERBUILDER_H

#include "CSVCellMaker.h"
#include "memory"

class CSVCellMakerBuilder {
public:
    virtual void setRowSeparator(char ch) = 0;
    virtual void setColumnSeparator(char ch) = 0;
    virtual void setShieldingCharacter(char ch) = 0;
    virtual std::shared_ptr<CSVCellMaker> build() = 0;
};


#endif //LAB_4_CSVCELLMAKERBUILDER_H
