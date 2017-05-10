#include "Message.h"



Message::Message()
{
}

void Message::setType(int t)
{
	type = t;
}

int Message::getType()
{
	return type;
}

Message::Message(int t)
{
	setType(t);
}


Message::~Message()
{
}
