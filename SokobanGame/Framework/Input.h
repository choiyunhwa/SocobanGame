#pragma once

#include <stdint.h>
#include <stdbool.h>
typedef enum KeyCode
{
	KEYCODE_W = 'W', //1byte이기 때문에 인덱스로 사용
	KEYCODE_A = 'A',
	KEYCODE_S = 'S',
	KEYCODE_D = 'D'

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
bool GetButtonDown(EKeyCode keyCode);

/// <summary>
/// 현재 프레임에 버튼이 떼었는지 체크한다.
/// </summary>
/// <param name="keyCode"> 가상 기 코드</param>
/// <return>뗏다면 true, 아니면 false </return>
bool GetButtonUp(EKeyCode keyCode);

/// <summary>
/// 버튼이 계속 눌렸는지 체크단다.
/// </summary>
/// <param name="keyCode"> 가상 기 코드</param>
/// <return>눌렸다면 true, 아니면 false </return>
bool GetButton(EKeyCode keyCode);