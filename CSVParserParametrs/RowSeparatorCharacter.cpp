//
// Created by nikol on 30.11.2021.
//

#include "RowSeparatorCharacter.h"

RowSeparatorCharacter::RowSeparatorCharacter(char sep) : sep(sep) { }

void RowSeparatorCharacter::setSeparator(char value) {
    this->sep = value;
}

bool RowSeparatorCharacter::isSeparator(char value) {
    return sep == value;
}

