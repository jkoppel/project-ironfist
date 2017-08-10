#include <map>
#include "combat\army.h"

class stackExtra {
    public:
        std::map<army*, int> abilityCounter;
        std::map<army*, bool> abilityNowAnimating;
};

class combatExtra {
    public:
        stackExtra stack;
};

class ironfistExtra {
    public:
        combatExtra combat;
};