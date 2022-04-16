#pragma once
#include "Stage.h"
#include "stdafx.h"

bool BoxMovement(char s_map[][MAP_SIZE], SPos pos, char movedir, int32_t** s_boxOnGoalCount);

bool BoxOnGoalMovement(char s_map[][MAP_SIZE], SPos pos, char movedir, int32_t** s_boxOnGoalCount);