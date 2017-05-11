#pragma once
#include "Message.h"
#include <queue>

using namespace std;

class PullMessage
{
public:
	static PullMessage& getInstance();
	bool PushMessage(Message&);
	Message* PopMessage();
private:
	
	queue<Message*> pullQueue;

	PullMessage();
	~PullMessage();

	PullMessage(PullMessage const&)=delete;
	PullMessage& operator=(PullMessage const&) = delete;
};

