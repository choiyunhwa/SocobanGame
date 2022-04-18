#include "stdafx.h"
#include "Stage.h"
#include "../Framework/input.h"

static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0;
static int32_t s_boxOnGoalCount = 0;
static int32_t s_playerX = 0;
static int32_t s_playerY = 0;
static EStageLevel s_currentLevel = 0;
static bool Goal = false;

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
	if (level == STAGE_MAX)
	{
		//�ܼ� ȭ���� û��
		system("cls");
		puts("��������������");
		puts("��     GAME OVER        ��");
		puts("��������������");
		exit(1);
	}
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

//�÷��̾� �����̱� 
void PlayerMove(int x, int y)
{
	if (Goal == true)
	{
		s_map[s_playerY][s_playerX] = MAPTYPE_GOAL;
		Goal = false;
	}
	else
	{
		s_map[s_playerY][s_playerX] = MAPTYPE_PATH;
	}

	s_playerX += x;
	s_playerY += y;
	s_map[s_playerY][s_playerX] = MAPTYPE_PLAYER;
}

void UpdateStage()
{
	if (GetButtonDown(KEYCODE_W))
	{
		PlayerException(0, -1);
	}
	else if (GetButtonDown(KEYCODE_S))
	{
		PlayerException(0, 1);
	}
	else if (GetButtonDown(KEYCODE_A))
	{
		PlayerException(-1, 0);
	}
	else if (GetButtonDown(KEYCODE_D))
	{
		PlayerException(1, 0);
	}
	else if (GetButtonDown(KEYCODE_R))
	{
		clearStage();
		LoadStage(s_currentLevel);
	}
}

//�÷��̾� ����ó��
void PlayerException(int x, int y)
{
	char orginMap = s_map[s_playerY][s_playerX];
	char nextMap = s_map[s_playerY + y][s_playerX + x];
	char TwoNextBox = s_map[s_playerY + (y * 2)][s_playerX + (x * 2)];

	//1. �÷��̾ �ٸ� ��ֹ��� �������� �ȿ�����
	/*if (nextMap == MAPTYPE_WALL|| nextMap == MAPTYPE_GOAL|| nextMap == MAPTYPE_BOX)
	{
		return false;
	}
	PlayerMove(x, y);*/

	//2. �÷��̾ �ڽ��� �������� �ڽ��� ������
	/*if (nextMap == MAPTYPE_WALL || nextMap == MAPTYPE_GOAL)
	{
		return false;
	}
	if (nextMap == MAPTYPE_BOX)
	{
		if (nextBox == MAPTYPE_BOX)
		{
			s_map[s_playerY + y][s_playerX + x] = MAPTYPE_PLAYER;
			return;
		}
		else
		{
			s_map[s_playerY + (y * 2)][s_playerX + (x * 2)] = MAPTYPE_BOX;
		}
		PlayerMove(x, y);
	}
	else
	{
		PlayerMove(x, y);
	}*/

	//3. �ڽ� - ��/ �ڽ� - �ڽ�/ �ڽ� - ��ǥ
	//(�߰� ����)�÷��̾ ��ǥ ������ ������ ��ǥ�� �����
	if (nextMap == MAPTYPE_WALL)
	{
		return false;
	}
	else if (nextMap == MAPTYPE_BOX)
	{
		if (TwoNextBox != MAPTYPE_WALL)
		{
			if (TwoNextBox == MAPTYPE_BOX)
			{
				s_map[s_playerY + y][s_playerX + x] = MAPTYPE_BOX;
				return;
			}
			else if (TwoNextBox == MAPTYPE_GOAL)
			{
				//s_map[s_playerY + y][s_playerX + x] = MAPTYPE_PLAYER;
				s_map[s_playerY + (y * 2)][s_playerX + (x * 2)] = MAPTYPE_BOX_ON_GOAL;
				s_boxOnGoalCount++;
			}
			else if (TwoNextBox == MAPTYPE_BOX_ON_GOAL)
			{
				return false;
			}
			else
			{
				s_map[s_playerY + (y * 2)][s_playerX + (x * 2)] = MAPTYPE_BOX;
			}
			PlayerMove(x, y);
		}
	}
	else if (nextMap == MAPTYPE_BOX_ON_GOAL)
	{
		if (TwoNextBox != MAPTYPE_WALL)
		{
			if (TwoNextBox == MAPTYPE_BOX)
			{
				//s_map[s_playerY + y][s_playerX + x] = MAPTYPE_BOX;
				return false;
			}
			else if (TwoNextBox == MAPTYPE_PATH)
			{
				s_map[s_playerY][s_playerX] = MAPTYPE_PATH;
				s_map[s_playerY + y][s_playerX + x] = MAPTYPE_PLAYER;
				s_boxOnGoalCount--;
				s_map[s_playerY + (y * 2)][s_playerX + (x * 2)] = MAPTYPE_BOX;
			}
			else if (TwoNextBox == MAPTYPE_GOAL)
			{
				s_map[s_playerY][s_playerX] = MAPTYPE_PATH;
				s_map[s_playerY + y][s_playerX + x] = MAPTYPE_PLAYER;
				s_map[s_playerY + (y * 2)][s_playerX + (x * 2)] = MAPTYPE_BOX_ON_GOAL;
			}
			else
			{
				return;
			}
		}
		else
		{
			return false;
		}
	}
	else if (nextMap == MAPTYPE_GOAL)
	{
		if (TwoNextBox != MAPTYPE_WALL)
		{
			if (TwoNextBox == MAPTYPE_BOX_ON_GOAL)
			{
				s_map[s_playerY][s_playerX] = MAPTYPE_PATH;
				s_map[s_playerY + y][s_playerX + x] = MAPTYPE_PLAYER;
				s_map[s_playerY + (y * 2)][s_playerX + (x * 2)] = MAPTYPE_BOX_ON_GOAL;
			}
		}
	}
	else
	{
		PlayerMove(x, y);
	}
	if (nextMap == MAPTYPE_GOAL)
	{
		PlayerMove(x, y);
		Goal = true;
	}
	if (nextMap == MAPTYPE_BOX_ON_GOAL)
	{
		PlayerMove(x, y);
		Goal = true;
	}
	if (s_goalCount == s_boxOnGoalCount)
	{
		LoadStage(++s_currentLevel);
	}
}

const char** GetMap()
{
	return s_map;
}