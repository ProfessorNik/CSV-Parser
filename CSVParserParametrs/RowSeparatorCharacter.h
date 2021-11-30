//
// Created by nikol on 30.11.2021.
//

#ifndef LAB_4_ROWSEPARATORCHARACTER_H
#define LAB_4_ROWSEPARATORCHARACTER_H


class RowSeparatorCharacter {
public:
    explicit RowSeparatorCharacter(char sep = '\n') : sep(sep) { }

    void setSeparator(char value) { this->sep = value; }
    [[nodiscard]] bool isSeparator(char value) const { return sep == value; }


private:
    char sep{};
};


#endif //LAB_4_ROWSEPARATORCHARACTER_H
