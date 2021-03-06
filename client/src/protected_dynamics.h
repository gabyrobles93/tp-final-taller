#ifndef __PROTECTED_DYNAMIC_MAP_H__
#define __PROTECTED_DYNAMIC_MAP_H__

#include "yaml.h"
#include <queue>

class ProtectedDynamics {
    private:
        std::queue<YAML::Node> models;
        YAML::Node dynamics;
    public:
        ProtectedDynamics(YAML::Node &);
        void addModel(YAML::Node &);
        YAML::Node getWorms(void);
        YAML::Node getProjectiles(void);
        YAML::Node getGameStatus(void);
        YAML::Node getTeamInventory(size_t);
        int getTurnTimeLeft(void);
        size_t getWormProtagonicId(void);
        bool popModel(void);
        bool finishedMatch(void);
        bool hasGameStatus(void);
        bool teamDefeated(size_t);
        size_t getWinnerTeam(void);
        size_t getTeamTurn(void);
};

#endif