/************************************************************************/
/*
CLASS			: MouseComponent
Author			: �����
����			: ���콺 Ŀ�ǵ�
���� ��������	: 2014-11-04
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/
#pragma once
#include "CommandComponent.h"
#include "cocos2d.h"


class MouseCommand : public CommandComponent
{
public:

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	CREATE_FUNC(MouseCommand);

protected:

};

