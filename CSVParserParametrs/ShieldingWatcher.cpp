//
// Created by nikol on 30.11.2021.
//

#include "ShieldingWatcher.h"

ShieldingWatcher::ShieldingWatcher(char shieldingChar) : shieldingChar(shieldingChar){
    prevCharIsShielding = false;
    curCharIsShielding = false;
    shieldingText = false;
    counter = 0;
}

void ShieldingWatcher::pushCharacter(char value) {
    prevCharIsShielding = curCharIsShielding;
    if(value == shieldingChar) {
        if (prevCharIsShielding) {
            counter--;
            curCharIsShielding = false;
        } else {
            counter++;
            curCharIsShielding = true;
        }
    }
    else if (prevCharIsShielding){
        shieldingText = !shieldingText;
        curCharIsShielding = false;
    }else{
        curCharIsShielding = false;
    }

}

bool ShieldingWatcher::isShieldingCharacter(char value) const {
    return curCharIsShielding;
}

bool ShieldingWatcher::isShieldingText() const {
    return counter % 2;
}
