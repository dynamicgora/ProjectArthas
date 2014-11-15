/************************************************************************/
/*
	CLASS			: PhysicsComponent
	Author			: �迬��
	����				: ��������Ǵ� ������Ʈ
	���� ��������	: 2014-10-31
	���� ������		:
	���� ��������	:
	Comment			: Body�� tag�� �θ��� Ÿ��
	*/
/************************************************************************/

#pragma once
#include "Component.h"
#include "cocos2d.h"

BEGIN_NS_AT

class PhysicsComponent : public Component
{
public:
	~PhysicsComponent();

	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	void						initPhysics();
	void						initPhysics( cocos2d::Rect rect, bool isDynamic,
										 float density = 0.0f, float Restitution = 0.0f,
										 float Friction = 0.0f, int ContactTestBitmask = 0x00000000,
										 int CategoryBitmask = 0xffffffff, int CollisionBitmask = 0xffffffff );
// 	void						extendBody(cocos2d::Rect rect, float density = 0.f, float Restitution = 0.f,
// 										 float Friction = 0.f);
	void						extendBody(cocos2d::Rect rect, ComponentType type, float density /*= 0.f*/, float Restitution /*= 0.f*/, float Friction /*= 0.f*/);
	cocos2d::PhysicsBody*		getBody();
	bool						isIgnoreCollision(ComponentType otherType, Direction collisionDir);
	bool						onContactBegin(cocos2d::PhysicsContact& contact);
	void						onContactSeparate(cocos2d::PhysicsContact& contact);
	void						addIgnoreCollision(ComponentType otherType, Direction collisionDir);
	void						setEnabled(bool enable);

	CREATE_FUNC(PhysicsComponent);

protected:
	cocos2d::PhysicsBody*		m_Body;
	std::map<int, Direction>	m_IgnoreCollisions;
};

END_NS_AT