#include "Crate.h"
#include <time.h>

//randomly spawning crates
Crate::Crate(const BackBuffer* pBackBuffer, int rando)
{
    m_pSprite = new Sprite("data/crate.bmp", RGB(0xff, 0x00, 0xff));
    m_pSprite->setBackBuffer(pBackBuffer);
    m_pSprite->mPosition = Vec2(rando, sHeight() / 2);
    m_pSprite->mVelocity = Vec2(0, 50);
}

//spawning crates at specific coordinates
Crate::Crate(const BackBuffer* pBackBuffer, int x, int y)
{
    m_pSprite = new Sprite("data/crate.bmp", RGB(0xff, 0x00, 0xff));
    m_pSprite->setBackBuffer(pBackBuffer);
    m_pSprite->mPosition = Vec2(x, y);
    m_pSprite->mVelocity = Vec2(0, 50);
}

Crate::~Crate() {

    delete m_pSprite;
}

void Crate::Draw()
{
    SpriteManipulation::Draw();
}

//if leaving the bottom screen, randomly sending it back from the top
void Crate::Update(float dt, ULONG height, ULONG width) {

    SpriteManipulation::Update(dt);
    srand(time(NULL));

    if (Position().y > height)
    {
        m_pSprite->mPosition.y = m_pSprite->height() / 2;
        m_pSprite->mPosition.x = rand() % width;
    }
}