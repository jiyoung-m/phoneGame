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
	void Judge_Time();
	void Eye_Move();
	enum State Judge_State();

	State state;
	bool see;
	int limit_time;
	int count_time;

	int test = 0;







	//UI
	int mob;		//handle
	int eye;
	int bg;

	int mobEye_w;
	int eye_w;
	float eye_x;

private:
	int white;
};


#endif 
