#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"

bool Initialize()
{
	if (false == InitializeRenderer())
	{
		return false;
	}
	return true;
}

void processInput()
{

}

void update()
{

}

void render()
{
	RenderMap();
}

int32_t Run()
{
	
	while (true)
	{
		//입력처리
		processInput();

		//업데이트
		update();
		//렌더링
		render();
	}

}