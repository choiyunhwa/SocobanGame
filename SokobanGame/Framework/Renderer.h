#pragma once
#include <stdbool.h>

/// <summary>
/// 렌더러를 초기화한다
/// </summary>
/// <returns>초기화 성공 true, 아니면 false </returns>

bool InitializeRenderer();

/// <summary>
/// 맵을 그린다
/// </summary>초기화 성공 true, 아니면 false </returns>

void RenderMap();

//void SetKeyMessage(int keyCode);

void SetMessage(const char message[24]);