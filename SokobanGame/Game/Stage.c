#include "stdafx.h"
#include "Stage.h"
#include "Player.h"
#include "../Framework/input.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0;
static int32_t s_boxOnGoalCount = 0;
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;
static EStageLevel s_currentLevel = 0;

bool parseMapType(int i, int j, char mapType)
{
	if (mapType == '\n' || mapType == '\0')
	{
		return false;
	}

	s_map[i][j] = mapType;

	switch (mapType)
	{
	case MAPTYPE_PLAYER:
		s_playerX = j;
		s_playerY = i;
		break;
	case MAPTYPE_GOAL:
		s_goalCount++;
		break;
	case MAPTYPE_BOX_ON_GOAL:
		s_goalCount++;
		s_boxOnGoalCount++;
		break;
	}
}

void clearStage()
{
	memset(s_map, ' ', sizeof(s_map));
	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
	s_goalCount = 0;
	s_boxOnGoalCount = 0;
	s_playerX = 0;
	s_playerY = 0;
}

void LoadStage(EStageLevel level)
{
	assert(STAGE_01 <= level && level < STAGE_MAX);
	s_currentLevel = level;

	static char path[MAX_PATH] = { 0 };
	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", (int32_t)level);


	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	clearStage();


	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j = 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (false == parseMapType(i, j, ch))
			{
				break;
			}
		}

		if (feof(fp))
		{
			break;
		}
	}

	fclose(fp);
}

//플레이어 움직이기 
void PlayerMove(int x, int y)
{
	s_map[s_playerY][s_playerX] = MAPTYPE_PATH;
	s_playerX += x;
	s_playerY += y;
	s_map[s_playerY][s_playerX] = MAPTYPE_PLAYER;
}

void UpdateStage()
{
	if (GetButtonDown(KEYCODE_W))
	{
		PlayerExcoption(0, -1);
	}
	else if (GetButtonDown(KEYCODE_S))
	{
		PlayerExcoption(0, 1);
	}
	else if (GetButtonDown(KEYCODE_A))
	{
		PlayerExcoption(-1, 0);
	}
	else if (GetButtonDown(KEYCODE_D))
	{
		PlayerExcoption(1, 0);
	}
}

//플레이어 예외처리
void PlayerExcoption(int x, int y)
{
	char orginMap = s_map[s_playerY][s_playerX];
	char nextMap = s_map[s_playerY + y][s_playerX + x];
	char nextBox = s_map[s_playerY + y * 2][s_playerX + x * 2];

	//1. 플레이어가 다른 장애물을 만났을때 안움직이는 코드
	/*if (nextMap == MAPTYPE_WALL|| nextMap == MAPTYPE_GOAL|| nextMap == MAPTYPE_BOX)
	{
		return false;
	}
	PlayerMove(x, y);*/

	//2. 플레이어가 박스를 만났을때 박스가 움직임
	//왜ㅐㅐㅐ 플레이어가 박스를 씹어먹지ㅜㅜㅜ
	if (nextMap == MAPTYPE_WALL || nextMap == MAPTYPE_GOAL)
	{
		return false;
	}
	if (nextMap == MAPTYPE_BOX)
	{
		if (nextBox == MAPTYPE_PATH)
		{
			nextMap = MAPTYPE_PATH;
			nextBox = MAPTYPE_BOX;
		}

	}
	else
	{
		PlayerMove(x, y);
	}

}

const char** GetMap()
{
	return s_map;
}