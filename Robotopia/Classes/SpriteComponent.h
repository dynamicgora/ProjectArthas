/************************************************************************/
/*
	CLASS			: SpriteComp
	Author			: �迬��
	����				: Sprite Component�� Ŭ����
	���� ��������	: 2014-10-29
	���� ������		:
	���� ��������	:
	Comment			: �߻�Ŭ������ ����� �� ��������Ʈ ���� ���� Ŭ������ ����� ������ ���� ��
*/
/************************************************************************/
#pragma once
#include "Component.h"
#include "cocos2d.h"

BEGIN_NS_AT

class SpriteComponent : public Component
{
public:
	OVERRIDE bool				init();
	OVERRIDE void				update( float dTime );
	OVERRIDE void				enter();
	OVERRIDE void				exit();

	//Sprite�� �������� ���� �з��ϸ� �Ʒ� create �����ε��� �Լ��� ���ʿ��Դϴ�.
	void						setSprite( const char* SpriteName, bool isFrameCache );
	int							getType(){return m_Type;}

	CREATE_FUNC( SpriteComponent );

protected:
	cocos2d::Sprite*			m_Sprite;
	int							m_Type;
};

END_NS_AT