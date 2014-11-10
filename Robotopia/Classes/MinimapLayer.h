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
	//Draw Map
	cocos2d::DrawNode*		m_Map;
	cocos2d::DrawNode*		m_Minimap;
	StageData				m_StageData;
	int						m_ModuleSize;

	int						m_CurrentFloor;
	std::vector<int>		m_VisitedRoom;

	struct MarginSet
	{
		bool mUp;
		bool mRight;
		bool mDown;
		bool mLeft;
	};
	MarginSet				m_MarginSet;
	void					initMarginSet();
	int						getModulePlaceData(int roomCnt, int x, int y);
	void					roomBoundaryCheck(int roomCnt, int x, int y, int maxX, int maxY);
	cocos2d::DrawNode*		makeRoomRect(int width, int height, int marginSize, MarginSet margin, cocos2d::Color4B fillColor);
	cocos2d::DrawNode*		drawMap(int margin, int drawScale);

	//Map Window
	cocos2d::Sprite*		m_MapWin;
	bool					m_MapWinOn;
	
	void					drawMapWin();
	float					fitToWin();


	//Minimap
	cocos2d::Sprite*		m_MinimapFrame;
	cocos2d::Sprite*		m_MinimapMask;

	void					drawMiniMap();
};

END_NS_AT



