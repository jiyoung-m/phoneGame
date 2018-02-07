#ifndef DEF_UI_H //ìÒèdincludeñhé~

#define DEF_UI_H


class UI
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Finalize();



	int white;


	int score;
	int life;
	bool lifeCnt;

	int pic_okay ;
	int pic_notOkay ;
	int pic_pass ;

private:
};



#endif 