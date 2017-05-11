#include "PullMessage.h"



PullMessage & PullMessage::getInstance()
{
	static PullMessage pull;
	return pull;
}

bool PullMessage::PushMessage(Message &m)
{
	pullQueue.push(&m);
	return true;
}

Message* PullMessage::PopMessage()
{
	Message* m = pullQueue.front();
	pullQueue.pop();
	return m;
}

PullMessage::PullMessage()
{
}


PullMessage::~PullMessage()
{
}
