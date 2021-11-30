//
// Created by nikol on 30.11.2021.
//

#include "CSVStringCellMakerImpl.h"
#include "StringCellMakerException.h"

CSVStringCellMakerImpl::CSVStringCellMakerImpl() {
    cellMade = false;
    rowEnd = false;
}

bool CSVStringCellMakerImpl::hasCellMade() {
    return cellMade;
}

bool CSVStringCellMakerImpl::hasRowEnd() {
    return rowEnd;
}

void CSVStringCellMakerImpl::push(char value) {
    if(rowEnd)
        throw StringCellMakerException("error pushing character, row is end");
    if(cellMade)
        throw StringCellMakerException("error pushing character, cell is made");

    shieldingWatcher.pushCharacter(value);
    if(shieldingWatcher.isShieldingText()){
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

std::string CSVStringCellMakerImpl::getCellValue() {
    std::string tmp = cell;
    cell.clear();
    rowEnd = false;
    cellMade = false;
    return tmp;
}


