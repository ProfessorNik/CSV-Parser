//
// Created by nikol on 30.11.2021.
//

#include "ShieldingWatcher.h"

ShieldingWatcher::ShieldingWatcher(char shieldingChar) : shieldingChar(shieldingChar){
    prevCharIsShielding = false;
    curCharIsShielding = false;
    counterShieldingCharacters = 0;
}

void ShieldingWatcher::pushCharacter(char value) {
    prevCharIsShielding = curCharIsShielding;
    if(value == shieldingChar) {
        if (prevCharIsShielding) {
            counterShieldingCharacters--;
            curCharIsShielding = false;
        } else {
            counterShieldingCharacters++;
            curCharIsShielding = true;
        }
    } else{
        curCharIsShielding = false;
    }

}

bool ShieldingWatcher::isShieldingCharacter(char value) const {
    return curCharIsShielding;
}

bool ShieldingWatcher::isShieldingText() const {
    return counterShieldingCharacters % 2;
}
