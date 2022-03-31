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
/// �Է� ���¸� ������Ʈ �Ѵ�
/// </summary>
void UpdateInput();

/// <summary>
///  ���� �����ӿ� ��ư�� ���ȴ��� üũ�Ѵ�
/// </summary>
/// <param name="keyCode"></param>
/// <return>���ȴٸ� true, �ƴϸ� false </return>
void GetButtonDown(EKeyCode keyCode);

/// <summary>
/// ���� �����ӿ� ��ư�� �������� üũ�Ѵ�.
/// </summary>
/// <param name="keyCode"> ���� �� �ڵ�</param>
/// <return>�´ٸ� true, �ƴϸ� false </return>
void GetButtonUp(EKeyCode keyCode);

/// <summary>
/// ��ư�� ��� ���ȴ��� üũ�ܴ�.
/// </summary>
/// <param name="keyCode"> ���� �� �ڵ�</param>
/// <return>���ȴٸ� true, �ƴϸ� false </return>
void GetButton(EKeyCode keyCode);
