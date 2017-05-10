#include "MouseMessage.h"



MouseMessage::MouseMessage():Message(-1)
{

}


long MouseMessage::getXCoord()
{
	return pt.x;
}

long MouseMessage::getYCoord()
{
	
	return pt.y;
}

MouseMessage::MouseMessage(POINT pt, DWORD     mouseData,
	DWORD     flags,
	DWORD     time,
	ULONG_PTR dwExtraInfo):Message(0)
{
	this->pt = pt;
	this->mouseData = mouseData;
	this->flags = flags;
	this->time = time;
	this->dwExtraInfo = dwExtraInfo;
}

MouseMessage::~MouseMessage()
{
}
