#include "pch.h"
#include "Missile.h"
#include "MissileManager.h"
#include "MissilePlayerMelee.h"
#include "GameManager.h"
#include "ComponentManager.h"

bool Arthas::MissileManager::init()
{

	//�����ѹ����� �ٲ���
	m_Missiles.reserve(20);

	for (int i = 0; i < 5; ++i)
	{
		Missile* PlayerMeleeMissile = GET_COMPONENT_MANAGER()->createComponent<MissilePlayerMelee>();
		PlayerMeleeMissile->initMissile();
		m_Missiles.push_back(PlayerMeleeMissile);
	
	}

	return true;
}


Arthas::Missile* Arthas::MissileManager::getMissile(Arthas::ComponentType missileType, cocos2d::Point pos,
													Arthas::Direction attackDir, 
													float damage, cocos2d::Vec2 velocity)
{
	for (auto pMissile : m_Missiles)
	{
		if (pMissile->getType() == missileType && pMissile->isUsable())
		{
			pMissile->setAttribute(pos, attackDir, damage, velocity);
			
			return pMissile;
		}
	}

	//������� �Դٸ� �տ��� ���ǿ� �´� �̻����� �����ٴ� ���̰�
	//�̻����� ���� �����ؼ� �־���� �Ѵ�. 
	/*Missile* PlayerMeleeMissile = GET_COMPONENT_MANAGER()->createComponent<missileType>();
	m_Missiles.push_back(PlayerMeleeMissile);*/


	//��� �̷��� �ȵ����� �ϴ���
	return nullptr;
}


