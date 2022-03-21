#ifndef __CRATE_H__
#define __CRATE_H__
#include "SpriteManipulation.h"

class Crate : public SpriteManipulation {


public:
    Crate(const BackBuffer* pBackBuffer, int rando);
    Crate(const BackBuffer* pBackBuffer, int x, int y);
    virtual ~Crate();

    void            Update(float dt, ULONG height, ULONG width);
    void            Draw();

};
#endif // !__CRATE_H_
