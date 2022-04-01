#include "stdafx.h"
#include "Input.h"

// 키가 눌렸다면 true, 뗐으면 false
// 현재 프레임의 키 상태
static bool s_currentKeyStates[256] = { false };
// 이전 프레임의 키 상태
static bool s_prevKeyStates[256] = { false };

bool isKeyDown(int32_t keyCode)
{
	// 1000 0000 0000 0000
	if (0x8000 & GetAsyncKeyState(keyCode))
	{
		return true;
	}
	else
	{
		return false;
	}
}

void UpdateInput()
{
	memcpy(s_prevKeyStates, s_currentKeyStates, sizeof(s_prevKeyStates));

	for (int32_t keyCode = 0; keyCode < 256; keyCode++)
	{
		if (isKeyDown(keyCode))
		{
			s_currentKeyStates[keyCode] = true;
		}
		else
		{
			s_currentKeyStates[keyCode] = false;
		}
		// GetAsyncKeyState(keyCode);  반환값 = short
		// 3 가지 상태값 반환
		// 0x8000 => 0b 1000 0000 0000 0000 => 눌린 상태
		// 0x8001 => 0b 1000 0000 0000 0001 => 계속 눌린 상태
		// 0x0001 => 사이엔 눌렸는데 지금은 뗌
		// 0x0000 => 아예 안 눌림
		// 1. 현재 키가 눌렸는지 => MSB(Most Significant bit)가 set(=1)
		// 2 .현재 키가 안눌렸는지 => LSB(least Significant bit) = reset(=0)
		// 3. GetAsyncKeyState() ---- GetAsyncKeyState()
		//                         ^ 요 사이에 눌렸는지		
	}
}

bool GetButtonDown(EKeyCode keyCode)
{
	if (false == s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GetButtonUp(EKeyCode keyCode)
{
	if (s_prevKeyStates[keyCode] && false == s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool GetButton(EKeyCode keyCode)
{
	if (s_prevKeyStates[keyCode] && s_currentKeyStates[keyCode])
	{
		return true;
	}
	else
	{
		return false;
	}
}