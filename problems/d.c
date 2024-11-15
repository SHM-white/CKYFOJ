#include <stdio.h>
#include <stdbool.h>
#define min(a, b) ((a) > (b)) ? (b) : (a)
#define max(a, b) ((a) > (b)) ? (a) : (b)
char map[6][10];//row col
bool checkMap(){
    bool result = true;
    for (size_t i = 0; i < 6; i++)
    {
        result &= !(map[i][0] >= 'a' && map[i][0] <= 'e');
    }
    return result;
}
void printMap(){
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 10; c++)
        {
            printf("%c ", map[r][c]);
        }
        printf("\n");
    }
    
}
void updateMap(){
    for (size_t r = 0; r < 6; r++)
    {
        int plantCount = 0;
        for (size_t c = 0; c < 10; c++)
        {
            if (map[r][c] == '1'){
                plantCount++;
            }
            if (plantCount && (map[r][c] <= 'e' && map[r][c] >= 'a'))
            {
                if(map[r][c]=='a'){
                    map[r][c] = '0';
                    plantCount--;
                }
                else{
                    if(plantCount > (map[r][c] - 'a')){
                        plantCount -= (map[r][c] - 'a' + 1);
                        map[r][c] = '0';
                    }
                    else{
                        map[r][c - 1] = map[r][c] - plantCount;
                        map[r][c] = '0';
                        plantCount = 0;
                    }
                }
            }
            else if (map[r][c] <= 'e' && map[r][c] >= 'a')
            {
                map[r][c - 1] = map[r][c];
                map[r][c] = '0';
            }
        }
        
    }
    
}
int main(){
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 10; c++)
        {
            map[r][c] = '0';
        }
    }
    int n;
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        int r, c;
        char type;
        scanf("%d %d %c", &r, &c, &type);
        r -= 1;
        c -= 1;
        switch (type)
        {
        case 'p':
            map[r][c] = '1';
            break;
        case 'z':
            map[r][c] = 'e';
            break;
        default:
            break;
        }
    }
    int count = 0;
    while (checkMap() && (count < 10))
    {
        updateMap();
        count++;
        //printMap();
    }
    if(checkMap()){
        puts("victory");
    }
    else{
        puts("defeat");
    }
    printMap();
    return 0;
}