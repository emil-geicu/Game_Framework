#ifndef __LIVES_H__
#define __LIVES_H__
#include "Sprite.h"
#include "SpriteManipulation.h"

class Lives:public SpriteManipulation
{
	
public:
	Lives(const BackBuffer* BackBuffer, double x);
	virtual ~Lives(void);
	void Draw() { m_pSprite->draw(); }
	Vec2& Position() { return m_pSprite->mPosition; }
	int Height() { return m_pSprite->height(); }
	int Width() { return m_pSprite->width(); }
};
#endif // !_LIVES_H_
