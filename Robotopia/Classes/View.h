/************************************************************************/
/*
CLASS			: View
Author			: �輺��
����				: State���� �߻� Ŭ����
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
	static void initView(cocos2d::Layer* scrollingLayer);
	static void setViewPort(cocos2d::Point pivotPoint);

private:
	//static cocos2d::extension::ScrollView* m_Scroll;
};

END_NS_AT
