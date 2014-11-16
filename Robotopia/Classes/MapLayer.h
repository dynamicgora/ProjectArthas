/************************************************************************/
/*
CLASS			: MapLayer
Author			: �����
����			: MapData�� �޾ƿͼ� ���� �׸��� �Լ��� �����ϴ� �� ���� Ŭ����,
Minimap�� MapWindow�� ������ �ִ�.
���� ��������	: 2014-11-14
���� ������		:
���� ��������	:
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "GameSceneUILayer.h"


class MinimapLayer;
class MapWindowLayer;

class MapLayer : public GameSceneUILayer
{
public:
	MapLayer();
	~MapLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(MapLayer);

	void					setUpMap(); //�÷ξ �ٲ� ��, ��鸱 �� Ŀ�ǵ� �޾Ƽ� ȣ���ؾ� �� �Լ�

	void					showMapWin();
	void					hideMapWin();

protected:
	//Draw Map
	StageData				m_StageData;
	int						m_ModuleSize;
	cocos2d::DrawNode*		m_MapPaper;
	
	cocos2d::DrawNode*		drawMap(int margin, int drawScale);

private:
	MinimapLayer*			m_Minimap;
	MapWindowLayer*			m_MapWindow;

	int						m_CurrentFloor;
	std::vector<int>		m_VisitedRoom;

	//members for drawing map
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
};
