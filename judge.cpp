#include "DxLib.h"
#include "judge.h"
#include "Player.h"
#include "UI.h"

// このファイル内でしか使えないグローバル変数


Player player;

// 初期化をする
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

// 動きを計算する
void Judge::Update() {

	++count_time;
	see = Judge_See();

	Judge_State();
	Eye_Move();

}

// 描画する
void Judge::Draw() {
	DrawGraph(0, 0, bg, TRUE); //BackGround
	//UI - Eye
	DrawGraph(200, 0, mob, TRUE);
	DrawGraphF(200 + mobEye_w + eye_x - eye_w, 0 + (mobEye_w / 2) - eye_w / 2.f, eye, TRUE);

	DrawFormatString(0, 0, white, "%d / %d", count_time, limit_time);
	DrawFormatString(0, 150, white, "score: %d点, %d, %d", Score(),Judge_State(), see);
}

// 終了処理をする
void Judge::Finalize() {
}

bool Judge::Judge_See()
{
	if (count_time >= limit_time)		//見る
	{
		if (count_time >= (limit_time + 50)) //ディレイ(50)後初期化
		{
			Init_Time();
		}
		return true;
	}

	else								//見ない
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
		if (player.Concent())	//見ている&&集中する
		{
			state = okay;
		}
		else					//見ている&&集中しない
		{
			state = notOkay;
		}
	}
	if (!see)					
	{
		state = pass;
		if (!player.Concent())	//見てない&&集中しない
		{
			Score(1);
		}						//見てない&&集中する
	}
	return state;
}
