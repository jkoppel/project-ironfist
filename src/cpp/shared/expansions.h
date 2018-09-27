#include <map>
#include "combat\army.h"

class stackExtra {
    public:
        std::map<army*, std::map<std::string, int>> abilityCounter;
        std::map<army*, std::map<std::string, bool>> abilityNowAnimating;
        std::map<army*, int> forceShieldHP;
};

class spellExtra {
    struct FireBombWallHex {
        int hexIdx;
        int turnsLeft;
        int currentFrame;
    };
    public:
        std::vector<FireBombWallHex> fireBombWalls;
};

class combatExtra {
    public:
        stackExtra stack;
        spellExtra spell;
};

class ironfistExtra {
    public:
        combatExtra combat;
};