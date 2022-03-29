#ifndef _ENEMY_H_
#define _ENEMY_H_

#include "Main.h"
#include "Sprite.h"
#include "Bullet.h"
#include "SpriteManipulation.h"
#include <deque>

class Enemy : public SpriteManipulation
{


public:
	// constructors and destructor
		//enemy shooting
	std::deque<Bullet*>	bullets;

	Enemy(const BackBuffer* pBackBuffer, int x, float dt);
	virtual ~Enemy();

	void			Update(float dt);
	void			Draw();
	void			Shoot(const BackBuffer* pBackBuffer);
	void			deleteBullet(int i);
};

#endif // !_ENEMY_H_
