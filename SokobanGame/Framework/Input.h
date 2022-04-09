#pragma once

#include <stdint.h>
#include <stdbool.h>
typedef enum KeyCode
{
	KEYCODE_W = 'W', //1byte�̱� ������ �ε����� ���
	KEYCODE_A = 'A',
	KEYCODE_S = 'S',
	KEYCODE_D = 'D'

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
bool GetButtonDown(EKeyCode keyCode);

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode"> ���� �� �ڵ�</param>
/// <return>�´ٸ� true, �ƴϸ� false </return>
bool GetButtonUp(EKeyCode keyCode);

/// <summary>
/// ��ư�� ��� ���ȴ��� üũ�ܴ�.
/// </summary>
/// <param name="keyCode"> ���� �� �ڵ�</param>
/// <return>���ȴٸ� true, �ƴϸ� false </return>
bool GetButton(EKeyCode keyCode);