#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Judge.h"
#include "UI.h"

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK);
	SetGraphMode(800, 600, 32);
	Judge judge;
	Player player;
	UI ui;

	judge.Initialize();
	player.Initialize();
	ui.Initialize();
	
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		Keyboard_Update();
		
		judge.Update();
		player.Update();
		ui.Update();

		player.Draw();
		judge.Draw();
		ui.Draw();
	}
	judge.Finalize();
	player.Finalize();
	ui.Finalize();

    DxLib_End();    // DXƒ‰ƒCƒuƒ‰ƒŠI—¹ˆ—
    return 0;
}