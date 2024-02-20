#include <stdio.h>
#include <windows.h>
#include "snake.h"

//nemu
void printMenu() {
    resetColor(); // ������ɫ
    gotoxy(0,0); // ����ض�λ
    const char *logo[10] = {"   ________\n",
                            "  / ______ \\    v1.1~~~\n",
                            " / /      \\ \\                                 ___\n",
                            " | \\      |_|                                 | | \n",
                            "  \\ \\______     ___ ______       ____   ___   | | __    ______\n",
                            "   \\______ \\    | |/ ____ \\     / __ \\_/  /   | |/ /   /  ___ \\\n",
                            " _        \\ \\   | | /    \\ \\   / /  \\    /    |   /   |  /___\\ \\\n",
                            "| |        | |  |  /     | |  | |    |   |    |   \\   |  _______|\n",
                            " \\ \\_______| |  | |      | |  |  \\__/ __  \\   | |\\ \\   \\ \\______\n",
                            "  \\_________/   |_|      |_|   \\_____/  \\__\\  |_| \\_\\   \\______/\n"
    };

    for (int i = 0; i < 10; ++i) {//��ӡ����
        setForeColor(9 + i % 6); // color 9-14
        printf("%s", logo[i]);
    }
    const char *select_menu[7] = {
            "        _______________________________________________\n",
            "        |                                             |\n",
            "        |       ��ѡ��:                               |\n",
            "        |       1.��ʼ��Ϸ     2.�˳���Ϸ             |\n",
            "        |                                             |\n",
            "        |                                             |\n",
            "        -----------------------------------------------\n"
    };
    for (int i = 0; i < 7; ++i) {//��ӡ�˵�
        setForeColor(9 + i % 6); // color 9-14
        printf("%s", select_menu[i]);
    }
    setForeColor(15); // ����ɫ
    const char *select = "                    ��������[1/2]:[ ]";
    printf("%s", select);
}

void initGame() {//��ʼ����������
    clearWindow();
    setDifficulty();
    printBox();
    initSnakeAndApple();
}

void wrongInput() {//�������ļ�������---��ӡ������Ϣ
    gotoxy(43, 17);
    printf("�������!");
    Sleep(1000);//ͣ��һ��������Ϣ
    gotoxy(43, 17);
    printf("         ");
    gotoxy(39, 17);
}