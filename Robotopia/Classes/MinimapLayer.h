/************************************************************************/
/*
CLASS			: MinimapLayer
Author			: �����
����			: Minimap�� �����ְ�, MŰ�� ������ �� Ȯ�� ����� �����ش�!
���� ��������	: 2014-11-05
���� ������		:
���� ��������	:
Comment			: 
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "Util.h"
#include "GameSceneUILayer.h"

BEGIN_NS_AT

class MinimapLayer : public GameSceneUILayer
{
public:
	MinimapLayer();
	~MinimapLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	void					setUpMap();
	//�÷ξ �ٲ� ��, ��鸱 �� Ŀ�ǵ� �޾Ƽ� ȣ���ؾ� �� �Լ�
	void					showMapWin();
	void					hideMapWin();
	bool					getMapWinOn();

	CREATE_FUNC(MinimapLayer);

private:
	//Map Draw
	cocos2d::Sprite*		m_Map;
	int						m_CurrentFloor;
	std::vector<int>		m_VisitedRoom;
	cocos2d::Sprite*		drawMap(int drawScale);
	StageData				m_StageData;

	//Map Window
	cocos2d::Sprite*		m_MapWin;
	bool					m_MapWinOn;
	void					drawMapWin();

	//Minimap
	cocos2d::Sprite*		m_MiniMapFrame;	
	void					drawMiniMap();
};

END_NS_AT