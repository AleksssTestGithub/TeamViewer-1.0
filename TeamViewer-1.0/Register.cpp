#include "Register.h"
#include "MouseMessage.h"
#include <sstream>

int Register::eventCounter=0;

//comment

LRESULT Register::LowLevelMouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (Register::eventCounter < 5 && wParam == WM_MOUSEMOVE)
	{
		MSLLHOOKSTRUCT* points = (MSLLHOOKSTRUCT*)lParam;
		int x = points->pt.x;
		int y = points->pt.y;

#ifdef UNICODE
		typedef std::wostringstream tstringstream;
#else
		typedef std::ostringstream tstringstream;
#endif
		tstringstream stros;
		stros << x<<" "<<y;
		
		PushMessage(points);
		Register::eventCounter++;
		MessageBox(NULL, stros.str().c_str(), L"MouseCoords", MB_OK);
	}
	//TODO: remove!!!
	return LRESULT();
}

HHOOK Register::getHook()
{
	return mainHook;
}

void Register::setHook(HHOOK hook)
{
	mainHook = hook;
}

void Register::PushMessage(MSLLHOOKSTRUCT *s)
{
	MouseMessage m(s->pt, s->mouseData, s->flags, s->time, s->dwExtraInfo);
}

Register::Register()
{
	this->setHook(SetWindowsHookEx(WH_MOUSE_LL, LowLevelMouseProc, NULL, 0));
	if (!getHook())
	{
		MessageBox(NULL, L"Can't create hook!", L"Error!", MB_OK);
	}
	else
	{
		MessageBox(NULL, L"Hook was created!", L"Ok!", MB_OK);
	}
}


Register::~Register()
{
	if (getHook())
	{
		UnhookWindowsHookEx(getHook());
		MessageBox(NULL, L"Unhooked successfully!", L"Ok!", MB_OK);
	}
	else
	{
		MessageBox(NULL, L"Nothing to unhook there!", L"Error!", MB_OK);
	}
}
