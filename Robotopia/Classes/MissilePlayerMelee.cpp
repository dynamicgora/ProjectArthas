#include "pch.h"
#include "GameManager.h"
#include "PhysicsComponent.h"
#include "MissilePlayerMelee.h"
#include "ComponentManager.h"
#include "ObserverComponent.h"
#include "TriggerManager.h"
#include "PhysicsTrigger.h"
#include "AnimationComponent.h"
#include "DataManager.h"



void Arthas::MissilePlayerMelee::initMissile()
{
	m_IsPlayerMissile = true;
	m_IsUsable = true;
	m_IsPrevTimeCheck = true;
	m_PrevTime = 0;
	m_CurTime = 0;
	m_Duration = 0;
	
	m_Type = OT_MISSILE_PLAYER_MELEE;
	
	//duration�� �ִϸ��̼ǿ� ���� ���� ���� �� �ۿ� ���� 
	//������ �Ŵ������� ���� �;� �ҵ� 
	AnimationInfo missileAniInfo = GET_DATA_MANAGER()->getAnimationInfo(AT_MISSILE_PLAYER_MELEE);
	m_Duration = missileAniInfo.delay * missileAniInfo.frameNum;

	auto physics = GET_COMPONENT_MANAGER()->createComponent<PhysicsComponent>();
	addComponent(physics);
	//���Ͷ� �ε����� �Ǵµ� ���� ���Ϳ� ���� phyc�� ����. 
	//���� ����� �ε����� �ؾ��� 
	physics->initPhysics(cocos2d::Rect(0, 0, 65, 50), false, 0, 0, 0, PHYC_ALL, PHYC_NONE, PHYC_NONE);
	//�ϴ� ���� body ���� '�θ� �� ���ش�.' 
	physics->setEnabled(false);
	
	auto animation = GET_COMPONENT_MANAGER()->createComponent<AnimationCompnent>();
	addComponent(animation);
	animation->setAnimation(AT_MISSILE_PLAYER_MELEE, this, 1);

}
	
void Arthas::MissilePlayerMelee::setAttribute(cocos2d::Point pos, Direction attackDir,
											  float damage, cocos2d::Vec2 velocity, 
											  cocos2d::Point targetPos)
{
	//setAttribute�� Manager���� �θ� �� �Ѵ�.
	//�� �� ���� ��� ����
	m_Velocity = velocity;
	m_Damage = damage;
	m_AttackDir = attackDir;
	m_TargetPos = targetPos;
	setPosition(pos);
	
	//���⼭ physics�� �Ѿ߰ڴ�. 
	auto physicsCompo = (PhysicsComponent*)getComponent(CT_PHYSICS);
	physicsCompo->setEnabled(true);
	
	auto animationCompo = (AnimationCompnent*)getComponent(CT_ANIMATION);
	animationCompo->enter();

	m_IsUsable = false;
}

void Arthas::MissilePlayerMelee::update(float dTime)
{
	for (auto& component : getChildren())
	{
		component->update(dTime);
	}

	if (m_IsPrevTimeCheck)
	{
		m_IsPrevTimeCheck = false;
		m_PrevTime = GET_GAME_MANAGER()->getTime().tv_sec;
	}

	
	m_CurTime += GET_GAME_MANAGER()->getTime().tv_sec;

	if (m_CurTime - m_PrevTime >= m_Duration)
	{
		m_CurTime = 0;
		m_IsPrevTimeCheck = true;
		m_IsUsable = true;
		auto physicsCompo = (PhysicsComponent*)getComponent(CT_PHYSICS);
		physicsCompo->setEnabled(false);
		removeFromParent();
	}


}

bool Arthas::MissilePlayerMelee::init()
{
	if (!Missile::init())
	{
		return false;
	}

	return true;
}
void Arthas::MissilePlayerMelee::enter()
{
}

void Arthas::MissilePlayerMelee::exit()
{
}