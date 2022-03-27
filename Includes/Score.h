#ifndef _SCORE_H_
#define _SCORE_H_

#include "Sprite.h"
#include <string>
#include <deque>

class Score {
	int counter;
	int positionShow;
	const BackBuffer* pBackBuffer;
	std::deque<Sprite*>digits;

public:
	Score(const BackBuffer* Buffer, int tr);
	virtual ~Score();
	void setScore(int i) { counter = i; }
	void Draw();
	void constructScore();
};


#endif // !__SCORE_H__
