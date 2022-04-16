#include "stdafx.h"
#include "Framework/Game.h"

void Init()
{
	system("mode con cols = 30 lines = 30 | title Sokoban"); // 콘솔 크기 지정
}

int main(void)
{
	Init();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14); //색상 변경

	if (false == Initialize())
	{
		puts("게임을 로딩하는 데 문제가 생겼습니다.");

		return 1;
	}

	return Run();
}