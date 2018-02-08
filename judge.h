#ifndef DEF_JUDGE_H //ìÒèdincludeñhé~

#define DEF_JUDGE_H

class Judge
{
public:

	void Initialize();

	void Update();

	void Draw();

	void Finalize();


	enum State {
		okay, 
		notOkay,
		pass
	};
	void Init_Time();
	bool Judge_See();
	void Eye_Move();
	void Judge_State(bool see);

	State state;
	bool see;
	int limit_time;
	int count_time;
	int delay;





	//UI
	int bg;			//image handle BG
	int mob;		//mobÅ@Åiå„Ç≈BGÇ∆çáê¨
	int eye;		//eye
	int pic_okay;	
	int pic_notOkay;
	int pic_pass;

	int mobEye_w;
	int eye_w;
	float eye_x;
	bool lifeCnt;

private:
	int white;
};


#endif 
