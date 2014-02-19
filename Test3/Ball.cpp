#include "Ball.h"

HGE* Ball::hge = 0;
Ball::Ball(){
	hge = hgeCreate(HGE_VERSION);

	texture = hge->Texture_Load("Ball.jpg");
	p_sprite = new hgeSprite(texture, 0, 0, 50, 50);
	p_sprite->SetHotSpot(10, 10);
}
 
Ball::~Ball()    
{
	hge->Texture_Free(texture);
	delete p_sprite;

	hge -> Release();
}

bool Ball::update(){
	position.x += velocity.x;
	position.y += velocity.y;
	return false;
}

void Ball::render(){
	p_sprite->Render(position.x, position.y);
}

void Ball::setVelocity(hgeVector vel){
	velocity = vel;
}
void Ball::setPosition(hgeVector pos){
	position = pos;
}

hgeVector Ball::getPosition(){
	return position;
}