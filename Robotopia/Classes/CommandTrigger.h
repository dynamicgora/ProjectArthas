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



class BaseComponent;

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

