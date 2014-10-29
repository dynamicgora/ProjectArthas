/************************************************************************/
/*
	CLASS			: Component
	Author			: �迬��
	����				: ��� ������Ʈ���� �߻�Ŭ����
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: ��� ��ӹ޾Ƽ� ������ٴ� ���� ������ ��, 
					  update�� ��� �ڽĵ鿡�� ���� �ʴ� ������Ʈ�� ��� ������Ʈ �������̵��� ��,
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
	ABSTRACT void				enter() {};
	ABSTRACT void				exit() {};

	void						addComponent( Component* component );
	Component*					getComponent( int type );
	void						removeComponent( Component* remComponent );
	void						removeAllComponent();
	int							getType() {return m_Type; }
	void						setParent(Component* parent) {m_Parent = parent;}
	Component*					getParnet() {return m_Parent; }

protected:
	int							m_Type;
	Component*					m_Parent;
};

END_NS_AT