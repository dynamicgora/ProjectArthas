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

BEGIN_NS_AT

class View
{
	// standardPoint�� �������� �Ǵ� ���� �Ѱܶ�, anchorPoint(0~1)
	static void setViewPort(cocos2d::Layer* layer, cocos2d::Point standardPoint, cocos2d::Point anchorPoint);

	// Scene �߿� ���ϴ� ��ġ�� Width Height�� �ѱ�� �׷��� �ѱ� ��ġ�� �߽����� �߶� ũ�⸸ŭ�� 
	//�׸��� ������ â�� ������ �����
	static void setViewPortWithHighlight(cocos2d::Layer* layer, cocos2d::Rect standardRect);

	//�並 ���������� �߽����� ������
	static void setViewPortShake(cocos2d::Layer* layer, cocos2d::Point standardPoint, cocos2d::Point anchorPoint);
};

END_NS_AT