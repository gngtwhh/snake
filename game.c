#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "snake.h"

//��Ϸ����
typedef struct snake {
    int x, y;
    struct snake *prior, *next;
} snake;//�������һ����������
snake *head, *tail;//ָ����ͷ����β����ָ��

struct APPLE {
    int x, y;
} apple;//ƻ������������

int score, pre_x, pre_y, wait = 500;//�÷�;ǰһ��x,y����;�ȴ�ʱ��(����Ϸ�Ѷ��й�---�ı����ƶ����ٶ�)
int HEIGHT = 30;//��ͼ�߶�
int WIDTH = 30;//��ͼ���
int curSnakeLen = 0;//��ǰ��������
int maxSnakeLen = 0;//��ͼ�����ɵ����������,�ﵽ���������ζ����Ϸʤ��

//starting
void printBox() {
    bool flag = 1;
    int n;
    int cur_console_x = getWindowSizeX();
    int cur_console_y = getWindowSizeY();
    // printf("x:%d,y:%d", x, y);
    // �û��Զ����ͼ��С,�����м���Ӧ�����ɵĸ�������
    gotoxy(0, 0);
    setForeColor(15); // ����ɫ
    printf("�������ͼ��С(�����߽�,���س���ȷ��):\n");
    printf("��������(��Χ%d~%d):", min_between(cur_console_x / 4, 15),
           cur_console_x / 2);
    while (flag) {
        if (scanf("%d", &n) && n >= min_between(cur_console_x / 4, 15) &&
            n <= cur_console_x / 2) {
            flag = 0;
            WIDTH = n;
        } else {
            clearWindow();//����
            gotoxy(0, 0);
            printf("��������:");
            gotoxy(0, 1);
            printf("�������!");
            gotoxy(11, 0);
            rewind(stdin);
        }
    }

    clearWindow(); // ����

    gotoxy(0, 0);
    printf("������߶�:(��Χ%d~%d):", min_between(cur_console_y / 2 - 1, 15),
           cur_console_y - 1);
    flag = 1;
    while (flag) {
        if (scanf("%d", &n) && n >= min_between(cur_console_y / 2 - 1, 15) &&
            n <= cur_console_y - 1) {
            flag = 0;
            HEIGHT = n;
        } else {
            clearWindow();//����
            gotoxy(0, 0);
            printf("������߶�:");
            gotoxy(0, 1);
            printf("�������!");
            gotoxy(11, 0);
            rewind(stdin);
        }
    }

    // +=2��ԭ��ÿ�δ�ӡ2���ո��ַ�
    // ��ӡΧǽ
    clearWindow();//����
    setBackColor(28); //��ɫ��ͼ�߽�
    for (int i = 0; i < WIDTH * 2; i += 2) {//����
        gotoxy(i, 0);
        printf("  ");
        gotoxy(i, HEIGHT - 1);
        printf("  ");
    }
    for (int i = 1; i <= HEIGHT - 1; i++) {//����
        gotoxy(0, i);
        printf("  ");
        gotoxy(WIDTH * 2 - 2, i);
        printf("  ");
    }
    resetColor();
}

void initSnakeAndApple() {//ȱ��:�˺���δ����malloc���ܵĴ���
    //��ʼ������
    //��˫������洢������,���������ǰ/������

    //������ͷ
    head = (snake *) malloc(sizeof(snake));
    head->next = head->prior = NULL;
    head->x = 16;
    head->y = 4;
    //����ʣ��3����ͨ������---��Ϸ�����ߵĳ���Ĭ��Ϊ4
    snake *temp = head;
    for (int i = 1; i <= 3; ++i) {
        temp->next = (snake *) malloc(sizeof(snake));
        temp->next->prior = temp;
        temp = temp->next;

        temp->x = (head->x) + i * 2;
        temp->y = 4;
    }
    temp->next = NULL;
    tail = temp;
    curSnakeLen = 4;//��ʼʱ�ߵĳ���Ϊ4
    maxSnakeLen = (WIDTH - 2) * (HEIGHT - 2);//���ݵ�ͼ��С������Ϸʤ����Ӧ�ôﵽ�ĳ���

    // ע:�÷�֧�������߶�����Ϊ��ɫ
    // ��ӡ��ͷ
    temp = head;
    setBackColor(15); //��ɫ��ͷ
    gotoxy(temp->x, temp->y);
    printf("  ");

    // ��ӡ����
    temp = temp->next;
    setBackColor(15); //��ɫ����
    while (NULL != temp) {
        gotoxy(temp->x, temp->y);
        printf("  ");
        temp = temp->next;
    }

    // ��ʼ��ƻ������ӡ---��Ϸ���ֵ�һ��ƻ����λ��Ĭ��Ϊ(8,4)
    apple.x = 8;
    apple.y = 4;
    setBackColor(9); //����ɫ
    gotoxy(8, 4);
    printf("  ");

    // ��¼��β
    pre_x = tail->x;
    pre_y = tail->y;
}

