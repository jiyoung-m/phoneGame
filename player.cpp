#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Judge.h"

Judge judge;


	// ‰Šú‰»‚ğ‚·‚é
void Player::Initialize() {
	concentrate = false;
	white = GetColor(0, 255, 255);

	pic_concent = LoadGraph("image/concent.png");
	pic_phone = LoadGraph("image/phone.png");
	bg = LoadGraph("image/bg.png");
}

// “®‚«‚ğŒvZ‚·‚é
void Player::Update() {
	
	concentrate = Concent();
		
}

// •`‰æ‚·‚é
void Player::Draw() {
	DrawGraph(0, 0, bg, TRUE); //BackGround
	if (Concent())
	{
		DrawFormatString(0, 50, white, "W’†");
		DrawGraph(49, 195, pic_concent, TRUE);
	}
	else
	{
		DrawFormatString(0, 50, white, "Œg‘Ñ");
		DrawGraph(16,160, pic_phone, TRUE);
	}

}

// I—¹ˆ—‚ğ‚·‚é
void Player::Finalize() {
}




bool Player::Concent()
{
	if (Keyboard_Get(KEY_INPUT_Z) > 0) 
	{
		return false;
	}
	else
	{
		return true;
	}
}