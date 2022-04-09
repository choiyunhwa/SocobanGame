#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Timer.h"

bool Initialize()
{
	if (false == InitializeRenderer())
	{
		return false;
	}

	InitializeTimer();

	return true;
}

void processInput()
{
	UpdateInput(); // Ű�� ���� ���� ��ȯ�Ѵ�.
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
		SetMessage("¥��");
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
		//�Է�ó��
		processInput();

		//������Ʈ
		update();
		//������
		render();
		
	}

}