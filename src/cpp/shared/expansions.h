#include <map>
#include "combat\army.h"

class stackExtra {
    public:
        std::map<army*, std::map<std::string, int>> abilityCounter;
        std::map<army*, std::map<std::string, bool>> abilityNowAnimating;
};

class combatExtra {
    public:
        stackExtra stack;
};

class ironfistExtra {
    public:
        combatExtra combat;
};