#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Timer.h"
#include "../Game/Stage.h"

bool Initialize()
{
	if (false == InitializeRenderer())
	{
		return false;
	}

	InitializeTimer();

	LoadStage(STAGE_01);

	return true;
}

void processInput()
{
	//Ű �Է��� �޴� �Լ�
	UpdateInput();
}

void update()
{
	//Ű �Է��� �޾� ���� �����ϴ� ��������
	UpdateStage();
}

void render()
{
	//�Է¹����� ����ϴ� �Լ�
	RenderMap();
}

int32_t Run()
{
	while (true)
	{
		UpdateTimer();
		processInput();
		update();
		render();
	}

	return 0;
}