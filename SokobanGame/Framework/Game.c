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
	UpdateInput(); // Ű�� ���� ���� ��ȯ�Ѵ�.
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
		//�Է�ó��
		processInput();

		//������Ʈ
		update();
		//������
		render();
	}

}