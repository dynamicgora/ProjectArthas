/************************************************************************/
/*
CLASS			: AICommand
Author			: �輺��
����				: ���͵鿡 ��Ȳ�� ���� Ʈ���Ÿ� ���� AIĿ�ǵ���� �߻�Ŭ����
���� ��������		: 2014-11-16
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/
#pragma once
#include "CommandComponent.h"



class AICommand : public CommandComponent
{
public:

	OVERRIDE bool				init();
	OVERRIDE void				update(float dTime);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	CREATE_FUNC(AICommand);

protected:

};

