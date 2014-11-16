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

BEGIN_NS_AT

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

END_NS_AT