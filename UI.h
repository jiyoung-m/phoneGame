#ifndef DEF_UI_H //ìÒèdincludeñhé~

#define DEF_UI_H


class UI
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Finalize();


	void DrawScore(int score, int scoreMax);
	int scoreMax;

	int white;


	int life;
	bool lifeCnt;


private:
};

inline int& Score(int s = 0);
inline int& Life(int l = 0);


#endif 