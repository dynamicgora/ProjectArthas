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

BEGIN_NS_AT

class SeizeFireTrigger : public Trigger
{
public:
	void					initTrigger(int signifier);
	virtual bool			operator ==( const Trigger& trigger );

	SeizeFireTrigger();

private:
};

END_NS_AT