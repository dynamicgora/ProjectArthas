/************************************************************************/
/*
CLASS			: EffectManager
Author			: �輺��
����				: Effect ��û�� ������ ����
���� ��������		: 2014-10-29
���� ������		: 
���� ��������		:
Comment			: ���� � layer�� ���� ������ ���� ���� ����
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "cocos2d.h"



//�ӽ÷� roomLayer�� �޾Ҵٰ� �մϴ�.(���߿� ��Ȯ�� ������ ������ ���ؾߵ�)
class Effect;
class EffectManager
{
public:
	EffectManager();
	~EffectManager();

	bool			init();
	Effect*			createEffect(EffectType effectType, cocos2d::Point position);



private:
};




