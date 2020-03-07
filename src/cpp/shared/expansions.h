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

class campaignExtra {
  public:
    struct partialHeroData {
      char primarySkills[NUM_PRIMARY_SKILLS];
      char skillIndex[14];
      char secondarySkillLevel[14];
      int numSecSkillsKnown;
      char artifacts[14];
      char scrollSpell[14];
      char spellsLearned[NUM_SPELLS];
      armyGroup army;
      int experience;
    };
    std::map<int, partialHeroData> savedHeroData;
};

class ironfistExtra {
    public:
        combatExtra combat;
        campaignExtra campaign;
};

extern ironfistExtra gIronfistExtra;