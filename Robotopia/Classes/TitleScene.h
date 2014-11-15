/************************************************************************/
/*
	CLASS			: TitleScene
	Author			: �迬��
	����				: Ÿ��Ʋ ȭ���� ��� ���̾���� ��� ��
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: �׳� �Ͳٸ� ¥��.
*/
/************************************************************************/
#pragma once
#include "cocos2d.h"
#include "Util.h"

BEGIN_NS_AT

class TitleScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene*	createScene();
	OVERRIDE bool			init();
	void					menuCallback( Ref* sender );
	CREATE_FUNC( TitleScene );
private:
	bool					m_IsStarted;
};

END_NS_AT