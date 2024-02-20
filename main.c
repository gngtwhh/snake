// Author: WAHAHA
// Update: 2024-02-20
// Overview: A pure console simple snake game,
//     based on ANSI terminal control code drawing

#include <stdio.h>
#include <conio.h>
#include "snake.h"//包含了所有的函数声明,和为了与c++兼容设置的bool宏

int main() {
    printMenu();//第一次进入循环前先初始化一次菜单
    int c;
    while (1) {//控制主循环
        gotoxy(37, 17);//定位到输入栏
        c = _getch(); // 无回显输入
        if (c == '1') {
            initGame();//游戏数据初始化
            start();//正式开始一局游戏
            destoryGameData();//清除游戏数据,释放空间
            clearWindow();//游戏结束清屏
            printMenu();//重新打印菜单
        } else if (c == '2') {
            setForeColor(107);//将颜色设置回白色
            gotoxy(0, 18);
            printf("游戏结束!\n");
            break;//跳出循环,结束游戏
        } else wrongInput();//输入非法,打印错误信息
    }
    return 0;
}