/************************************************************************/
/*
CLASS			: LabelLayer
Author			: �����
����			: Label ����
���� ��������	: 2014-11-28
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "UILayer.h"

class LabelLayer : public UILayer
{
public:
	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC (LabelLayer);

	void					setLabelProperties(LabelType labelType);
	void					setLabelRect(cocos2d::Point labelPosition, bool rectDirDown);

private:
	float					m_LabelWidth = 0.0f;
	float					m_LabelHeight = 0.0f;
	LabelType				m_LabelType = NO_LABEL;
	cocos2d::Sprite*		m_LabelFrame = nullptr;

};