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
	enum State Judge_State();

	State state;
	bool see;
	int limit_time;
	int count_time;





	//UI
	int mob;		//image handle
	int eye;
	int bg;

	int mobEye_w;
	int eye_w;
	float eye_x;

private:
	int white;
};


#endif 
