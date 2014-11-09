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

class View : public cocos2d::extension::ScrollView
{
public:
	OVERRIDE bool init();
	//���ڷ� ���� ����� �Ǵ� ���̾ �����ÿ�
	void		  initView(cocos2d::Layer* scrollingLayer);
	//���ڷ� ���� �÷��̾� ��ġ���� �����ÿ�
	void		  setViewPort(cocos2d::Point pivotPoint);

	CREATE_FUNC(View);
private:
	cocos2d::extension::ScrollView* m_Scroll;
};

END_NS_AT
