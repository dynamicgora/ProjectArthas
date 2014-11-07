/************************************************************************/
/*
	CLASS			: SimpleRoaming
	Author			: �迬��
	����				: ������ ��ġ���� �·� ��� �̵��ϴ� ������ Roaming
	���� ��������	: 2014-11-05
	���� ������		:
	���� ��������	:
	Comment			:
*/
/************************************************************************/
#pragma once
#include "Util.h"
#include "FSMComponent.h"

BEGIN_NS_AT

class SimpleRoamingFSM : public FSMComponent
{
public:
	OVERRIDE bool				init();
	void						initRoaming(Component* parent, cocos2d::Point leftPoint, cocos2d::Point rightPoint, float time);
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	CREATE_FUNC(SimpleRoamingFSM);
private:
};

END_NS_AT