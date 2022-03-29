#include "Enemy.h"

Enemy::Enemy(const BackBuffer* pBackBuffer, int x, float dt)
{
	m_pSprite = new Sprite("data/enemy.bmp", RGB(0xff, 0x00, 0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_pSprite->mPosition.x = x;
	m_pSprite->mPosition.y = 100;
	m_pSprite->mVelocity.x = 100;
	m_pSprite->mVelocity.y = 0;
}

Enemy::~Enemy()
{
	while (!bullets.empty())
	{
		delete bullets.front();
		bullets.erase(bullets.begin());
	}
}

void Enemy::Update(float dt)
{
	SpriteManipulation::Update(dt);


	for (int i = 0; i < bullets.size(); i++)
	{
		bullets[i]->Update(dt);
		if (bullets[i]->outsideScreen==true)
		{
			delete bullets[i];
			bullets.erase(bullets.begin() + i);
			i--;
		}
	}

	if (Position().x > 800)
	{
		m_pSprite->mPosition.x = 100;
	}
	if (Position().x < 0)
	{
		m_pSprite->mPosition.x = 700;
	}

	int i = rand() % 2;
	if(i==0)
		m_pSprite->mVelocity.x = rand() % 300;
	else
		m_pSprite->mVelocity.x = (-1)*rand() % 300;

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
	m_pSprite->mVelocity.x = rand() % 300;
}

void Enemy::deleteBullet(int i)
{
	delete bullets[i];
	bullets.erase(bullets.begin() + i);
}
