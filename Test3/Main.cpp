#include <hge.h>
#include <hgesprite.h>
#include <hgevector.h>
#include "Ball.h"

HGE*    hge = NULL;
Ball* ball = NULL;
bool mouseReleased = false;
bool mousePressed = false;
bool ballReleased = false;

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

	ball->update();
	if (hge->Input_GetKeyState(HGEK_ESCAPE)) return true;
	return false;
}

bool RenderFunc()
{
	hge->Gfx_BeginScene();
	hge->Gfx_Clear(0);
	ball->render();
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
		hge->System_Start();
		delete ball;
	}
	else
	{
		MessageBox(NULL, hge->System_GetErrorMessage(), "Error", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}

	hge->System_Shutdown();
	hge->Release();

	return 0;
}