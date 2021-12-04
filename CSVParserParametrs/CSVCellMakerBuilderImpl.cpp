//
// Created by nikol on 03.12.2021.
//

#include "CSVCellMakerBuilderImpl.h"

CSVCellMakerBuilderImpl::CSVCellMakerBuilderImpl() : maker(new CSVStringCellMaker){

}

void CSVCellMakerBuilderImpl::setRowSeparator(char ch) {
    maker->setRowSeparator(ch);
}

void CSVCellMakerBuilderImpl::setColumnSeparator(char ch) {
    maker->setColumnSeparator(ch);
}

void CSVCellMakerBuilderImpl::setShieldingCharacter(char ch) {
    maker->setShieldingCharacter(ch);
}

std::shared_ptr<CSVCellMaker> CSVCellMakerBuilderImpl::build() {
    return maker;
}


