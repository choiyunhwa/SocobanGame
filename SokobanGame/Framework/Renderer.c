#include "stdafx.h"
#include "Renderer.h"

#define MAP_SIZE 24


static char s_map[MAP_SIZE][MAP_SIZE] //인터널로 쓰기 때문에
= { { "********"},
	{"*sokoban*"},
	{"********"} 
	};

static HANDLE s_consoleHandle; //HANDLE 재정의된 타입

bool InitializeRenderer()
{
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //콘솔핸들을 가지고 옴
	
	if (INVALID_HANDLE_VALUE == s_consoleHandle) //예외처리
	{
		return false;
	}

	/*CONSOLE_CURSOR_INFO info; // 초기화할때 바꿔주는 것. but 콘솔에 변화가 생기면 다시 초기화가 생김
	info.dwSize = 100;
	info.bVisible = false;

	if (false == SetConsoleCursorInfo(s_consoleHandle, &info)) {
		return false;
	}*/

	return true;
}

void RenderMap()
{
	const static COORD initialPos = { 0, 0 }; //콘솔 커서 포지션의 시작시점
	const static CONSOLE_CURSOR_INFO info = { 100,false }; //렌더를 할때마다 CURSOR_INFO함

	SetConsoleCursorPosition (s_consoleHandle, initialPos);
	SetConsoleCursorInfo (s_consoleHandle, &info);

	for (int i = 0; i < MAP_SIZE; ++i)
	{
		puts(s_map[i]); //1차원 배열은 char pointer로 퇴행이 되어 puts으로 전달할 수 있음
	}
}