//
// Created by nikol on 30.11.2021.
//

#ifndef LAB_4_COLUMNSEPARATORCHARACTER_H
#define LAB_4_COLUMNSEPARATORCHARACTER_H


class ColumnSeparatorCharacter {
public:
    ColumnSeparatorCharacter() { sep = ','; }
    explicit ColumnSeparatorCharacter(char sep) : sep(sep) {}

    void setSeparator(char value) { this->sep = value; };
    [[nodiscard]] bool isSeparator(char value) const { return value == sep; };
private:
    char sep{};
};


#endif //LAB_4_COLUMNSEPARATORCHARACTER_H
