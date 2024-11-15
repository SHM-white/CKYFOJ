// tanchishe.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG
typedef enum BodyDirection
{
    up = 3,
    down,
    left,
    right
} BodyDirection;
int pan = 1;       // Not used?
int time = -1;     // timeline
int m, n;          // map size
typedef struct snk // struct of snake body
{
    int len;
    int x;
    int y;
    int direct; // Why not use enum?
} snk;
int **map;
/*
map items:
1 barriar
2 food
3 body_up
4 body_down
5 body_left
6 body_right
*/
snk snake;
#ifdef DEBUG
void printMap();
#endif // DEBUG
void StepForward(int);
void EatFood(int);
void Exit()
{
    printf("%d d", time);
    exit(0);
}
void Wall(int x, int y)
{
    if (x > m - 1 || x < 0)
    {
        Exit();
    }
    if (y > n - 1 || y < 0)
    {
        Exit();
    }
}
// 判断装没装墙
void ActCommand(int x, int y, char c)
{
    switch (c)
    {
    case 'b':
        map[x][y] = 1;
        break;
    case 'f':
        map[x][y] = 2;
        break;
    case 'u':
        if (map[snake.x][snake.y] == 4)
        {
            time++;
            Exit();
        }
        map[snake.x][snake.y] = 3;
        snake.direct = 3;
        break;
    case 'd':
        if (map[snake.x][snake.y] == 3 && time != -1)
        {
            time++;
            Exit();
        }
        map[snake.x][snake.y] = 4;
        snake.direct = 4;
        break;
    case 'l':
        if (map[snake.x][snake.y] == 6)
        {
            time++;
            Exit();
        }
        map[snake.x][snake.y] = 5;
        snake.direct = 5;
        break;
    case 'r':
        if (map[snake.x][snake.y] == 5)
        {
            time++;
            Exit();
        }
        map[snake.x][snake.y] = 6;
        snake.direct = 6;
        break;
    } // 执行指令
}
void panduan(void)
{
    switch (snake.direct)
    {
    case up:
        Wall(snake.x, snake.y - 1);
        switch (map[snake.x][snake.y - 1])
        {
        case 0:
            StepForward(3);
            break;
        case 1:
            Exit();
            break;
        case 2:
            EatFood(3);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            Exit();
            break;
        }
        break;
    case down:
        Wall(snake.x, snake.y + 1);
        switch (map[snake.x][snake.y + 1])
        {
        case 0:
            StepForward(4);
            break;
        case 1:
            Exit();
            break;
        case 2:
            EatFood(4);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            Exit();
            break;
        }
        break;
    case left:
        Wall(snake.x - 1, snake.y);
        switch (map[snake.x - 1][snake.y])
        {
        case 0:
            StepForward(5);
            break;
        case 1:
            Exit();
            break;
        case 2:
            EatFood(5);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            Exit();
            break;
        }
        break;
    case right:
        Wall(snake.x + 1, snake.y);
        switch (map[snake.x + 1][snake.y])
        {
        case 0:
            StepForward(6);
            break;
        case 1:
            Exit();
            break;
        case 2:
            EatFood(6);
            break;
        case 3:
        case 4:
        case 5:
        case 6:
            Exit();
            break;
        }
        break;
    }
}
// 根据蛇蛇前方一格的内容决定操作

void EatFood(int i)
{
    switch (i)
    {
    case 3:
        map[snake.x][snake.y - 1] = 3;
        snake.y--;
        break;
    case 4:
        map[snake.x][snake.y + 1] = 4;
        snake.y++;
        break;
    case 5:
        map[snake.x - 1][snake.y] = 5;
        snake.x--;
        break;
    case 6:
        map[snake.x + 1][snake.y] = 6;
        snake.x++;
        break;
    }
    snake.len++;
    printf("%d f\n", time);
}
void StepForward(int i)
{
    int q = 0;
    q = snake.len;
    int x = snake.x;
    int y = snake.y;
    switch (i)
    {
    case 3:
        map[snake.x][snake.y - 1] = 3;
        for (; q > 0; q--)
        {
            switch (map[x][y])
            {
            case 3:
                y++;
                break;
            case 4:
                y--;
                break;
            case 5:
                x++;
                break;
            case 6:
                x--;
                break;
            }
        } // 找尾巴
        map[x][y] = 0;
        snake.y--;
        break;
    case 4:
        map[snake.x][snake.y + 1] = 4;
        for (; q > 0; q--)
        {
            switch (map[x][y])
            {
            case 3:
                y++;
                break;
            case 4:
                y--;
                break;
            case 5:
                x++;

                break;
            case 6:
                x--;
                break;
            }
        }
        map[x][y] = 0;
        snake.y++;
        break;
    case 5:
        map[snake.x - 1][snake.y] = 5;
        for (; q > 0; q--)
        {
            switch (map[x][y])
            {
            case 3:
                y++;
                break;
            case 4:
                y--;
                break;
            case 5:
                x++;
                break;
            case 6:
                x--;
                break;
            }
        }
        map[x][y] = 0;
        snake.x--;
        break;
    case 6:
        map[snake.x + 1][snake.y] = 6;
        for (; q > 1; q--)
        {
            switch (map[x][y])
            {
            case 3:
                y++;
                break;
            case 4:
                y--;
                break;
            case 5:
                x++;
                break;
            case 6:
                x--;
                break;
            }
        }
        map[x][y] = 0;
        snake.x++;
        break;
    }
}
#ifdef DEBUG
void printMap()
{
    puts("------------------------------------");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d ", map[j][i]);
        }
        putchar('\n');
    }
    puts("-----------------------------------");
}
#endif // DEBUG
// typedef struct snk snake;
int main()
{
    int x1, y1, l;
    int q = 1;

    int i = 0;
    int j = 0;
    m = n = x1 = y1 = l = 0;
    scanf("%d %d %d %d %d", &m, &n, &x1, &y1, &l);
    int *x = (int *)calloc(l, sizeof(int));
    int *y = (int *)calloc(l, sizeof(int));
    int *t = (int *)calloc(l, sizeof(int));
    char *c = (char *)calloc(l, sizeof(char));
    map = (int **)calloc(m, sizeof(int));
    for (i = 0; i < m; i++)
    {
        map[i] = (int *)calloc(n, sizeof(int));
    }
    map[x1][y1] = 3; // 0为空气，1为障碍物，2为食物，3为向上的蛇蛇身体，4为向下，5为向左，6为向右
    snake.x = x1;    // 标记蛇头位置
    snake.y = y1;
    snake.direct = 3;
    snake.len = 1;
    for (i = 0; i < l; i++)
    {
        scanf("%d %d %d %c", &t[i], &x[i], &y[i], &c[i]);
    }
    i = 0;
    while (pan == 1)
    {
        if (i < l)
        {
            if (time == t[i] - 1)
            {
#ifdef DEBUG
                printf("time:%d\n", time);
                printf("CurrentCommand:%d,%d,%c\n", x[i], y[i], c[i]);
                printMap();
#endif // DEBUG
                ActCommand(x[i], y[i], c[i]);
                i++;
            }
        }
        else
        {
            return 0;
        }
        if (time == -1)
        {
            time++;
        }
#ifdef DEBUG
        printf("time:%d\n", time);
        printMap();
#endif // DEBUG

        panduan();
        time++;
    }
    return 0;
}