//
// Created by nikol on 03.12.2021.
//

#ifndef LAB_4_CSVCELLMAKERBUILDERIMPL_H
#define LAB_4_CSVCELLMAKERBUILDERIMPL_H


#include "CSVCellMakerBuilder.h"
#include "CSVStringCellMakerImpl.h"

class CSVCellMakerBuilderImpl : public CSVCellMakerBuilder {
public:
    CSVCellMakerBuilderImpl();

    void setRowSeparator(char ch) override;
    void setColumnSeparator(char ch) override;
    void setShieldingCharacter(char ch) override;
    std::shared_ptr<CSVCellMaker> build() override;

private:
    std::shared_ptr<CSVStringCellMakerImpl> maker;
};


#endif //LAB_4_CSVCELLMAKERBUILDERIMPL_H
