/************************************************************************/
/*
CLASS			: EquipmentStatusLayer
Author			: �輺��
����				: Equipment�� status�� �����ִ� ���̾�
���� ��������		: 2014-12-01
���� ������		: �輺��
���� ��������		: �ű�
Comment			: 
*/
/************************************************************************/

#pragma once
#include "Util.h"
#include "UILayer.h"

class EquipmentStatusLayer : public UILayer
{
public:
	EquipmentStatusLayer();
	~EquipmentStatusLayer();

	struct CurBeChosenEquipmentes
	{
		HeadList		   m_CurChosenHead = HL_START;
		ArmorList		   m_CurChosenArmor = AL_START;
		EngineList		   m_CurChosenEngine = EL_START;
		LegList			   m_CurChosenLeg = LL_START;
		MeleeList		   m_CurChosenMelee = ML_START;
		RangeList		   m_CurChosenRangeList = RL_START;
		SteamContainerList m_CurChosenSteamContainerList = SCL_START;

	};

	OVERRIDE bool			init();
	OVERRIDE void			update(float dTime);

	CREATE_FUNC(EquipmentStatusLayer);

	void					setStartEquipmentType(CurBeChosenEquipmentes equipmentList);
	//void					

private:
	CurBeChosenEquipmentes m_CurBeChosenEquipment;


};