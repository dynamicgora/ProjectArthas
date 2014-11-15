/************************************************************************/
/*
CLASS			: MapWindowLayer
Author			: �����
����			: MŰ�� ������ �� ���� �����ش�!
���� ��������	: 2014-11-14
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "MapLayer.h"

BEGIN_NS_AT

class MapWindowLayer : public MapLayer
{
public:
	MapWindowLayer();
	~MapWindowLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(MapWindowLayer);

	void					showMapWIn();
	void					hideMapWin();

private:

	float					FitToWin();

};
END_NS_AT
