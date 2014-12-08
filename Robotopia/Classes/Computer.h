/************************************************************************/
/*
CLASS			: Computer
Author			: �迬��
����				: �������� ������ Computer NPC?
���� ��������	: 2014-12-08
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/
#pragma once
#include "NPC.h"
#define COMPUTER_WIDTH 50
#define COMPUTER_HEIGHT 50

class Computer : public NPC
{
public:
	virtual bool	init();
	virtual void	update(float dTime);
	virtual void	enter();
	virtual void	exit();

	CREATE_FUNC(Computer);

private:
	AllStatus				m_Info;
};

