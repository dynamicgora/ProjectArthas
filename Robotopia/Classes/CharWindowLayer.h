/************************************************************************/
/*
CLASS			: CharWindowLayer
Author			: �����
����			: CŰ�� ������ �� ĳ���� â�� �����ش�!
���� ��������	: 2014-11-15
���� ������		: �����
���� ��������	: �ű�
Comment			:
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "GameSceneUILayer.h"

BEGIN_NS_AT

class CharWindowLayer : public GameSceneUILayer
{
public:
	CharWindowLayer();
	~CharWindowLayer();

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(CharWindowLayer);

	void					showCharWin();
	void					hideCharWin();

private:
	cocos2d::Sprite*		m_CharWinFrame;
	cocos2d::Sprite*		m_CharWinTrigger;
};
END_NS_AT