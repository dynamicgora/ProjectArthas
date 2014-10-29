/************************************************************************/
/*
CLASS			: Tile
Author			: �迬��
����				: Tile���� �߻� class
���� ��������	: 2014-10-29
���� ������		:
���� ��������	:
Comment			: 
*/
/************************************************************************/
#pragma once
#include "Component.h"
#include "Util.h"

BEGIN_NS_AT

class Tile : public Component
{
public:
	OVERRIDE bool init();
	ABSTRACT void setRect( float x , float y , float width , float height );
	
protected:
	cocos2d::Rect m_BoxRect;
};

END_NS_AT