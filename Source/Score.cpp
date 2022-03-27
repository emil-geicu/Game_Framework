#include "Score.h"

Score::Score(const BackBuffer* Buffer, int tr) {
	counter = 0;
	pBackBuffer = Buffer;
	positionShow = tr;
}

Score::~Score() {
	while (!digits.empty()) {
		delete digits.front();
		digits.erase(digits.begin());

	}
}

void Score::Draw() {
	constructScore();
	int i = 0;
	for (auto sp : digits) {
		sp->mPosition = Vec2(200 + i * 30 + positionShow+200, 45);
		sp->draw();
		i++;
	}
}
void Score::constructScore() {

    for (auto &sp : digits)
    {
        delete sp;
    }
    digits.clear();

    if (counter == 0)
    {
        Sprite* s = new Sprite("data/0.bmp", RGB(0xff, 0x00, 0xff));
        s->setBackBuffer(pBackBuffer);
        s->mPosition = Vec2(200, 50);
        digits.push_front(s);
    }
    else
    {
        int copy = counter;
        unsigned int i = 0;

        while (copy)
        {
            std::string str = "data/";
            str += std::to_string(copy % 10);
            str += ".bmp";
            copy /= 10;

            const char* result = str.c_str();
            Sprite* s = new Sprite(result, RGB(0xff, 0x00, 0xff));
            s->setBackBuffer(pBackBuffer);
            digits.push_front(s);
            i++;
        }
    }

}