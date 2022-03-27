#ifndef _BONUSLIVES_H_
#define _BONUSLIVES_H_
#include "SpriteManipulation.h"

class BonusLives : public SpriteManipulation {


public:
    BonusLives(const BackBuffer* pBackBuffer, int rando);
    BonusLives(const BackBuffer* pBackBuffer, int x, int y);
    virtual ~BonusLives();

    void            Update(float dt, ULONG height, ULONG width);
    void            Draw();

};
#endif
