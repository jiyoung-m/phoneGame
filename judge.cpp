#include "DxLib.h"
#include "judge.h"
#include "Player.h"
#include "UI.h"

// ���̃t�@�C�����ł����g���Ȃ��O���[�o���ϐ�


Player player;

// ������������
void Judge::Initialize() {
	capture = false;
	limit_time = rand() % 100 + 30;
	delay = rand() % 20 + 10;
	count_time = 0;
	catch_time = 0;
	lifeCnt = false;


	white = GetColor(255, 0, 255);

	//UI
	mob = LoadGraph("image/mob.png");
	eye = LoadGraph("image/eye.png");
	mobEye_w = 100;
	eye_w = 20;
	eye_x = 0.f;

	pic_okay = LoadGraph("image/okay.png");
	pic_notOkay = LoadGraph("image/notOkay.png");
	pic_pass = LoadGraph("image/pass.png");
	pic_phone = LoadGraph("image/phone2.png");
}

// �������v�Z����
void Judge::Update() {

	++count_time;
	Eye_Move();

	if (capture)
	{
		state = notOkay;
		if (catch_time <= 50)
		{
			if (lifeCnt == false)
			{
			Life(-1);
			lifeCnt = true;
			}
			++catch_time;
		}
		else
		{
			Init_Time();
		}
	}
	else
	{
		capture = Judge_See();
		Trick_See();
	}
}

// �`�悷��
void Judge::Draw() {
	//UI - Eye
	DrawGraph(200, 0, mob, TRUE);
	DrawGraphF(200 + mobEye_w + eye_x - eye_w, 0 + (mobEye_w / 2) - eye_w / 2.f, eye, TRUE);


	if (state == okay)
	{
		DrawGraph(402, 47, pic_okay, TRUE);
	}
	else if (state == notOkay)
	{
		DrawGraph(16, 160, pic_phone, TRUE);
		DrawGraph(304, 0, pic_notOkay, TRUE);
	}
	else
	{
		DrawGraph(351, 7, pic_pass, TRUE);
	}
	DrawFormatString(0, 0, white, "count: %d / limit: %d / delay: %d", count_time, limit_time, delay);
	DrawFormatString(0, 150, white, "score: %d�_, life: %d / state: %d ", Score(), Life(), state);
}

// �I������������
void Judge::Finalize() {
}

bool Judge::Judge_See()
{
	if (count_time >= (limit_time - delay) || count_time <= delay)		//�����Ă���
	{
		if (!player.Concent())
		{
			return true;
		}
		if (count_time >= (limit_time + 50)) //�f�B���C(50)�㏉����
		{
			Init_Time();
		}
	}

	else								//�����ĂȂ�
	{
		if (!player.Concent())
		{
			++Score();
		}
	}
	return false;
}

void Judge::Init_Time()
{
	limit_time = rand() % 100 + 30; 
	delay = rand() % 20 + 10;
	lifeCnt = false;
	state = pass;
	capture = false;
	catch_time = 0;
	count_time = 0;
}

void Judge::Eye_Move()
{
	if (count_time >= limit_time || state == notOkay)		//�ډB���p�@�����Ă�
	{
		eye_x = 0;
	}
	else													//�ډB���p�@�����ĂȂ�
	{
		eye_x -= 80.f / limit_time;
	}
}


void Judge::Trick_See()
{
	if (count_time >= limit_time)		//�����Ă���
	{
		state = okay;
	}

	else								//�����ĂȂ�
	{
		state = pass;
	}

}