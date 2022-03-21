#include "SpriteManipulation.h"

SpriteManipulation::SpriteManipulation() {

}
void SpriteManipulation::Update(float dt) {
	m_pSprite->update(dt);
}

void SpriteManipulation::Draw()
{
	m_pSprite->draw();
}