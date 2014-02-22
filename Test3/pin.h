#ifndef C_PIN_H
#define C_PIN_H
#pragma once

#include <hge.h>
#include <hgesprite.h>
#include <hgevector.h>

class Pin
{
public:
	Pin();
	~Pin();
	hgeRect getBounding();
	bool update();
	void render();
	void setVelocity(hgeVector velocity);
	hgeVector getVelocity();
	void setPosition(hgeVector position);
	hgeVector getPosition();

private:
	static HGE*		hge;
	hgeVector		position;
	hgeVector		velocity;
	HTEXTURE		texture;
	hgeSprite*		p_sprite;
	hgeRect			bounding;

};

#endif