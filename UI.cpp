#include "DxLib.h"
#include "UI.h"
#include "Judge.h"


Judge judge;
Judge::State state;

void UI::Initialize() {

	score = 0;
	life = 3;
	lifeCnt = false;
	state = Judge::State::okay;

	pic_okay = LoadGraph("image/okay.png");
	pic_notOkay = LoadGraph("image/notOkay.png");
	pic_pass = LoadGraph("image/pass.png");
}

void UI:: Update() {
	state = judge.Judge_State(); //<<<<<<<<<<<<<<<<<<<<<<<?????????????????
	if (state == Judge::State::okay)
	{
		lifeCnt = false;
		++score;
	}
	else if (state == Judge::State::notOkay)
	{
		life -= 1;
		if (lifeCnt == false)
		{
			lifeCnt = true;
		}
	}
	else
	{
		lifeCnt = false;
	}
}

void UI::Draw() {

	
	if (state == Judge::State::okay)
	{
		DrawGraph(402, 47, pic_okay, TRUE);

	}
	else if (state == Judge::State::notOkay)
	{
		DrawGraph(304, 0, pic_notOkay, TRUE);

	}
	if (state == Judge::State::pass)
	{
		DrawGraph(351, 7, pic_pass, TRUE);
	}

	DrawFormatString(0, 150, white, "score: %d“_, life: %d / %d", score, life, judge.Judge_State());

	}

void UI::Finalize() 
{
}
