/************************************************************************/
/*
CLASS			: TrivialTrigger
Author			: �迬��
����				: �׳� ���� �Է��ؼ� ������ Ʈ���� ���� �� �ְ� ��.
���� ��������	: 2014-11-12
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/
#pragma once
#include "Trigger.h"

BEGIN_NS_AT

class TrivialTrigger : public Trigger
{
public:
	void					initTrigger(int signifier);
	virtual bool			operator ==( const Trigger& trigger );
	int						getSignifier();

	TrivialTrigger();

private:
	int	m_Signifier;
};

END_NS_AT