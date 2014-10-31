/************************************************************************/
/*
CLASS			: IdleState
Author			: �輺��
����				: �⺻ State�� ��Ÿ�� (�Ƹ� ���ִ»���)
���� ��������		: 2014-10-31
���� ������		: ������
���� ��������		: 2014-10-31
Comment			: State Type �ݿ��� �ȵ��־� �̰� �ݿ��߽��ϴ�
*/
/************************************************************************/

#pragma once
#include "StateComponent.h"
#include "cocos2d.h"

BEGIN_NS_AT

class IdleState : public StateComponent
{
public:
	OVERRIDE bool init();
	OVERRIDE void enter();
	OVERRIDE void exit();
	OVERRIDE void update(float dTime);

	CREATE_FUNC(IdleState);

private:
};

END_NS_AT