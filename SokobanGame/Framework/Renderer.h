#pragma once
#include <stdbool.h>

/// <summary>
/// �������� �ʱ�ȭ�Ѵ�
/// </summary>
/// <returns>�ʱ�ȭ ���� true, �ƴϸ� false </returns>

bool InitializeRenderer();

/// <summary>
/// ���� �׸���
/// </summary>�ʱ�ȭ ���� true, �ƴϸ� false </returns>

void RenderMap();

//void SetKeyMessage(int keyCode);

void SetMessage(const char message[24]);