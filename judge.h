#ifndef DEF_JUDGE_H //��dinclude�h�~

#define DEF_JUDGE_H

class Judge
{
public:

	void Initialize();

	void Update();

	void Draw();

	void Finalize();


	enum State {				//�����o���̉摜��`�����߂̕ϐ�
		okay, 
		notOkay,
		pass
	};
	void Init_Time();			//���Ԃ��Ԃ����Z�b�g����֐�
	bool Judge_See();			//�߂܂������ǂ�����Ԃ��֐��A�����ĂȂ��Ƃ��̓X�R�A���オ��B
	void Trick_See();			//�����摜��`�����߂̊֐�
	void Eye_Move();			//�ډB���p�̖ڋʉ摜��`�����߂̊֐�

	State state;
	bool capture;				//�߂܂��Ă��邩�E�Ȃ���
	int count_time;				//���t���[��1���オ��A������
	int limit_time;				//�ډB���p�̐������ԁA���ۂ́@limit_time - delay�@���{���̐�������
	int delay;					//�����Ƌْ�����^���邽�߂̉B��Ă���ϐ�
	int catch_time;				//�߂܂������A��莞�Ԍ�Ƀ��Z�b�g���邽�߂̕ϐ�
	bool lifeCnt;





	//UI
	int mob;		//mob�@�i���BG�ƍ���
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
