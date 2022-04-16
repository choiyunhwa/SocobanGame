#include "stdafx.h"
#include "Player.h"
#include "Box.h"
#include "../Framework/Input.h"

//전체 맵사이즈, 이동할 위치, movedir(키 방향(박스 움직일때 쓰임)), 이전위치, 박스의 목표치
bool PlayerMovemet(char s_map[][MAP_SIZE], SPos pos, char movedir, char* s_prevObject, int32_t* s_boxOnGoalCount)
{
    //위치가 벽을 만났을 경우 움직이지 않음
    if (s_map[pos.posY][pos.posX] == MAPTYPE_WALL)
    {
        return false;
    }
    else if (s_map[pos.posY][pos.posX] == MAPTYPE_BOX)
    {
        SPos tagetPos;
        tagetPos.posX = pos.posX;
        tagetPos.posY = pos.posY;

        switch (movedir)
        {
        case KEYCODE_W:
            tagetPos.posY--;
            break;
        case KEYCODE_S:
            tagetPos.posY++;
            break;
        case KEYCODE_A:
            tagetPos.posX--;
            break;
        case KEYCODE_D:
            tagetPos.posX++;
            break;
        }
        //tagetPos 박스가 움직일 위치
        if (BoxMovement(s_map, tagetPos, movedir, &s_boxOnGoalCount) == false)
        {
            return false;
        }
        else
        {
            s_map[pos.posY][pos.posX] = MAPTYPE_PLAYER;
        }
        *s_prevObject = MAPTYPE_PATH;
    }
    else if (s_map[pos.posY][pos.posX] == MAPTYPE_BOX_ON_GOAL)
    {
        SPos tagetPos;
        tagetPos.posX = pos.posX;
        tagetPos.posY = pos.posY;

        switch (movedir)
        {
        case KEYCODE_W:
            tagetPos.posY--;
            break;
        case KEYCODE_S:
            tagetPos.posY++;
            break;
        case KEYCODE_A:
            tagetPos.posX--;
            break;
        case KEYCODE_D:
            tagetPos.posX++;
            break;
        }
        if (BoxOnGoalMovement(s_map, tagetPos, movedir, &s_boxOnGoalCount) == false)
        {
            return false;
        }
        else
        {
            s_map[pos.posY][pos.posX] = MAPTYPE_PLAYER;
        }
        *s_prevObject = MAPTYPE_GOAL;
    }
    else if (s_map[pos.posY][pos.posX] == MAPTYPE_GOAL)
    {
        *s_prevObject = MAPTYPE_GOAL;
    }
    else
    {
        *s_prevObject = MAPTYPE_PATH;
    }

    return true;
}