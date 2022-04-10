#include "stdafx.h"
#include "Stage.h"


static char s_map[MAP_SIZE][MAP_SIZE];
static int32_t s_goalCount = 0; //목표 개수
static int32_t s_boxOnGoalCount = 0; //현재 맞는 개수
static int32_t s_playerX = 0; //player의 x 위치
static int32_t s_playerY = 0; //player의 y 위치

bool parseMapType(int i, int j, char mapType)
{
	switch (mapType)
	{
		//각 맵타입별로 해줘야 하는일
		s_map[i][j] = ch; // Map에 저장
	}
	//반환은 행에 다다랐을때
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

	static char path[MAX_PATH] = { 0 }; //파일 경로 MAX_PATH까지만 작성이 가능

	sprintf_s(path, sizeof(path), "Stage/Stage%02d.txt", (int32_t)level);

	FILE* fp = NULL;
	fopen_s(&fp, path, "r");
	assert(fp != NULL);

	clearStage(); //데이터를 받아오기 전 clear해줌

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		for (size_t j= 0; j < MAP_SIZE; ++j)
		{
			char ch = fgetc(fp);

			if (false == parseMapType(i,j,ch))
			{
				break; //false가 나오면 행이 끝남
			}

			if (ch == '\n')
			{
				break;
			}
		}
		if (feof(fp)) //fgetc가 끝나면 EOF를 반환하므로 EOF인 경우 끝냄
		{
			break;
		}
		//stage로 한줄 씩파일을 읽어오지만 끝에 \n이 붙어 다른것으로 대체
		//fgets(s_map[i], sizeof(s_map[i]), fp);
	}
	fclose(fp);
}

void UpdateStage()
{
	//입력에 대해서 처리를 함(wasd 업데이트)
	//게임이 클리어 됐는지 파악함
	//게임 로직

}

const char** GetMap()
{
	return  s_map;
}