/************************************************************************/
/*
	CLASS			: Component
	Author			: �迬��
	����				: ��� ������Ʈ���� �߻�Ŭ����
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: ��� ��ӹ޾Ƽ� ������ٴ� ���� ������ ��
					  ������Ʈ ������. �ƹ��͵� �ȳ־���.
*/
/************************************************************************/
#pragma once
#include "cocos2d.h"
#include "Util.h"

BEGIN_NS_AT

class Component : public cocos2d::Node
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );
	ABSTRACT void				enter() = 0;
	ABSTRACT void				exit() = 0;

	void						addComponent( Component* component );
	Component*					getComponent( int type ) ;
	void						removeComponent( Component* remComponent );
	void						removeAllComponent();
	int							getType()const;
	void						setParent( Component* parent );
	Component*					getParent()const;

protected:
	int							m_Type;
	Component*					m_Parent;
};

END_NS_AT