/************************************************************************/
/*
CLASS			: GameSceneUILayer
Author			: �����
����			: GameScene�� �ʿ��� UILayer
���� ��������	: 2014-10-31
���� ������		: �����
���� ��������	:
Comment			:
*/
/************************************************************************/

#pragma once
#include "GameManager.h"
#include "Util.h"
#include "UILayer.h"

BEGIN_NS_AT

class Player;
class MapLayer;
class GearLayer;
class SteamLayer;

class GameSceneUILayer : public UILayer
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(GameSceneUILayer);

protected:
	const Player*			m_Player;
	GearLayer*				m_Gear;
	SteamLayer*				m_SteamBar;
	MapLayer*				m_Map;
};

END_NS_AT