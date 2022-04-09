#include "stdafx.h"
#include "Input.h"

static bool s_currentKeyStates[256] = { false };
static bool s_prevKeyStates[256] = { false };

<<<<<<< HEAD
bool isKeyDown(int32_t keyCode)
{
	//MSB�� Set�Ǿ����� Ȯ��
	if (0x8000 & GetAsyncKeyState(keyCode))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UpdateInput() 
{
	memcpy(s_prevKeyStates, s_currentKeyStates, sizeof(s_prevKeyStates)); //���� �Է��� Ű ���¸� pre�� ������

	//��� Ű�� ���¸� �����ϴ°� 
	for (int32_t keyCode = 0; keyCode < 256; ++keyCode) //keyCode �� �������� �ȴ������� Ȯ��
	{
		if (isKeyDown(keyCode)) 
		{
			s_currentKeyStates[keyCode] = true; // ��������
		}
		else
		{
			s_currentKeyStates[keyCode] = false; //�������ʾ�����
		}
		//MSB : ���� �ֻ��� ��Ʈ
		//LSB : ���� ������ ��Ʈ
		//��ȯ�ϴ� ũ�⿡ ���� MSB, LSB ��ġ�� �޶�����. (31�� ���� �ٽõ��)
		GetAsyncKeyState(keyCode);
	}
=======
void UpdateInput()
{

>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137
}

bool GetButtonDown(EKeyCode keyCode)
{
<<<<<<< HEAD
	if (false == s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode]) // �迭�� �ε����� �̿���
=======
	if (false == s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode])
>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool GetButtonUp(EKeyCode keyCode)
{
	if (s_prevKeyStates[keyCode] && false == s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool GetButton(EKeyCode keyCode)
{
	if (s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}
