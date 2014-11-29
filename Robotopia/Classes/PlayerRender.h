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
#include "RenderPart.h"

class PlayerRender : public BaseComponent
{
public:
	enum PartsType
	{
		PT_TOROSO,
		PT_HEAD,
		PT_ARM_LEFT,
		PT_ARM_RIGHT,
		PT_LEG_LEFT,
		PT_LEG_RIGHT,
		PT_MAX,
	};

	virtual bool				init();
	virtual void				update(float dTime);
	virtual void				enter();
	virtual void				exit();

	void						addPart(RenderPart* part, PartsType type);
	void						removePart(PartsType type);


	CREATE_FUNC(PlayerRender);

protected:
	std::vector<RenderPart*>	m_Parts;
};
