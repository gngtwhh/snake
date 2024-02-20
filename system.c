//与控制台相关的函数
//控制光标位置,当前打印颜色,检测键盘输入
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "snake.h"

//system
//使用ANSI终端控制码来控制,设置打印颜色
void color(int fore, int back) {
    if (fore < 0 && back < 0)
        return;
    else if(fore < 0)
        printf("\033[0;%dm", back + 40);
    else if(back < 0)
        printf("\033[0;%dm", fore + 30);
    else
        printf("\033[0;%d;%dm", fore + 30, back + 40);
}

//重置打印颜色
void resetColor() {
    printf("\033[0m");
}

//游戏中每次调用gotoxy时的参数都是根据游戏菜单字符位置/当前坐标计算好传递过来的
//使用ANSI终端控制码来控制
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y+1, x+1); // 注意x和y的顺序
    // 主调函数的坐标是从0开始的,而控制台的坐标是从1开始的
}

int keyboard(int pre) {//键盘输入判断
    char c;
    int n = pre;
    if (_kbhit()) {//检查是否有键盘输入
        c = _getch();//如果有,则进行一次读取
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
    rewind(stdin);//fflush(stdin); 刷新缓冲区,在VS2015之后不再起作用(编译成功但无效果)
    if ((pre == 1 && n == 3) || (pre == 2 && n == 4) || (pre == 3 && n == 1) ||
        (pre == 4 && n == 2))
        return pre;//如果键盘要求蛇180度转向,则转向失败,蛇仍然按照原来的方向前进
    return n;//成功转向,返回下一步前进的方向
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