#ifndef C_BALL_H
#define C_BALL_H
#pragma once

#include <hge.h>
#include <hgesprite.h>
#include <hgevector.h>


class Ball
{
public:
	Ball();
	~Ball();

	bool update();
	void render();
	void setVelocity(hgeVector velocity);
	void setPosition(hgeVector position);
	hgeVector getPosition();
	

private:
	static HGE*		hge;
	hgeVector		position;
	hgeVector		velocity;
	HTEXTURE		texture;
	hgeSprite*		p_sprite;

};

#endif