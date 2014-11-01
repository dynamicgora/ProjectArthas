#include "PhysicsComponent.h"

bool Arthas::PhysicsComponent::init()
{
	if(!Component::init())
	{
		return false;
	}
	m_Body = nullptr;
	m_Type = Arthas::ComponentType::CT_PHYSICS;
	return true;
}
void Arthas::PhysicsComponent::update( float dTime )
{

}

void Arthas::PhysicsComponent::enter()
{

}

void Arthas::PhysicsComponent::exit()
{

}



cocos2d::PhysicsBody* Arthas::PhysicsComponent::getBody()
{
	return	m_Body;
}

//���� �ٵ� ���� rect(�ٵ� ��ġ�� ������), isDynamic(�����̳�?), density(���Կ� ����), Restitution(ź�� ����), Frinction(������),
//��Ʈ����ũ�� http://cafe.naver.com/cocos2dxusers/19578 ����
void Arthas::PhysicsComponent::initPhysics( cocos2d::Rect rect, bool isDynamic,
										float density /*= 0.0f */, float Restitution /*= 0.0f*/, float Friction /*= 0.0f*/,
										int ContactTestBitmask /*= 0x00000000*/, int CategoryBitmask /*= 0xffffffff*/, int CollisionBitmask /*= 0xffffffff*/ )
{
	auto material = cocos2d::PhysicsMaterial( density, Restitution, Friction );
	m_Body = cocos2d::PhysicsBody::createBox( rect.size, material );
	m_Body->setContactTestBitmask( ContactTestBitmask );
	m_Body->setCategoryBitmask( CategoryBitmask );
	m_Body->setCollisionBitmask( CollisionBitmask );
	m_Body->setTag( (int)m_Parent->getType() );
	m_Body->setDynamic( isDynamic );
	m_Parent->setPhysicsBody( m_Body );
}

