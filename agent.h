#pragma once

#include <vector>
#include "map.h"
#include "definitions.h"

class Agent {
public:
    Agent(int startX, int startY, int numOtherAgents, Map& map);

    int updateInternalMap(Map& fullMap);
    void step(std::vector<Agent>& agents, Map& fullMap);
    void moveDirection(Direction d);
    int BFS_to_Undiscovered(int, int);
    void joinAuction();
    void leaveAuction();
    bool bid(int askingPrice, std::vector<int> agentsInAuction);
    
    int m_x = -1;
    int m_y = -1;
    int m_treasureCount;
    std::vector<int> m_likableness;

    int m_goalX = -1;
    int m_goalY = -1;

    Map m_map;
    Map& m_global_map;

    bool m_aimless = false;
    int m_collectStep = -1;
    bool m_stuck = false;
    bool m_inAuction = false;
};
