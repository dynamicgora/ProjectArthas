/************************************************************************/
/*
CLASS			: RenderPart
Author			: �迬��
����				: Player ������ �κ� ������ ����
���� ��������	: 2014-11-29
���� ������		:
���� ��������	:
Comment			: �κ� ������ FSM���� enter exit�����۾� �ʿ�
*/
/************************************************************************/
#pragma once
#include "SpriteComponent.h"

class RenderPart : public SpriteComponent
{
public:
	virtual bool				init();
	virtual void				update(float dTime);
	virtual void				enter();
	virtual void				exit();


	CREATE_FUNC(RenderPart);
protected:

};