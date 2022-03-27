//-----------------------------------------------------------------------------
// File: CPlayer.cpp
//
// Desc: This file stores the player object class. This class performs tasks
//	   such as player movement, some minor physics as well as rendering.
//
// Original design by Adam Hoult & Gary Simmons. Modified by Mihai Popescu.
//-----------------------------------------------------------------------------

#ifndef _CPLAYER_H_
#define _CPLAYER_H_

//-----------------------------------------------------------------------------
// CPlayer Specific Includes
//-----------------------------------------------------------------------------
#include "Main.h"
#include "Sprite.h"
#include "Bullet.h"
#include "Score.h"
#include "Lives.h"
#include <deque>
#include "SpriteManipulation.h"
//-----------------------------------------------------------------------------
// Main Class Definitions
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Name : CPlayer (Class)
// Desc : Player class handles all player manipulation, update and management.
//-----------------------------------------------------------------------------
class CPlayer:public SpriteManipulation
{
public:
	//-------------------------------------------------------------------------
	// Enumerators
	//-------------------------------------------------------------------------
	enum DIRECTION 
	{ 
		DIR_FORWARD	 = 1, 
		DIR_BACKWARD	= 2, 
		DIR_LEFT		= 4, 
		DIR_RIGHT	   = 8, 
	};

	enum ESpeedStates
	{
		SPEED_START,
		SPEED_STOP
	};

	//-------------------------------------------------------------------------
	// Constructors & Destructors for This Class.
	//-------------------------------------------------------------------------
			 CPlayer(const BackBuffer *pBackBuffer,int scorePosition);
	virtual ~CPlayer();

	//-------------------------------------------------------------------------
	// Public Functions for This Class.
	//-------------------------------------------------------------------------
	void					Update( float dt );
	void					Draw();
	void					Move(ULONG ulDirection);
	Vec2&					Position();
	Vec2&					Velocity();
	void					Explode();
	bool					AdvanceExplosion();
	void					FireBullet(Bullet *b, const BackBuffer* pBackBuffer);

	void RotateLeft(const BackBuffer* pBackBuffer);

	void RotateRight(const BackBuffer* pBackBuffer);

	void Collsion(CPlayer* player2);
	void deleteLife();
	void addLife(const BackBuffer* pBackBuffer);
	
	bool isAlive() { return alive; }
	bool CurrentlyExploding() { return m_bExplosion; }
	void incrementScore(int i) { scorey += i; score->setScore(scorey); }
	void setScore(int i) { scorey = i; score->setScore(scorey); }
	int  getScore() { return scorey; }

private:
	//-------------------------------------------------------------------------
	// Private Variables for This Class.
	//-------------------------------------------------------------------------
	//Sprite*					m_pSprite;
	ESpeedStates			m_eSpeedState;
	float					m_fTimer;
	DIRECTION				planeDirection;
	bool					m_bExplosion;
	AnimatedSprite*			m_pExplosionSprite;
	int						m_iExplosionFrame;
	int scorePosition;
	int scorey;
	Score* score;
	std::deque<Lives*> lives;
	bool					alive;
};	

#endif // _CPLAYER_H_