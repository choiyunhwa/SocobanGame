#include "stdafx.h"
#include "Renderer.h"

#define MAP_SIZE 24


static char s_map[MAP_SIZE][MAP_SIZE]; //���ͳη� ���� ������
static HANDLE s_consoleHandle; //HANDLE �����ǵ� Ÿ��

void clear() // �� �������� �ְ� �������� NULL���ڸ� ��
{
	memset(s_map, ' ', sizeof(s_map));

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
}

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

	SetConsoleCursorPosition(s_consoleHandle, initialPos);
	SetConsoleCursorInfo(s_consoleHandle, &info);

	//DeltaTime ����ϱ�
	//sprintf_s(s_map[0], sizeof(s_map[0]), "Delta TIme : %.6f", GetDeltaTime());
	//sprintf_s(s_map[1], sizeof(s_map[1]), "FPS : %d", (int32_t)(1/GetDeltaTime()));

	//�ð� �帣�� ��Ȳ
	//clock_t tick = clock();
	//sprintf_s(s_map[0], sizeof(s_map[0]), "Elapsed TIme : %d", tick);

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		puts(s_map[i]); //1���� �迭�� char pointer�� ������ �Ǿ� puts���� ������ �� ����
	}

	//��� �Ŀ� ���� �������� ����
	clear();
}

void SetMessage(const char *messge)
{
	strcpy(s_map[0],MAP_SIZE, messge);
}
