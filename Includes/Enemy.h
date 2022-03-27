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

	void			Update(float dt, ULONG height, ULONG width);
	void			Draw();
	void			Shoot(const BackBuffer* pBackBuffer);

	unsigned int	NoOfBullets() { return bullets.size(); }
	Bullet* getBullet(int i) { return bullets[i]; }
	void			deleteBullet(int i);
};

#endif // !_ENEMY_H_
