#include <map>
#include "combat\army.h"

class stack_expansions {
    public:
        std::map<army*, int> abilityCounter;
        std::map<army*, bool> abilityNowAnimating;
};

class combat_expansions {
    public:
        stack_expansions stack;
};

class ironfist_expansions {
    public:
        combat_expansions combat;
};