#pragma once
#include <Windows.h>
class Register
{
private:
	static LRESULT __stdcall LowLevelMouseProc(
		_In_ int    nCode,
		_In_ WPARAM wParam,
		_In_ LPARAM lParam
	);
	HHOOK mainHook;
	HHOOK getHook();
	void setHook(HHOOK);

	static int eventCounter;
	static void PushMessage(MSLLHOOKSTRUCT*);

public:
	Register();
	~Register();
};

