#define bool int//��c����,��Ҫ�궨��bool����
#define false 0
#define true 1

//main nemu---���˵�
void printMenu();//��ӡ�˵�����
void initGame();//��ʼ����Ϸ�����ܿ��ƺ���
void wrongInput();//�˵�ѡ��������봦��
//void showRank();��ʾ��������,��δʵ��

//starting---������Ϸ���ݳ�ʼ������
void printBox();//��ӡ��ͼ
void initSnakeAndApple();//��ʼ���ߺ�ƻ��
void setDifficulty();//������Ϸ�Ѷ�

//game begin---��Ϸ�߼�����
void start();//��Ϸ��ѭ��(�ܿ���)
bool againstTheWall();//������Ƿ�ײǽ
bool againstSelf();//������Ƿ�ײ���Լ�
void gameover();//��Ϸ��������
void gamewin();//��Ϸʤ������
void moveSnake(int);//�ƶ���
void snakeGrowth();//�Ե�ƻ��ʱ������
bool isOverlap();//����ƻ��ʱ����Ƿ�������������������
void destoryGameData();//��ǰһ����Ϸ����ʱ�ͷſռ�

//system---ϵͳ��صĺ���
void gotoxy(int, int);//����ض�λ
void setBackColor(int back);//���ñ�����ɫ
void setForeColor(int fore);//����ǰ����ɫ
void resetColor();//���ô�ӡ��ɫ
void clearWindow();//����
int keyboard(int);//�޻����������֧��
int getWindowSizeX();//��ȡ����̨���ڿ��
int getWindowSizeY();//��ȡ����̨���ڸ߶�
int min_between(int a, int b);//�����������н�С���Ǹ