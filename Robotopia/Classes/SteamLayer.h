/************************************************************************/
/*
CLASS			: SteamLayer
Author			: �����
����			: SteamLayer�� �����ش�.
���� ��������	: 2014-11-14
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "cocos2d.h"
#include "Util.h"
#include "GameSceneUILayer.h"

BEGIN_NS_AT

class SteamLayer : public GameSceneUILayer
{
public:
	SteamLayer();
	~SteamLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(SteamLayer);

private:
	
};

END_NS_AT