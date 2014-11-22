/************************************************************************/
/*
CLASS			: GameMenuLayer
Author			: �����
����			: Game �߿� ESC�� ������ ������ �޴�
���� ��������	: 2014-11-22
���� ������		: �����
���� ��������	:�ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "GameSceneUILayer.h"

class ButtonLayer;

class GameMenuLayer : public GameSceneUILayer
{
public:
	GameMenuLayer();
	~GameMenuLayer();

	OVERRIDE bool					init();
	OVERRIDE void					update(float dTime);

	CREATE_FUNC(GameMenuLayer);

	void							showGameMenu();
	void							hideGameMenu();

private:
	cocos2d::Sprite*				m_GameMenuBackGround;
	cocos2d::Sprite*				m_GameMenuFrame;
	std::vector<ButtonLayer*>		m_MenuItem;
	ButtonLayer*					m_Button1;

};