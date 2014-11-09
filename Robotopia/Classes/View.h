/************************************************************************/
/*
CLASS			: View
Author			: �輺��
����				: 
���� ��������		: 2014-11-09
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/

#pragma once

#include "Util.h"

BEGIN_NS_AT

class View
{
public:

	void initView(cocos2d::Layer* scrollingLayer);
	void setViewPort(cocos2d::Point pivotPoint);

private:
	cocos2d::extension::ScrollView* m_Scroll;
};

END_NS_AT
