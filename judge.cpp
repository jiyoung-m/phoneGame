#include "DxLib.h"
#include "judge.h"
#include "Player.h"
#include "UI.h"

// ���̃t�@�C�����ł����g���Ȃ��O���[�o���ϐ�


Player player;

// ������������
void Judge::Initialize() {
	see = true;
	limit_time = rand() % 200 + 60;
	count_time = 0;


	white = GetColor(255, 0, 255);

	//UI
	mob = LoadGraph("image/mob.png");
	eye = LoadGraph("image/eye.png");
	bg = LoadGraph("image/bg.png");
	mobEye_w = 100;
	eye_w = 20;
	eye_x = 0.f;

}

// �������v�Z����
void Judge::Update() {

	++count_time;
	see = Judge_See();

	Judge_State();
	Eye_Move();

}

// �`�悷��
void Judge::Draw() {
	DrawGraph(0, 0, bg, TRUE); //BackGround
	//UI - Eye
	DrawGraph(200, 0, mob, TRUE);
	DrawGraphF(200 + mobEye_w + eye_x - eye_w, 0 + (mobEye_w / 2) - eye_w / 2.f, eye, TRUE);

	DrawFormatString(0, 0, white, "%d / %d", count_time, limit_time);
	DrawFormatString(0, 150, white, "score: %d�_, %d, %d", Score(),Judge_State(), see);
}

// �I������������
void Judge::Finalize() {
}

bool Judge::Judge_See()
{
	if (count_time >= limit_time)		//����
	{
		if (count_time >= (limit_time + 50)) //�f�B���C(50)�㏉����
		{
			Init_Time();
		}
		return true;
	}

	else								//���Ȃ�
	{
		return false;
	}
}

void Judge::Init_Time()
{
	limit_time = rand() % 200 + 60; //300+60
	count_time = 0;
}

void Judge::Eye_Move()
{
	if (!see)
	{
		eye_x -= 80.f / limit_time;
	}
	else
	{
		eye_x = 0;
	}
}

enum Judge::State Judge::Judge_State()
{
	if (see)
	{
		if (player.Concent())	//���Ă���&&�W������
		{
			state = okay;
		}
		else					//���Ă���&&�W�����Ȃ�
		{
			state = notOkay;
		}
	}
	if (!see)					
	{
		state = pass;
		if (!player.Concent())	//���ĂȂ�&&�W�����Ȃ�
		{
			Score(1);
		}						//���ĂȂ�&&�W������
	}
	return state;
}
