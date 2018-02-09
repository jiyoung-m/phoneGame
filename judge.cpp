#include "DxLib.h"
#include "judge.h"
#include "Player.h"
#include "UI.h"

// ���̃t�@�C�����ł����g���Ȃ��O���[�o���ϐ�


Player player;

// ������������
void Judge::Initialize() {
	see = true;
	limit_time = rand() % 100 + 30;
	delay = rand() % 20 + 10;
	count_time = 0;
	lifeCnt = false;


	white = GetColor(255, 0, 255);

	//UI
	mob = LoadGraph("image/mob.png");
	eye = LoadGraph("image/eye.png");
	bg = LoadGraph("image/bg.png");
	mobEye_w = 100;
	eye_w = 20;
	eye_x = 0.f;

	pic_okay = LoadGraph("image/okay.png");
	pic_notOkay = LoadGraph("image/notOkay.png");
	pic_pass = LoadGraph("image/pass.png");
}

// �������v�Z����
void Judge::Update() {

	++count_time;
	see = Judge_See();

	Judge_State(see);
	Eye_Move();

}

// �`�悷��
void Judge::Draw() {
	DrawGraph(0, 0, bg, TRUE); //BackGround
	//UI - Eye
	DrawGraph(200, 0, mob, TRUE);
	DrawGraphF(200 + mobEye_w + eye_x - eye_w, 0 + (mobEye_w / 2) - eye_w / 2.f, eye, TRUE);

	DrawFormatString(0, 0, white, "count: %d / limit: %d / delay: %d", count_time, limit_time, delay);
	DrawFormatString(0, 150, white, "score: %d�_, life: %d / %d", Score(),Life(),state);

	if (state == okay)
	{
		DrawGraph(402, 47, pic_okay, TRUE);
	}
	else if (state == notOkay)
	{
		DrawGraph(304, 0, pic_notOkay, TRUE);
	}
	else
	{
		DrawGraph(351, 7, pic_pass, TRUE);
	}
}

// �I������������
void Judge::Finalize() {
}

bool Judge::Judge_See()
{
	if (count_time >= limit_time - delay || count_time <= delay)		//�����Ă���
	{
		if (count_time >= (limit_time + 50) && state != notOkay) //�f�B���C(50)�㏉����
		{
			Init_Time();
		}
		return true;
	}

	else								//�����ĂȂ�
	{
		return false;
	}
}

void Judge::Init_Time()
{
	limit_time = rand() % 100 + 30; //300+60
	delay = rand() % 20 + 10;
	count_time = 0;
}

void Judge::Eye_Move()
{
	if (count_time >= limit_time)		//�ډB���p�@�����ĂȂ�
	{
		eye_x = 0;
	}
	else								//�ډB���p�@�����Ă�
	{
		eye_x -= 80.f / limit_time;
	}
}

void Judge::Judge_State(bool see)
{
	if (see)
	{
		if (player.Concent())	//�����Ă�&&�W������
		{
			state = okay;
			lifeCnt = false;
		}
		else					//�����Ă�&&�W�����Ȃ�
		{
			if (lifeCnt == false)
			{
				--Life();
				lifeCnt = true;
			}
			--Score(); ////�e�X�g�p�@��ŏ����I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I�I
			state = notOkay;
		}
	}
	else					
	{
		state = pass;
		lifeCnt = false;
		if (!player.Concent())	//�����ĂĂȂ�&&�W�����Ȃ�
		{
			++Score();
		}						//�����ĂȂ�&&�W������
	}
}
