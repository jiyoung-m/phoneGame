#ifndef DEF_PLAYER_H //ìÒèdincludeñhé~

#define DEF_PLAYER_H

class Player
{
public:
	void Initialize();

	void Update();

	void Draw();

	void Finalize();


	bool Concent();

	bool concentrate;
	int pic_concent;
	int pic_phone;

private:
	int white;
};
#endif 