void setDifficulty() {
    bool flag = 1;
    int n, difficulties[6] = {0, 1000, 800, 600, 400, 200};//5����Ϸ�Ѷ�---��Ӧ��ͬ�ĵȴ�ʱ��
    gotoxy(0, 0);//ÿ�ε���ת���Ǹ�����ʾ��Ϣ����õ�,�������׸Ķ�
    setForeColor(15); //��ɫ
    printf("�������Ѷ�[1~5](���س���ȷ��):");
    while (flag) {
        if (scanf("%d", &n) && n > 0 && n < 6)
            flag = 0;//����ɹ�������ѭ��
        else {
            clearWindow();//����
            gotoxy(0, 0);
            printf("�������Ѷ�[1~5](���س���ȷ��):");
            gotoxy(0, 1);
            printf("�������!");
            gotoxy(30, 0);
            rewind(stdin);
        }
    }
    // wait = 1100 - n * 200;
    wait = difficulties[n];//���õȴ�ʱ��
    //��ʼ������
    score = 0;

    rewind(stdin); // ˢ�»�����
    clearWindow(); // ����
}

/*
 * ��Ϸ��ѭ����,��ʽ������Ϸ,�˳���ζ�Ž���һ����Ϸ
 */
void start() {
    int flag = 2, flag2;//��ʼ�����˶�
    bool pause_game = false;
    /* ��ӡ��ʾ���� */
    gotoxy(WIDTH * 2 + 4, 3);
    resetColor();
    setForeColor(15);
    printf("wasd����,�ո����ͣ");
    gotoxy(WIDTH * 2 + 4, 5);
    printf("score:");

    while (1) {
        if (againstTheWall() || againstSelf()) {//�ж���Ϸ����
            gameover();//������Ϸ�����Ĵ���
            return; // ������Ϻ������һ�ֵ���Ϸ,��ת��������ѭ��
        }
        /* ��ӡ��ǰ�ɼ� */
        gotoxy(WIDTH * 2 + 10, 5);
        resetColor();
        setForeColor(15);
        printf("%d", score);
        /* ���˶� */
        flag2 = flag; // ���浱ǰ��ǰ������
        flag = keyboard(flag); // ��ȡ�µ�(���ܷ����ı��)�ƶ�����
        if (flag <= 4)
            moveSnake(flag);
        /* 5 ���������˿ո�,��ζ����ͣ��Ϸ */
        else if (flag == 5) {
            pause_game = true; // ������ͣ��־λ
            flag = flag2; // ǰ����������Ϊԭ���ķ���
        }
        /* ����Ե�ƻ�� */
        if (head->x == apple.x && head->y == apple.y) {

            snakeGrowth(); // �߳���
            if (curSnakeLen == maxSnakeLen) {
                gamewin();//��Ϸʤ��
                return;
            }
            // ������һ��ƻ��������(���)
            srand((unsigned int) time(NULL));
            do {
                apple.x = ((rand() % (WIDTH - 2)) + 1) * 2;
                apple.y = (rand() % (HEIGHT - 2)) + 1;
            } while (isOverlap());//ֱ��ƻ����������ȷ��(û����������������---��Ҫ���ߵ�������б���)λ��
            gotoxy(apple.x, apple.y);//��ת�������겢���д�ӡƻ��
            setBackColor(9); //����ɫ
            printf("  ");
            score++;//����+1
        }
        /* �����ͣ��־λ����Ϊtrue����ͣ��Ϸ */
        if (pause_game) {
            gotoxy(WIDTH * 2 + 4, 4);
            resetColor();
            setForeColor(15);
            printf("pause    ");
            while (_getch() != ' '); // ��ͣ����ѭ��---ֱ������ո�,����ѭ��,��Ϸ����
            rewind(stdin);
            pause_game = false;
            gotoxy(WIDTH * 2 + 4, 4);
            printf("          "); // ������ͣ��ʾ��Ϣ
        }
        Sleep(wait); // �ȴ�һ��ʱ���ټ�������
        rewind(stdin); // ˢ����Ϸ������
    }
}

bool againstTheWall() {//���ײǽ�������ͷ�������Ƿ��ǽ�ڵ������غ�
    if (head->x == 0 || head->x == WIDTH * 2 - 2 ||
        head->y == 0 || head->y == HEIGHT - 1)
        return true;
    return false;
}

