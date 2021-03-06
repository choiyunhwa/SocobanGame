#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef enum KeyCode
{
	KEYCODE_W = 'W',
	KEYCODE_A = 'A',
	KEYCODE_S = 'S',
	KEYCODE_D = 'D',
	KEYCODE_R = 'R'
} EKeyCode;

/// <summary>
/// 입력 상태를 업데이트 한다.
/// </summary>
void UpdateInput();

/// <summary>
/// 현재 프레임에 버튼이 눌렸는지 체크한다.
/// </summary>
/// <param name="keyCode">가상 키 코드</param>
/// <return>눌렸다면 true, 아니면 false</return>
bool GetButtonDown(EKeyCode keyCode);

/// <summary>
/// 현재 프레임에 버튼이 떼었는지 체크한다.
/// </summary>
/// <param name="keyCode">가상 키 코드</param>
/// <returns>뗐다면 true, 아니면 false</returns>
bool GetButtonUp(EKeyCode keyCode);

/// <summary>
/// 버튼이 계속 눌렸는지 체크한다.
/// </summary>
/// <param name="keyCode">가상 키 코드</param>
/// <returns>눌렸다면 true, 아니면 false</returns>
bool GetButton(EKeyCode keyCode);