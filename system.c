//�����̨��صĺ���
//���ƹ��λ��,��ǰ��ӡ��ɫ,����������
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "snake.h"

//system
//ʹ��ANSI�ն˿�����������


//��Ϸ��ÿ�ε���gotoxyʱ�Ĳ������Ǹ�����Ϸ�˵��ַ�λ��/��ǰ�������ô��ݹ�����
void gotoxy(int x, int y) {
    COORD c;
    static HANDLE h;
    h = GetStdHandle(STD_OUTPUT_HANDLE);//�ӱ�׼�豸��ȡ���
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(h, c);
}

int keyboard(int pre) {//���������ж�
    char c;
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
    if ((pre == 1 && n == 3) || (pre == 2 && n == 4) || (pre == 3 && n == 1) ||
        (pre == 4 && n == 2))
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