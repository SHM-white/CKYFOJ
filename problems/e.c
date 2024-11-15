#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#define DEBUG
//enums
enum commandType
{
    barrier,
    putFood,
    up,
    down,
    left,
    right
};
enum status
{
    error = -1,
    nullPoint,
    obstacle,
    food,
    body_up,
    body_down,
    body_left,
    body_right
};

//types
typedef struct{
    int time;
    int x;
    int y;
    enum commandType c;
} command;
typedef struct 
{
    int x;
    int y;
} position;

//global values
int m, n;
int **map;
position head;
position end;
command *commands[65535] = {NULL};
unsigned short timeLine[65535] = {0};

//functions
void setup();
position getEnd();
enum status getStatus(position p);
bool update(int currentTime);
bool actCommand(command cmd);
bool deleteEnd();
position getNext(position current);
position getLast(position current);
bool setValue(position p, enum status s);

#ifdef DEBUG
void printMap(){
    puts("----------------------");
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; j++)
        {
            printf("%d ", map[j][i]);
        }
        printf("\n");
    }
    puts("----------------------");
}
#endif

//The logical part of the functions
void setup(){
    scanf("%d %d", &m, &n);
    map = (int **)calloc(m, sizeof(int *));
    for (size_t i = 0; i < m; i++)
    {
        map[i] = (int *)calloc(n, sizeof(int));
        for (size_t j = 0; j < n; j++)
        {
            map[i][j] = nullPoint;
        }
        
    }
    int x, y;
    scanf("%d %d", &x, &y);
    map[x][y] = body_up;
    head.x = x;
    head.y = y;
    end = head;
}
enum status getStatus(position p){
    if(p.x >= m || p.x < 0 || p.y >= n || p.y < 0){
        return -1;
    }
    return map[p.x][p.y];
}
bool deleteEnd(){
    position newEnd = getNext(end);
    if(newEnd.x==-1||newEnd.y==-1){
        return false;
    }
    setValue(end,nullPoint);
    end = newEnd;
    return true;
}
position getNext(position current){
    position result = current;
    switch (getStatus(current))
    {
    case body_up:
        result.y++;
        break;
    case body_down:
        result.y--;
        break;
    case body_left:
        result.x--;
        break;
    case body_right:
        result.x++;
        break;
    default:
        break;
    }
    if(getStatus(result) >= 3 && getStatus(result) <= 6){
        return result;
    }
    else{
        return (position){-1, -1};
    }
    
}
position getLast(position current){
    int searchX[] = {1, -1, 0, 0};
    int searchY[] = {0, 0, 1, -1};
    for (size_t i = 0; i < 4; i++)
    {
        position new = current;
        new.x += searchX[i];
        new.y += searchY[i];
        position result = getNext(new);
        if(result.x == current.x && result.y == current.y){
            return new;
        }
    }
    return (position){-1, -1};
}
position getEnd(){
    return end;
}
bool actCommand(command cmd){
    switch (cmd.c)
    {
    case barrier:
        setValue((position){cmd.x, cmd.y}, obstacle);
        break;
    case putFood:
        setValue((position){cmd.x, cmd.y}, food);
        break;
    case up:
        if(getStatus(head) == body_down){
            return false;
        }
        setValue(head, body_up);
        break;
    case down:
        if(getStatus(head) == body_up){
            return false;
        }
        setValue(head, body_down);
        break;
    case left:
        if(getStatus(head) == body_right){
            return false;
        }
        setValue(head, body_left);
        break;
    case right:
        if(getStatus(head) == body_left){
            return false;
        }
        setValue(head, body_right);
        break;    
    default:
        break;
    }
    return true;
}
bool update(int currentTime){
    for (size_t i = 0; i < timeLine[currentTime]; i++)
    {
        if(!actCommand(commands[currentTime][i])){
            printf("%d d\n", currentTime);
            return false;
        }
    }
    position next = head;
    switch (getStatus(head))
    {
    case body_up:
        next.y--;
        break;
    case body_down:
        next.y++;
        break;
    case body_left:
        next.x--;
        break;
    case body_right:
        next.x++;
        break;
    default:
        break;
    }
    enum status nextStatus = getStatus(next);
    if(nextStatus == nullPoint || nextStatus == food){
        setValue(next, getStatus(head));
        head = next;
        if(nextStatus == nullPoint){
            deleteEnd();
        }
        else{
            printf("%d f\n", currentTime);
        }
        return true;
    }
    else
    {
        printf("%d d\n", currentTime);
        return false;
    }
    
}
bool setValue(position p, enum status s){
    if(p.x >= 0 && p.x < m && p.y >= 0 && p.y < n){
        map[p.x][p.y] = s;
        return true;
    }
    return false;
}

//main() function
int main(){
    int currentTime = 0;
    setup();
    int cmdCount;
    scanf("%d", &cmdCount);
    for (size_t i = 0; i < cmdCount; i++)
    {
        char cmd;
        int time, x, y;
        scanf("%d", &time);
        timeLine[time] += 1;
        commands[time] = realloc(commands[time], sizeof(command) * timeLine[time]);
        scanf("%d %d %c", &x, &y, &cmd);
        commands[time][timeLine[time] - 1].x = x;
        commands[time][timeLine[time] - 1].y = y;
        switch (cmd)
        {
        case 'u':
            commands[time][timeLine[time] - 1].c = up;
            break;
        case 'd':
            commands[time][timeLine[time] - 1].c = down;
            break;
        case 'b':
            commands[time][timeLine[time] - 1].c = barrier;
            break;
        case 'f':
            commands[time][timeLine[time] - 1].c = putFood;
            break;
        case 'l':
            commands[time][timeLine[time] - 1].c = left;
            break;
        case 'r':
            commands[time][timeLine[time] - 1].c = right;
            break;
        default:
            break;
        }
    }
    while (1)
    {
#ifdef DEBUG
        printMap();
#endif
        if(!update(currentTime)){
            break;
        }
        currentTime++;
    }
    return 0;
}