bool againstSelf() {//���ײ���Լ��������ͷ�������Ƿ����һ����������غ�
    snake *temp = head->next;
    while (temp != NULL) {//��������б���
        if (head->x == temp->x && head->y == temp->y)
            return true;
        temp = temp->next;
    }
    return false;
}

// ��Ϸ�����Ĵ���
void gameover() {
    resetColor(); // ������ɫ
    clearWindow(); // ����
    gotoxy(0, 0); // ����ض�λ
    const char *endInterface[8] = {
            "        _______________________________________________\n",
            "        |                                             |\n",
            "        |        ��Ϸ����:                            |\n",
            "        |        ����:",
            "\n",
            "        |                                             |\n",
            "        -----------------------------------------------\n",
            "                    ���ո��ȷ��:[ ]"
    };
    for (int i = 0; i < 4; ++i) {
        setForeColor(9 + i % 6);
        printf("%s", endInterface[i]);
    }
    printf("%d", score);
    gotoxy(54, 3);
    putchar('|');
    for (int i = 4; i < 8; ++i) {
        setForeColor(9 + i % 6);
        printf("%s", endInterface[i]);
    }
    gotoxy(34, 6);
    while (_getch() != ' ');//ֱ������ո�Ż᷵��
}

//��Ϸʤ���Ĵ���
void gamewin() {
    resetColor(); // ������ɫ
    clearWindow(); // ����
    gotoxy(0, 0); // ����ض�λ
    const char *endInterface[8] = {
            "        _______________________________________________\n",
            "        |                                             |\n",
            "        |        ��Ϸʤ��:                            |\n",
            "        |        ����:",
            "\n",
            "        |                                             |\n",
            "        -----------------------------------------------\n",
            "                    ���ո��ȷ��:[ ]"
    };
    for (int i = 0; i < 4; ++i) {
        setForeColor(9 + i % 6);
        printf("%s", endInterface[i]);
    }
    printf("%d", score);
    gotoxy(54, 3);
    putchar('|');
    for (int i = 4; i < 8; ++i) {
        setForeColor(9 + i % 6);
        printf("%s", endInterface[i]);
    }
    gotoxy(34, 6);
    while (_getch() != ' ');//ͬ���ȴ�����
}

void moveSnake(int flag) {//�ߵ�����ǰ��
    int move[4][2] = {
            {0,  -1},
            {-2, 0},
            {0,  1},
            {2,  0}
    };//4�ֲ�ͬ���ƶ������Ӧ��4������任
    flag--;//��Ӧmove�����Ԫ��--���±�0��ʼ
    //������βλ��
    pre_x = tail->x;
    pre_y = tail->y;
    // ����β��������Ϊ������ɫ
    gotoxy(tail->x, tail->y);
    resetColor(); // ��β�뿪�ô�,���øô�Ϊ������ɫ
    printf("  ");

    /*
    ����֧�����߾�Ϊ��ɫ,�˴��벻����Ҫ
    gotoxy(head->x, head->y);
    setBackColor(15); // ��ͷ�ƶ�����λ��,������λ��Ϊ��ͷ��ɫ
    printf("  ");
    */

    //��β�Ͽ�
    snake *temp = tail;
    tail = tail->prior;
    tail->next = NULL;
    //��β�����Ϊ��ͷ,����Ҫɾ������,��ʡʱ��
    temp->next = head;
    temp->prior = NULL;
    head->prior = temp;
    head = temp;
    //����ͷλ�ü��㲢��ӡ
    head->x = head->next->x + move[flag][0];
    head->y = head->next->y + move[flag][1];
    gotoxy(head->x, head->y);
    setBackColor(15);
    printf("  ");
}

void snakeGrowth() {//�ߵĳ�������
    //����������---������β����һ����㲢���̴�ӡ(�ߴ�ʱ��ǰ��һ���ҳԵ�ƻ��
    tail->next = (snake *) malloc(sizeof(snake));
    tail->next->prior = tail;
    tail = tail->next;
    tail->next = NULL;
    tail->x = pre_x;
    tail->y = pre_y;
    ++curSnakeLen;//��ǰ����+1
    gotoxy(pre_x, pre_y);
    setBackColor(15);
    printf("  ");//���д�ӡ
}

bool isOverlap() {//��������ɵ�ƻ�������Ƿ��������κ�һ����λ�غ�
    snake *temp = head;
    while (temp != NULL) {//������������
        if (apple.x == temp->x && apple.y == temp->y)
            return true;
        temp = temp->next;
    }
    return false;
}

void destoryGameData() {//��Ҫ������������
    snake *temp = head;
    snake *next = NULL;
    while (temp != NULL) {//������������
        next = temp->next;//�����Ҳ��4�����,������temp��temp->nextΪNULL�����
        free(temp);
        temp = next;
    }
}