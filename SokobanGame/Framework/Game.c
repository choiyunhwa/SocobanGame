#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
<<<<<<< HEAD
#include "Input.h"
=======
>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137

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
	UpdateInput(); // 키의 상태 값을 반환한다.
}

void update()
{
	if (GetButton(KEYCODE_W))
	{
		SetKeyMessage(KEYCODE_W);
	}
	else if (GetButton(KEYCODE_D))
	{
		SetKeyMessage(KEYCODE_D);
	}
	else if (GetButton(KEYCODE_S))
	{
		SetKeyMessage(KEYCODE_S);
	}
	else if (GetButton(KEYCODE_A))
	{
		SetKeyMessage(KEYCODE_A);
	}
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