#pragma once

#include <stdint.h>
#include <stdbool.h>
typedef enum KeyCode
{
<<<<<<< HEAD
	KEYCODE_W = 'W', //1byte�̱� ������ �ε����� ���
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
/// �Է� ���¸� ������Ʈ �Ѵ�
/// </summary>
void UpdateInput();

/// <summary>
///  ���� �����ӿ� ��ư�� ���ȴ��� üũ�Ѵ�
/// </summary>
/// <param name="keyCode"></param>
/// <return>���ȴٸ� true, �ƴϸ� false </return>
<<<<<<< HEAD
bool GetButtonDown(EKeyCode keyCode);
=======
void GetButtonDown(EKeyCode keyCode);
>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode"> ���� �� �ڵ�</param>
/// <return>�´ٸ� true, �ƴϸ� false </return>
<<<<<<< HEAD
bool GetButtonUp(EKeyCode keyCode);
=======
void GetButtonUp(EKeyCode keyCode);
>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137

/// <summary>
/// ��ư�� ��� ���ȴ��� üũ�ܴ�.
/// </summary>
/// <param name="keyCode"> ���� �� �ڵ�</param>
/// <return>���ȴٸ� true, �ƴϸ� false </return>
<<<<<<< HEAD
bool GetButton(EKeyCode keyCode);
=======
void GetButton(EKeyCode keyCode);
>>>>>>> 3661dc3f939b9193fbdaacf619802dc4901c6137
