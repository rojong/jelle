#include "pin.h"

HGE* Pin::hge = 0;
Pin::Pin(){
	hge = hgeCreate(HGE_VERSION);

	texture = hge->Texture_Load("Pin.jpg");
	p_sprite = new hgeSprite(texture, 0, 0, 50, 50);
	p_sprite->SetHotSpot(10, 10);
}

Pin::~Pin()
{
	hge->Texture_Free(texture);
	delete p_sprite;

	hge->Release();
}

bool Pin::update(){
	position.x += velocity.x;
	position.y += velocity.y;
	bounding.Set(position.x, position.y, position.x + 50, position.y + 50);
	return false;
}

void Pin::render(){
	p_sprite->Render(position.x, position.y);
}

void Pin::setVelocity(hgeVector vel){
	velocity = vel;
}

hgeVector Pin::getVelocity(){
	return velocity
}

void Pin::setPosition(hgeVector pos){
	position = pos;
}

hgeVector Pin::getPosition(){
	return position;
}

hgeRect Pin::getBounding()
{
	return bounding;
}