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


	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );
	OVERRIDE void				enter();
	OVERRIDE void				exit();
	void						initPhysics();
	void						initPhysics( cocos2d::Rect rect, bool isDynamic,
										 float density = 0.0f, float Restitution = 0.0f,
										 float Friction = 0.0f, int ContactTestBitmask = 0x00000000,
										 int CategoryBitmask = 0xffffffff, int CollisionBitmask = 0xffffffff );
	cocos2d::PhysicsBody*		getBody();

	CREATE_FUNC( PhysicsComponent );

protected:
	cocos2d::PhysicsBody*		m_Body;
};

END_NS_AT