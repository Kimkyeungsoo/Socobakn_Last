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
	// Game Loop ��� ���ӿ� �ִ�
	// �÷��̾��� �Է��� �ϵ����� �и���Ų��.
	// https://gameprogrammingpatterns.com/game-loop.html

	// Game Loop�� ��ü�� Frame�̶�� �θ���.
	while (true)
	{
		UpdateTimer();
		// �Է� ó��
		processInput();
		// ������Ʈ
		update();
		// ������
		render();
	}

	return 0;
}