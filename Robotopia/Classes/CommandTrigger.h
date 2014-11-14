/************************************************************************/
/*
	CLASS			: CommandTrigger
	Author			: �迬��
	����				: Ŀ�ǵ带��gksms xmflrj��
	���� ��������	: 2014-11-14
	���� ������		:
	���� ��������	:
	Comment			:
*/
/************************************************************************/
#pragma once
#include "Trigger.h"

BEGIN_NS_AT

class Component;

class CommandTrigger : public Trigger
{
public:
	void			initCmdTrigger(CommandType commandType, void* argv = NULL);
	virtual bool	operator ==( const Trigger& trigger );
	CommandType		getCmdType();

	CommandTrigger();
	~CommandTrigger();

public:
	CommandType		m_CommandType;
	void*			m_Argv;
};

END_NS_AT