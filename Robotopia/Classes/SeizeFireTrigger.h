/************************************************************************/
/*
CLASS			: SeizeFireTrigger
Author			: �迬��
����				: ���� ���� Ʈ����
���� ��������	: 2014-11-12
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/
#pragma once
#include "Trigger.h"



class SeizeFireTrigger : public Trigger
{
public:
	void					initTrigger();
	virtual bool			operator ==( const Trigger& trigger );

	SeizeFireTrigger();

private:
};

