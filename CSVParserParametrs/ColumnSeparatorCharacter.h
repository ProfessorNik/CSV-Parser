//
// Created by nikol on 30.11.2021.
//

#ifndef LAB_4_COLUMNSEPARATORCHARACTER_H
#define LAB_4_COLUMNSEPARATORCHARACTER_H


class ColumnSeparatorCharacter {
public:
    explicit ColumnSeparatorCharacter(char sep = ',');

    void setSeparator(char value);
    [[nodiscard]] bool isSeparator(char value) const;
private:
    char sep{};
};


#endif //LAB_4_COLUMNSEPARATORCHARACTER_H
