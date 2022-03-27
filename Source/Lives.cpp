#include "Lives.h"

Lives::Lives(const BackBuffer* pBackBuffer, double x)
{
	m_pSprite = new Sprite("data/heart.bmp",RGB(0xff,0x00,0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_pSprite->mPosition.x = x + 10;
	m_pSprite->mPosition.y = m_pSprite->height() / 2;
}

Lives::~Lives() {
	delete m_pSprite;
}