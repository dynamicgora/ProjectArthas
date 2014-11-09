/************************************************************************/
/*
CLASS			: View
Author			: �輺��
����				: �÷��̾� ��ġ�� ���� �� 
���� ��������		: 2014-11-09
���� ������		:
���� ��������		:
Comment			:
*/
/************************************************************************/

#pragma once

#include "Util.h"
#include "cocos-ext.h"
#include "cocos2d.h"

class View : public cocos2d::extension::ScrollView
{
public:
	OVERRIDE bool init();
	void		  initScroll(cocos2d::Layer* scrollingLayer);
	void		  setViewPort(cocos2d::Point pivotPoint);

	CREATE_FUNC(View);

private:
	cocos2d::extension::ScrollView* m_Scroll;
};