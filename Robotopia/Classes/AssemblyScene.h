/************************************************************************/
/*
CLASS			: AssemblyScene
Author			: �����
����			: AssemblyScene�� �����ش�.
���� ��������	: 2014-11-28
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "cocos2d.h"

class UILayer;
class AssemblyScene : public cocos2d::Scene
{
public:
	static cocos2d::Scene*	createScene();
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(AssemblyScene);

private:
	bool					m_IsStarted = false;
	UILayer*				m_UILayer = nullptr;
};