// Author: WAHAHA
// Update: 2024-02-20
// Overview: A pure console simple snake game,
//     based on ANSI terminal control code drawing

#include <stdio.h>
#include <conio.h>
#include "snake.h"//���������еĺ�������,��Ϊ����c++�������õ�bool��

int main() {
    printMenu();//��һ�ν���ѭ��ǰ�ȳ�ʼ��һ�β˵�
    int c;
    while (1) {//������ѭ��
        gotoxy(37, 17);//��λ��������
        c = _getch(); // �޻�������
        if (c == '1') {
            initGame();//��Ϸ���ݳ�ʼ��
            start();//��ʽ��ʼһ����Ϸ
            destoryGameData();//�����Ϸ����,�ͷſռ�
            clearWindow();//��Ϸ��������
            printMenu();//���´�ӡ�˵�
        } else if (c == '2') {
            setForeColor(107);//����ɫ���ûذ�ɫ
            gotoxy(0, 18);
            printf("��Ϸ����!\n");
            break;//����ѭ��,������Ϸ
        } else wrongInput();//����Ƿ�,��ӡ������Ϣ
    }
    return 0;
}