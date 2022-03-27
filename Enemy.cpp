#include "Enemy.h"

Enemy::Enemy(const BackBuffer* pBackBuffer, int x, float dt)
{
	m_pSprite = new Sprite("data/PlaneImgAndMaskSouth.bmp", RGB(0xff, 0x00, 0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_pSprite->mPosition = Vec2(x, m_pSprite->height() / 2);
	m_pSprite->mVelocity = Vec2(50, 0);
}

Enemy::~Enemy()
{
	while (!bullets.empty())
	{
		delete bullets.front();
		bullets.erase(bullets.begin());
	}
}

void Enemy::Update(float dt, ULONG height, ULONG width)
{
	SpriteManipulation::Update(dt);

	if (Position().x > width)
	{
		m_pSprite->mPosition.x = m_pSprite->width() / 2;
	}


	for (unsigned int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update(dt);
		if (bullets[i]->outsideScreen==true)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			i--;
		}
	}
}

void Enemy::Draw()
{
	SpriteManipulation::Draw();

	for (unsigned int i = 0; i < bullets.size(); i++)
		bullets[i]->Draw();
}

void Enemy::Shoot(const BackBuffer* pBackBuffer)
{
	bullets.push_front(new Bullet(pBackBuffer));
	bullets.front()->Position().x = m_pSprite->mPosition.x;
	bullets.front()->Position().y = m_pSprite->mPosition.y + 80;
	bullets.front()->Move(Bullet::DIR_BACKWARD);
}

void Enemy::deleteBullet(int i)
{
	delete bullets[i];
	bullets.erase(bullets.begin() + i);
}
