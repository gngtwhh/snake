//�����̨��صĺ���
//���ƹ��λ��,��ǰ��ӡ��ɫ,����������
#include <stdio.h>
#include <windows.h>
#include <conio.h>

//system
//ʹ��ANSI�ն˿�����������,���ô�ӡ��ɫ,8λ��ɫ
void setBackColor(int back) {
    printf("\033[48;5;%dm", back);
}

void setForeColor(int fore) {
    printf("\033[38;5;%dm", fore);
}

//���ô�ӡ��ɫ
void resetColor() {
    printf("\033[0m");
}

//��Ϸ��ÿ�ε���gotoxyʱ�Ĳ������Ǹ�����Ϸ�˵��ַ�λ��/��ǰ�������ô��ݹ�����
//ʹ��ANSI�ն˿�����������
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y + 1, x + 1); // ע��x��y��˳��
    // ���������������Ǵ�0��ʼ��,������̨�������Ǵ�1��ʼ��
}

void clearWindow() {
    printf("\033[2J");
}

int keyboard(int pre) {//���������ж�
    int c;
    int n = pre;
    if (_kbhit()) {//����Ƿ��м�������
        c = _getch();//�����,�����һ�ζ�ȡ
        if (c == 'w' || c == 'W')
            n = 1;
        else if (c == 'a' || c == 'A')
            n = 2;
        else if (c == 's' || c == 'S')
            n = 3;
        else if (c == 'd' || c == 'D')
            n = 4;
        else if (c == ' ')
            n = 5;
    }
    rewind(stdin);//fflush(stdin); ˢ�»�����,��VS2015֮����������(����ɹ�����Ч��)
    // if ((pre == 1 && n == 3) || (pre == 2 && n == 4) || (pre == 3 && n == 1) ||
    //     (pre == 4 && n == 2))
    if (!((pre + n) & 1))
        return pre;//�������Ҫ����180��ת��,��ת��ʧ��,����Ȼ����ԭ���ķ���ǰ��
    return n;//�ɹ�ת��,������һ��ǰ���ķ���
}

int getWindowSizeX() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.X;
}

int getWindowSizeY() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.dwSize.Y;
}

int min_between(int a, int b) {
    return a < b ? a : b;
}