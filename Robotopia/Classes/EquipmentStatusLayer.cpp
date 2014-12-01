#include "pch.h"
#include "EquipmentStatusLayer.h"
#include "GameManager.h"
#include "ResourceManager.h"
#include "ButtonLayer.h"

bool EquipmentStatusLayer::init()
{
	if (!UILayer::init())
	{
		return false;
	}

	//st_start ��� �� ������� �ٲٸ� ��
	setUIProperties(GET_RESOURCE_MANAGER()->createSprite(ST_START), cocos2d::Point::ANCHOR_MIDDLE,
					cocos2d::Point::ZERO, 1.f, true, 0);


	//��ư �����
	m_EquipButton->setButtonProperties(BUTTON_ASSEMBLY, cocos2d::Point::ANCHOR_MIDDLE,
									   cocos2d::Point::ZERO, "EQUIP");
	m_UpgradeButton->setButtonProperties(BUTTON_ASSEMBLY, cocos2d::Point::ANCHOR_MIDDLE,
									   cocos2d::Point::ZERO, "UPGRADE");

	//�ݹ��Լ� ���ֿ� ���� 
//	m_ButtonConfirm->setButtonFunc(std::bind(&AssemblyUILayer::confirmAssembly, this));
	//m_ButtonCancel->setButtonFunc(std::bind(&AssemblyUILayer::toTitleScene, this));



	return true;
}

void EquipmentStatusLayer::update(float dTime)
{
	m_EquipButton->update(dTime);
	m_UpgradeButton->update(dTime);

	//getCurBeChosenEquipment�� �ؼ� ��������  
}

void EquipmentStatusLayer::setStartEquipmentType(Equipmentes equipmentList)
{
	m_CurBeInstalledEquipmentes = equipmentList;
}

