#include "Tile.h"
#include "GameManager.h"
#include "ComponentManager.h"
#include "SpriteComponent.h"
#include "PhysicsComponent.h"



bool Arthas::Tile::init()
{
	m_BoxRect = cocos2d::Rect();
	m_SpriteType = ST_END;
	return true;
}

void Arthas::Tile::initTile( float x, float y, float width, float height )
{
	//ũ�⸦ �����ѵ�
	m_BoxRect.setRect( x, y, width, height );

	//���� ������Ʈ �߰�
	auto physics = (PhysicsComponent*) GET_COMPONENT_MANAGER()->createComponent<PhysicsComponent>();
	physics->setBody( m_BoxRect, false );
	addComponent( physics );

}

void Arthas::Tile::initTile( cocos2d::Rect rect )
{
	initTile( rect.origin.x, rect.origin.y, rect.size.width, rect.size.height );
}
