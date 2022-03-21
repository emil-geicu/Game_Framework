#ifndef __SCORE_H__
#define __SCORE_H_

#include "Sprite.h"
#include <string>
#include <deque>

class Score {
	int val;
	int transl;
	const BackBuffer* pBackBuffer;
	std::deque<Sprite*>digits;

public:
	Score(const BackBuffer* Buffer, int tr);
	virtual ~Score();
	void setScore(int i) { val = i; }
	void Draw();
	void initScore();
};


#endif // !__SCORE_H__
