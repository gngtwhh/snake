/*
��������:
    ��ȫ����ע��,������һЩϸ�ڵ��޸�,�޸��ڴ�й©��©��(δ��������)
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "snake.h"//���������еĺ�������,��Ϊ����c++�������õ�bool��
int main() {
    printMenu();//��һ�ν���ѭ��ǰ�ȳ�ʼ��һ�β˵�
    char c;
    while (1) {//������ѭ��
        gotoxy(37, 17);//��λ��������
        c = _getch();//vs2022Ҫ��getch()����Ϊ_getch()---��׼c����������getch()(?)
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