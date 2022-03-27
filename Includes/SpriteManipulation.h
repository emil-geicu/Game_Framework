#ifndef _SPRITEMANIPULATION_H_
#define _SPRITEMANIPULATION_H_

#include "Sprite.h"

class SpriteManipulation
{
protected:
	Sprite* m_pSprite;
	float m_fTimer;

	SpriteManipulation();
	
public:
	Vec2& Position() { return m_pSprite->mPosition; }
	Vec2& Velocity() { return m_pSprite->mVelocity; }
	int spriteHeight() { return m_pSprite->height(); }
	int spriteWidth() { return m_pSprite->width(); }
	void Update(float dt);
	void Draw();

};
#endif // !_SPRITEMANIPULATION_H_
