#include <stdio.h>
#include <windows.h>
#include "snake.h"

//nemu
void printMenu() {
    resetColor(); // 重置颜色
    gotoxy(0,0); // 光标重定位
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

    for (int i = 0; i < 10; ++i) {//打印标题
        setForeColor(9 + i % 6); // color 9-14
        printf("%s", logo[i]);
    }
    const char *select_menu[7] = {
            "        _______________________________________________\n",
            "        |                                             |\n",
            "        |       请选择:                               |\n",
            "        |       1.开始游戏     2.退出游戏             |\n",
            "        |                                             |\n",
            "        |                                             |\n",
            "        -----------------------------------------------\n"
    };
    for (int i = 0; i < 7; ++i) {//打印菜单
        setForeColor(9 + i % 6); // color 9-14
        printf("%s", select_menu[i]);
    }
    setForeColor(15); // 亮白色
    const char *select = "                    请输入编号[1/2]:[ ]";
    printf("%s", select);
}

void initGame() {//初始化各项数据
    clearWindow();
    setDifficulty();
    printBox();
    initSnakeAndApple();
}

void wrongInput() {//处理错误的键盘输入---打印报错信息
    gotoxy(43, 17);
    printf("输入错误!");
    Sleep(1000);//停顿一秒后清除信息
    gotoxy(43, 17);
    printf("         ");
    gotoxy(39, 17);
}