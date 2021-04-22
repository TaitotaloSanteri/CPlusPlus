#pragma once
#include "Human.h"
class Child : public Human
{
public:
	Child(std::string _name, int _age) : Human(_name, _age) {}
	virtual void Info() override;
protected:
	
};

