#pragma once
#include "Stage.h"
#include "stdafx.h"

bool PlayerMovemet(char s_map[][MAP_SIZE], SPos pos, char movedir, char* s_prevObject, int32_t* s_boxOnGoalCount);