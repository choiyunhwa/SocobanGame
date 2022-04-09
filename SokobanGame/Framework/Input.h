#pragma once

#include <stdint.h>
#include <stdbool.h>
typedef enum KeyCode
{
<<<<<<< HEAD
	KEYCODE_W = 'W', //1byte이기 때문에 인덱스로 사용
	KEYCODE_A = 'A',
	KEYCODE_S = 'S',
	KEYCODE_D = 'D'
=======
	W = 'w',
	A = 'a',
	S = 's',
	D = 'd',
>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137

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
<<<<<<< HEAD
bool GetButtonDown(EKeyCode keyCode);
=======
void GetButtonDown(EKeyCode keyCode);
>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137

/// <summary>
/// 현재 프레임에 버튼이 떼었는지 체크한다.
/// </summary>
/// <param name="keyCode"> 가상 기 코드</param>
/// <return>뗏다면 true, 아니면 false </return>
<<<<<<< HEAD
bool GetButtonUp(EKeyCode keyCode);
=======
void GetButtonUp(EKeyCode keyCode);
>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137

/// <summary>
/// 버튼이 계속 눌렸는지 체크단다.
/// </summary>
/// <param name="keyCode"> 가상 기 코드</param>
/// <return>눌렸다면 true, 아니면 false </return>
<<<<<<< HEAD
bool GetButton(EKeyCode keyCode);
=======
void GetButton(EKeyCode keyCode);
>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137
