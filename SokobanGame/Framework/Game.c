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
	//키 입력을 받는 함수
	UpdateInput();
}

void update()
{
	//키 입력을 받아 실제 동작하는 스테이지
	UpdateStage();
}

void render()
{
	//입력받은걸 출력하는 함수
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