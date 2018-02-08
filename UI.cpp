#include "DxLib.h"
#include "UI.h"
#include "Judge.h"



void UI::Initialize() {
	Score() = 0;
	scoreMax = 600;
	Life() = 3;
	lifeCnt = false;

}

void UI:: Update() {
}

void UI::Draw() {
	DrawScore(Score(), scoreMax);
	if (Score() >= scoreMax) {
		Score() = scoreMax;
	}
	

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

int& Life(int l)
{
	static int life;

	life += l;
	return life;
}

