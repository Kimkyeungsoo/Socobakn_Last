#include "stdafx.h"
#include "Game.h"
#include "Renderer.h"
#include "Input.h"
#include "Timer.h"

bool Initialize()
{
	if (false == InitializeRenderer())
	{
		return false;
	}

	InitializeTimer();

	return true;
}

void processInput()
{
	UpdateInput();
}

void update()
{
	
}

void render()
{
	RenderMap();
}

int32_t Run()
{
	// Game Loop 모든 게임에 있다
	// 플레이어의 입력을 하드웨어랑 분리시킨다.
	// https://gameprogrammingpatterns.com/game-loop.html

	// Game Loop의 전체를 Frame이라고 부른다.
	while (true)
	{
		UpdateTimer();
		// 입력 처리
		processInput();
		// 업데이트
		update();
		// 렌더링
		render();
	}

	return 0;
}