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
	
	if (m_pSprite->mPosition.y < 0|| m_pSprite->mPosition.y >600|| m_pSprite->mPosition.x < 0|| m_pSprite->mPosition.x >800)
		outsideScreen = true;

}

void Bullet::Draw()
{
		m_pSprite->draw();
}

void Bullet::Move(ULONG ulDirection)
{

	if (ulDirection & DIRECTION::DIR_FORWARD)
		m_pSprite->mVelocity.y -= 500;
	if (ulDirection & DIRECTION::DIR_BACKWARD)
		m_pSprite->mVelocity.y += 500;
	if (ulDirection & DIRECTION::DIR_LEFT)
		m_pSprite->mVelocity.x -= 500;
	if (ulDirection & DIRECTION::DIR_RIGHT)
		m_pSprite->mVelocity.x += 500;

}
void Bullet::ChangeDirection(ULONG ulDirection, const BackBuffer* pBackBuffer)
{
	Vec2 retainedPosition = m_pSprite->mPosition;
	Vec2 retainedVelocity = m_pSprite->mVelocity;
	if (ulDirection & DIRECTION::DIR_FORWARD)
		m_pSprite = new Sprite("data/Bullet.bmp", RGB(0xff, 0x00, 0xff));
	if (ulDirection & DIRECTION::DIR_BACKWARD)
		m_pSprite = new Sprite("data/BulletS.bmp", RGB(0xff, 0x00, 0xff));
	if (ulDirection & DIRECTION::DIR_LEFT)
		m_pSprite = new Sprite("data/BulletW.bmp", RGB(0xff, 0x00, 0xff));
	if (ulDirection & DIRECTION::DIR_RIGHT)
		m_pSprite = new Sprite("data/BulletE.bmp", RGB(0xff, 0x00, 0xff));

	m_pSprite->mPosition = retainedPosition;
	m_pSprite->mVelocity = retainedVelocity;
	m_pSprite->setBackBuffer(pBackBuffer);
}

