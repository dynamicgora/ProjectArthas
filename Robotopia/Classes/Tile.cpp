#include "Tile.h"
#include "ComponentManager.h"
#include "SpriteComponent.h"

bool Arthas::Tile::init()
{
	auto spriteComp = SpriteComponent::create();
	addComponent( spriteComp );
	spriteComp->enter(); //���߿� �ٲ�ߵȴ�

	

	return true;
}

void Arthas::Tile::update()
{

}

void Arthas::Tile::enter()
{

}

void Arthas::Tile::exit()
{

}

void Arthas::Tile::setRect( float x, float y, float width, float height )
{
	m_BoxRect.setRect( x, y, width, height );
}
