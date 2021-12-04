//
// Created by nikol on 30.11.2021.
//

#include "ColumnSeparatorCharacter.h"

ColumnSeparatorCharacter::ColumnSeparatorCharacter(char sep) : sep(sep) {}

void ColumnSeparatorCharacter::setSeparator(char value) {
    this->sep = value;
}

bool ColumnSeparatorCharacter::isSeparator(char value) const {
    return value == sep;
}
