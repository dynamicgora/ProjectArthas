/************************************************************************/
/*
CLASS			: IdleState
Author			: �輺��
����				: �⺻ State�� ��Ÿ�� (�Ƹ� ���ִ»���)
���� ��������		: 2014-10-31
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/

#include "StateComponent.h"
#include "cocos2d.h"

BEGIN_NS_AT

class IdleState : public StateComponent
{
	OVERRIDE bool init();
	OVERRIDE void enter();
	OVERRIDE void exit();
	OVERRIDE void update(int dTime);
};

END_NS_AT