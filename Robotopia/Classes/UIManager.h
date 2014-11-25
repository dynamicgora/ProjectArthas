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
	///# �Ʒ��� ������ ��� �����ε�.. �� �ʱ�ȭ ����? ���߿� init()���� �ʱ�ȭ �ϴ��� �� ���� ����Ʈ�� ���� �ٶ�. �׷��� ������ init���� �׾����� �Ŀ� �׾����� �Ǵ��� ��
	TitleSceneUILayer*		m_TitleUI;
	LoadingSceneUILayer*	m_LoadingUI;
	GameSceneUILayer*		m_GameUI;
};


