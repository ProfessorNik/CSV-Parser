//
// Created by nikol on 30.11.2021.
//

#ifndef LAB_4_CSVSTRINGCELLMAKERIMPL_H
#define LAB_4_CSVSTRINGCELLMAKERIMPL_H

#include "CSVStringCellMaker.h"
#include "RowSeparatorCharacter.h"
#include "ColumnSeparatorCharacter.h"
#include "ShieldingWatcher.h"

class CSVStringCellMakerImpl : public CSVStringCellMaker{
public:
    CSVStringCellMakerImpl();

    bool hasCellMade() override;
    bool hasRowEnd() override;
    void push(char value) override;
    std::string getCellValue() override;

private:
    std::string cell;

    bool cellMade;
    bool rowEnd;

    RowSeparatorCharacter rowSep;
    ColumnSeparatorCharacter columnSep;
    ShieldingWatcher shieldingWatcher;
};


#endif //LAB_4_CSVSTRINGCELLMAKERIMPL_H
