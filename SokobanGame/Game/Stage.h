#pragma once

// ���� 
// 1. ���������� �ҷ���
// 2. �������� ���� ��Ȳ�� ����
// 3. ���������� Ŭ���� �ƴ��� ( �ڽ��� ��� ���� �� )

typedef enum MapType
{
	MAPTYPE_WALL = '#',
	MAPTYPE_PLAYER = 'P',
	MAPTYPE_BOX = 'a',
	MAPTYPE_GOAL = 'O',
	MAPTYPE_BOX_ON_GOAL = '@',
	MAPTYPE_PATH = ' '
} EMapType;

typedef enum StageLevel1
{
	STAGE_01 = 1,
	STAGE_MAX
} EStageLevel;

///<summary>
///�������� �ε��Ѵ�.
/// </summary>
void LoadStage(EStageLevel level);

/// <summary>
/// ���������� ������Ʈ�Ѵ�.
/// </summary>
void UpdateStage();

///<summary>
///���� ��ȯ�Ѵ�.
/// </summary>
const char** GetMap();