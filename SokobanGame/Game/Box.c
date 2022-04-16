#include "stdafx.h"
#include "Stage.h"
#include "Box.h"

bool BoxMovement(char s_map[][MAP_SIZE], SPos pos, char movedir, int32_t** s_boxOnGoalCount)
{
    if (s_map[pos.posY][pos.posX] == MAPTYPE_WALL || s_map[pos.posY][pos.posX] == MAPTYPE_BOX || s_map[pos.posY][pos.posX] == MAPTYPE_BOX_ON_GOAL)
    {
        return false;
    }
    else if (s_map[pos.posY][pos.posX] == MAPTYPE_GOAL)
    {
        **s_boxOnGoalCount += 1;
        s_map[pos.posY][pos.posX] = MAPTYPE_BOX_ON_GOAL;
    }
    else if (s_map[pos.posY][pos.posX] == MAPTYPE_PATH)
    {
        s_map[pos.posY][pos.posX] = MAPTYPE_BOX;
    }

    return true;
}

bool BoxOnGoalMovement(char s_map[][MAP_SIZE], SPos pos, char movedir, int32_t** s_boxOnGoalCount)
{

    if (s_map[pos.posY][pos.posX] == MAPTYPE_WALL || s_map[pos.posY][pos.posX] == MAPTYPE_BOX || s_map[pos.posY][pos.posX] == MAPTYPE_BOX_ON_GOAL)
    {
        return false;
    }
    else if (s_map[pos.posY][pos.posX] == MAPTYPE_GOAL)
    {
        s_map[pos.posY][pos.posX] = MAPTYPE_BOX_ON_GOAL;
    }
    else if (s_map[pos.posY][pos.posX] == MAPTYPE_PATH)
    {
        **s_boxOnGoalCount -= 1;
        s_map[pos.posY][pos.posX] = MAPTYPE_BOX;
    }

    return true;
}