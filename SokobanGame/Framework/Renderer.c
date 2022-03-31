#include "stdafx.h"
#include "Renderer.h"

#define MAP_SIZE 24


static char s_map[MAP_SIZE][MAP_SIZE] //���ͳη� ���� ������
= { { "********"},
	{"*sokoban*"},
	{"********"} 
	};

static HANDLE s_consoleHandle; //HANDLE �����ǵ� Ÿ��

bool InitializeRenderer()
{
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE); //�ܼ��ڵ��� ������ ��
	
	if (INVALID_HANDLE_VALUE == s_consoleHandle) //����ó��
	{
		return false;
	}

	/*CONSOLE_CURSOR_INFO info; // �ʱ�ȭ�Ҷ� �ٲ��ִ� ��. but �ֿܼ� ��ȭ�� ����� �ٽ� �ʱ�ȭ�� ����
	info.dwSize = 100;
	info.bVisible = false;

	if (false == SetConsoleCursorInfo(s_consoleHandle, &info)) {
		return false;
	}*/

	return true;
}

void RenderMap()
{
	const static COORD initialPos = { 0, 0 }; //�ܼ� Ŀ�� �������� ���۽���
	const static CONSOLE_CURSOR_INFO info = { 100,false }; //������ �Ҷ����� CURSOR_INFO��

	SetConsoleCursorPosition (s_consoleHandle, initialPos);
	SetConsoleCursorInfo (s_consoleHandle, &info);

	for (int i = 0; i < MAP_SIZE; ++i)
	{
		puts(s_map[i]); //1���� �迭�� char pointer�� ������ �Ǿ� puts���� ������ �� ����
	}
}