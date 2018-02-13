#ifndef DEF_JUDGE_H //二重include防止

#define DEF_JUDGE_H

class Judge
{
public:

	void Initialize();

	void Update();

	void Draw();

	void Finalize();


	enum State {				//吹き出しの画像を描くための変数
		okay, 
		notOkay,
		pass
	};
	void Init_Time();			//時間や状態をリセットする関数
	bool Judge_See();			//捕まえたかどうかを返す関数、見られてないときはスコアも上がる。
	void Trick_See();			//うそ画像を描くための関数
	void Eye_Move();			//目隠し用の目玉画像を描くための関数

	State state;
	bool capture;				//捕まえているか・ないか
	int count_time;				//毎フレーム1ずつ上がる、現時間
	int limit_time;				//目隠し用の制限時間、実際は　limit_time - delay　が本当の制限時間
	int delay;					//もっと緊張感を与えるための隠れている変数
	int catch_time;				//捕まえた時、一定時間後にリセットするための変数
	bool lifeCnt;





	//UI
	int mob;		//mob　（後でBGと合成
	int eye;		//eye
	int pic_okay;	
	int pic_notOkay;
	int pic_pass;
	int pic_phone;

	int mobEye_w;
	int eye_w;
	float eye_x;

private:
	int white;
};


#endif 
