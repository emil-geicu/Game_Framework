#include "Bullet.h"
Bullet::Bullet(const BackBuffer* pBackBuffer)
{
	//m_pSprite = new Sprite("data/planeimg.bmp", "data/planemask.bmp");
	m_pSprite = new Sprite("data/Bullet.bmp", RGB(0xff, 0x00, 0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_eSpeedState = SPEED_STOP;
	m_fTimer = 0;
}

//-----------------------------------------------------------------------------
// Name : ~CPlayer () (Destructor)
// Desc : CPlayer Class Destructor
//-----------------------------------------------------------------------------
Bullet::~Bullet()
{
	delete m_pSprite;
}
Vec2& Bullet::Position() {
	return m_pSprite->mPosition;
}
Vec2& Bullet::Velocity() {
	return m_pSprite->mVelocity;
}

void Bullet::Update(float dt)
{
	// Update sprite
	m_pSprite->update(dt);


	// Get velocity
	double v = m_pSprite->mVelocity.Magnitude();


	
}

void Bullet::Draw()
{
		m_pSprite->draw();
}

void Bullet::Move(ULONG ulDirection)
{
	m_pSprite->mVelocity.y = -40;
}

