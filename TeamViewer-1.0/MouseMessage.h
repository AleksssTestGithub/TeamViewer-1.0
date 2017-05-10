#pragma once
#include "Message.h"
#include <Windows.h>
class MouseMessage :
	public Message
{
private:
	MouseMessage();
	POINT     pt;
	DWORD     mouseData;
	DWORD     flags;
	DWORD     time;
	ULONG_PTR dwExtraInfo;
public:
	long getXCoord();
	long getYCoord();
	MouseMessage(POINT pt, DWORD     mouseData,
	DWORD     flags,
	DWORD     time,
	ULONG_PTR dwExtraInfo);
	~MouseMessage();
};

