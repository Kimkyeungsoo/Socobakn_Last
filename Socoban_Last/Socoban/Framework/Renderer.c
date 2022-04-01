#include "stdafx.h"
#include "Renderer.h"

#define MAP_SIZE 24

static char s_map[MAP_SIZE][MAP_SIZE];

static HANDLE s_consoleHandle;

void clear()
{
	memset(s_map, ' ', sizeof(s_map));

	for (size_t i = 0; i < MAP_SIZE; ++i)
	{
		s_map[i][MAP_SIZE - 1] = '\0';
	}
}

bool InitializeRenderer()
{
	s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE == s_consoleHandle)
	{
		return false;
	}

	return true;
}

void RenderMap()
{
	// 콘솔에서 map을 찍을 위치 설정
	const static COORD initialPos = { 0,0 };
	// 커서 사이즈
	//info.dwSize = 100;
	// 숨길 것 인지 표출 할 것 인지
	//info.bVisible = false;
	const static CONSOLE_CURSOR_INFO info = { 100,false };
	// 콘솔 커서 포지션을 옮긴후
	SetConsoleCursorPosition(s_consoleHandle, initialPos);
	// 커서를 숨긴후에
	SetConsoleCursorInfo(s_consoleHandle, &info);
	// 맵을 출력
	for (size_t i = 0; i < MAP_SIZE; i++)
	{
		puts(s_map[i]);
	}
	// 출력 후 현재 프레임을 지움 
	memset(s_map, ' ', sizeof(s_map));

	clear();
}

void SetKeyMessage(int32_t keyCode)
{
	sprintf_s(s_map[0], sizeof(s_map[0]), "%c키가 눌림", keyCode);
}