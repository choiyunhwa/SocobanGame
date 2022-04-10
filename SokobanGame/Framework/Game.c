#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Timer.h"
#include "Game/Stage.h"

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
	//UpdateInput(); // 키의 상태 값을 반환한다.
	UpdateStage();
}

void update()
{
	/*static float elapsedTime = 0.0f;
	static bool canShowMessage = false;

	elapsedTime += GetDeltaTime();

	if (elapsedTime > 0.5f)
	{
		elapsedTime = 0.0f;
		canShowMessage = !canShowMessage;
	}
	if (canShowMessage)
	{
		SetMessage("짜잔");
	}*/
}

void render()
{
	RenderMap();
}

int32_t Run()
{

	while (true)
	{
		UpdateTimer();
		//입력처리
		processInput();

		//업데이트
		update();
		//렌더링
		render();
		
	}

}