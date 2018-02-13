#include "DxLib.h"
#include "Player.h"
#include "Keyboard.h"
#include "Judge.h"

Judge judge;


	// ������������
void Player::Initialize() {
	concentrate = false;
	white = GetColor(0, 255, 255);

	pic_concent = LoadGraph("image/concent.png");
	pic_phone = LoadGraph("image/phone.png");
	bg = LoadGraph("image/bg.png");
}

// �������v�Z����
void Player::Update() {
	
	concentrate = Concent();
		
}

// �`�悷��
void Player::Draw() {
	DrawGraph(0, 0, bg, TRUE); //BackGround
	if (Concent())
	{
		DrawFormatString(0, 50, white, "�W��");
		DrawGraph(49, 195, pic_concent, TRUE);
	}
	else
	{
		DrawFormatString(0, 50, white, "�g��");
		DrawGraph(16,160, pic_phone, TRUE);
	}

}

// �I������������
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