#include "stdafx.h"
#include "Input.h"

static bool s_currentKeyStates[256] = { false };
static bool s_prevKeyStates[256] = { false };

<<<<<<< HEAD
bool isKeyDown(int32_t keyCode)
{
	//MSB가 Set되었는지 확인
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
	memcpy(s_prevKeyStates, s_currentKeyStates, sizeof(s_prevKeyStates)); //현재 입력한 키 상태를 pre로 복사함

	//모든 키의 상태를 저장하는것 
	for (int32_t keyCode = 0; keyCode < 256; ++keyCode) //keyCode 를 눌렀는지 안눌렀는지 확인
	{
		if (isKeyDown(keyCode)) 
		{
			s_currentKeyStates[keyCode] = true; // 눌렸을때
		}
		else
		{
			s_currentKeyStates[keyCode] = false; //눌리지않았을때
		}
		//MSB : 가장 최상위 비트
		//LSB : 가장 최하위 비트
		//반환하는 크기에 따라 MSB, LSB 위치가 달라진다. (31분 강의 다시듣기)
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
	if (false == s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode]) // 배열의 인덱스를 이용함
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
