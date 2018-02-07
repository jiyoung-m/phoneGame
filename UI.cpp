#include "DxLib.h"
#include "UI.h"
#include "Judge.h"


Judge judge;
Judge::State state;

void UI::Initialize() {
	Score() = 0;
	scoreMax = 600;
	life = 3;
	lifeCnt = false;
	state = Judge::State::okay;

	pic_okay = LoadGraph("image/okay.png");
	pic_notOkay = LoadGraph("image/notOkay.png");
	pic_pass = LoadGraph("image/pass.png");
}

void UI:: Update() {
	state = judge.Judge_State();
	if (state == Judge::State::okay)
	{
		lifeCnt = false;
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
	DrawScore(Score(), scoreMax);
	if (Score() >= scoreMax) {
		Score() = scoreMax;
	}
	
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

	DrawFormatString(0, 170, white, "score: %dì_, life: %d, %d, %d", 
		Score(), life, judge.Judge_State(), judge.count_time);

	}

void UI::Finalize() 
{
}

void UI::DrawScore(int score, int scoreMax) {
	int color = GetColor(0, 0, 0);
	DrawBox(20, 70, 20 + 50, 70 + 500, color, FALSE);        //ògÇï`âÊ
	DrawBox(20, 70 + 500 - (500 * score / scoreMax), 20 + 50, 70+500, color, TRUE);    //HPÉQÅ[ÉWÇï`âÊ
}

int& Score(int s)
{
	static int score;

	score += s;
	return score;
}

