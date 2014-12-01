/************************************************************************/
/*
CLASS			: PlayerRender
Author			: �迬��
����				: Player ������ ������ ����
���� ��������	: 2014-11-29
���� ������		:
���� ��������	:
Comment			: ������ ����. ���� �ٿ��� �����ϰ�.
*/
/************************************************************************/

#pragma once
#include "BaseComponent.h"
#include "Player.h"

class RenderPart;
class PlayerRenderer : public BaseComponent
{
public:
	enum PartsType
	{
		PT_ENGENE,
		PT_ARMOR,
		PT_RANGE,
		PT_MELEE,
		PT_LEG,
		PT_HEAD,
		PT_MAX,
	};

	virtual bool				init();
	virtual void				update(float dTime);
	virtual void				enter();
	virtual void				exit();

	void						changeState(Player::State state);
	void						addPart(RenderPart* part, PartsType type);
	void						removePart(PartsType type);

	CREATE_FUNC(PlayerRenderer);

protected:
	std::vector<RenderPart*>	m_Parts;
};
