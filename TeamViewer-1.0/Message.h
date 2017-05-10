#pragma once
class Message
{
private:
	Message();
	int type;
	void setType(int t);
public:
	int getType();
	Message(int t);
	~Message();
};

