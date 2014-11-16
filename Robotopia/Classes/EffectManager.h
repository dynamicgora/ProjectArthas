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
class RoomLayer;

class EffectManager
{
public:
	EffectManager();
	~EffectManager();

	bool	init();
	void    createEffect(EffectType effectType,RoomLayer* layer, 
						 cocos2d::Point point, int playTime);



private:
	void	removeEffectCallBack(cocos2d::Ref* sender);

};




