#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define DEBUG

int n;
bool **map;

#ifdef DEBUG
void printMap(){
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%d", map[i][j]);
        }
        printf("\n");
    }
    
}
#endif

typedef enum
{
    up,
    down,
    left,
    right
} Direction;
typedef struct Position
{
    int x;
    int y;
    int currentStep;
    Direction lastPosDirection;
    struct Position *lastPos;
} Position;
int getStep(Position* pos){
    if (pos->x == n - 1 && pos->y == n - 1){
        return pos->currentStep;
    }
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    //down right up left

}
int main(){
    scanf("%d", &n);
    n = n * 2 + 1;
    map = calloc(n, sizeof(bool *));
    for (size_t i = 0; i < n; i++)//read map
    {
        map[i] = calloc(n, sizeof(bool));

        char input[200];
        fflush(stdin);
        
        fgets(input, 2 * n + 2, stdin);
        for (size_t j = 0; j < n; j++)
        {
            if (input[j * 2] == ' ')
            {
                map[i][j] = true;
            }
            else
            {
                map[i][j] = false;  
            }
        }
    }
    printMap();
    return 0;
}