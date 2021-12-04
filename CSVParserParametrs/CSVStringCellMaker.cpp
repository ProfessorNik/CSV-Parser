//
// Created by nikol on 30.11.2021.
//

#include "CSVStringCellMaker.h"
#include "CellMakeException.h"

CSVStringCellMaker::CSVStringCellMaker() {
    cellMade = false;
    rowEnd = false;
}

bool CSVStringCellMaker::hasCellMade() {
    return cellMade;
}

bool CSVStringCellMaker::hasRowEnd() {
    return rowEnd;
}

void CSVStringCellMaker::push(char value) {
    if(rowEnd)
        throw CellMakeException("error pushing character, row is end");
    if(cellMade)
        throw CellMakeException("error pushing character, cell is made");

    shieldingWatcher.pushCharacter(value);
    if(shieldingWatcher.isShieldingText()){
        if(rowSep.isSeparator(value)){
            throw CellMakeException("error shielding, the shielding space is not closed");
        }
        if(!shieldingWatcher.isShieldingCharacter(value))
            cell.push_back(value);
    }
    else{
        if (columnSep.isSeparator(value)){
            cellMade = true;
        }
        else if(rowSep.isSeparator(value)){
            rowEnd = true;
        }
        else if(!shieldingWatcher.isShieldingCharacter(value)){
            cell.push_back(value);
        }
    }
}

std::string CSVStringCellMaker::getCellValue() {
    std::string tmp = cell;
    cell.clear();
    rowEnd = false;
    cellMade = false;
    return tmp;
}

void CSVStringCellMaker::setRowSeparator(char ch) {
    rowSep.setSeparator(ch);
}

void CSVStringCellMaker::setColumnSeparator(char ch) {
    columnSep.setSeparator(ch);
}

void CSVStringCellMaker::setShieldingCharacter(char ch) {
    shieldingWatcher.setShieldingCharacter(ch);
}


