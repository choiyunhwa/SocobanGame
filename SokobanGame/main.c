#include "stdafx.h" // 항상 인코딩해야함
#include "Framework/Game.h"

int main()
{
	if (false == Initialize())
	{
		puts("게임을 로딩하는데 문제가 생겼습니다.");

		return 1;

	}

	return Run();
}