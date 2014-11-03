/************************************************************************/
/*
CLASS			: UIManager
Author			: �����
����			: Scene�� �´� UI ��û �� �ش��ϴ� Layer ����
���� ��������	: 2014-10-31
���� ������		: �����
���� ��������	:
Comment			: 
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "cocos2d.h"

BEGIN_NS_AT

class UILayer;
class TitleSceneUILayer;
class LoadingSceneUILayer;
class GameSceneUILayer;

class UIManager
{
public:
	UIManager();
	~UIManager();

	bool					init();
	UILayer*				getUILayer(SceneType sceneType);
	
private:
	TitleSceneUILayer*		m_TitleUI;
	LoadingSceneUILayer*	m_LoadingUI;
	GameSceneUILayer*		m_GameUI;
};


END_NS_AT