//
// Created by nikol on 30.11.2021.
//

#ifndef LAB_4_SHIELDINGWATCHER_H
#define LAB_4_SHIELDINGWATCHER_H


class ShieldingWatcher {
public:
    void setShieldingCharacter(char value) { shieldingChar = value; }
    [[nodiscard]] bool isShieldingText() const;
    [[nodiscard]] bool isShieldingCharacter(char value) const;
    void pushCharacter(char value);

    explicit ShieldingWatcher(char shieldingChar = '\"');

private:
    int counter;
    char shieldingChar;
    bool shieldingText;
    bool prevCharIsShielding;
    bool curCharIsShielding;
    bool firstUsed{};

};


#endif //LAB_4_SHIELDINGWATCHER_H
