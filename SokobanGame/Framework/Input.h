#pragma once

#include <stdint.h>
#include <stdbool.h>
typedef enum KeyCode
{
	W = 'w',
	A = 'a',
	S = 's',
	D = 'd',

} EKeyCode;

/// <summary>
/// 입력 상태를 업데이트 한다
/// </summary>
void UpdateInput();

/// <summary>
///  현재 프레임에 버튼이 눌렸는지 체크한다
/// </summary>
/// <param name="keyCode"></param>
/// <return>눌렸다면 true, 아니면 false </return>
void GetButtonDown(EKeyCode keyCode);

/// <summary>
/// 현재 프레임에 버튼이 떼었는지 체크한다.
/// </summary>
/// <param name="keyCode"> 가상 기 코드</param>
/// <return>뗏다면 true, 아니면 false </return>
void GetButtonUp(EKeyCode keyCode);

/// <summary>
/// 버튼이 계속 눌렸는지 체크단다.
/// </summary>
/// <param name="keyCode"> 가상 기 코드</param>
/// <return>눌렸다면 true, 아니면 false </return>
void GetButton(EKeyCode keyCode);
