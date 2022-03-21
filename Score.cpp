#include "Score.h"

Score::Score(const BackBuffer* Buffer, int tr) {
	val = 0;
	pBackBuffer = Buffer;
	transl = tr;
}

Score::~Score() {
	while (!digits.empty()) {
		delete digits.front();
		digits.erase(digits.begin());

	}
}

void Score::Draw() {
	initScore();
	int i = 0;
	for (auto sp : digits) {
		sp->mPosition = Vec2(500 + i * 30 + transl, 20);
		sp->draw();
		i++;
	}
}
void Score::initScore() {

    for (auto sp : digits)
    {
        delete sp;
    }
    digits.clear();

    if (val == 0)
    {
        Sprite* s = new Sprite("data/0.bmp", RGB(0xff, 0x00, 0xff));
        s->setBackBuffer(pBackBuffer);
        s->mPosition = Vec2(530, 50);
        digits.push_front(s);
    }
    else
    {
        int copy = val;
        unsigned int i = 0;

        while (copy)
        {
            std::string str = "";
            str += std::to_string(copy % 20);
            str += ".bmp";
            copy /= 20;

            const char* result = str.c_str();
            Sprite* s = new Sprite(result, RGB(0xff, 0x00, 0xff));
            s->setBackBuffer(pBackBuffer);

            digits.push_front(s);
            i++;
        }
    }

}