#include <hge.h>
#include <hgesprite.h>
#include <hgevector.h>
#include "ball.h"
#include "pin.h"

HGE*    hge = NULL;
Ball* ball = NULL;
Pin* pin = NULL;
bool mouseReleased = false;
bool mousePressed = false;
bool ballReleased = false;
const float wdif = 3.0;//Ball wdif times heavier than pin


bool FrameFunc()
{
	bool lmouse = hge->Input_GetKeyState(HGEK_LBUTTON);
	if (lmouse)
	{
		hgeVector pos;
		hge->Input_GetMousePos(&pos.x, &pos.y);
		ball->setPosition(pos);
		mousePressed = true;
	}
	else if (mousePressed == true){
		mouseReleased = true;
	}
	
	if (ballReleased == false && lmouse == false && mousePressed == true && mouseReleased == true)
	{
		hgeVector currentpos;
		hge->Input_GetMousePos(&currentpos.x, &currentpos.y);
		hgeVector lastpos = ball->getPosition();
		hgeVector velocity = currentpos - lastpos;
		ball->setVelocity(velocity);
		ballReleased = true;
	}
	// collision
	if (ball->getBounding().Intersect(&pin->getBounding()))
	{
		// pin moves velocity ball , ball moves wdif times slower
		hgeVector velball;
		velball = ball->getVelocity();
		pin->setVelocity(velball);
		ball->setVelocity(velball / wdif);
		
	}
	ball->update();
	pin->update();
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	return false;
}

bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	ball->render();
	pin->render();
	hge->Gfx_EndScene();
	return false;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	hge = hgeCreate(HGE_VERSION);
	hge->System_SetState(HGE_FRAMEFUNC, FrameFunc);
	hge->System_SetState(HGE_RENDERFUNC, RenderFunc);
	hge->System_SetState(HGE_WINDOWED, true);
	hge->System_SetState(HGE_USESOUND, false);
	hge->System_SetState(HGE_FPS, HGEFPS_VSYNC);
	hge->System_SetState(HGE_TITLE, "Spaceshooter Tutorial");

	if (hge->System_Initiate())
	{
		ball = new Ball();
		pin = new Pin();
		pin->setPosition(hgeVector(700, 300));
		hge->System_Start();
		delete ball;
		delete pin;
	}
	else
	{
		MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}

	hge->System_Shutdown();
	hge->Release();

	return 0;
}