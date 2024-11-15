#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int max(int a,int b){
    if(a > b){
        return a;
    }
    else{
        return b;
    }
}
typedef struct
{
    int r;
    int c;
} position;
position *getBeginPoints(int **lands, int row, int col, int *count) {
    position *pos = malloc(sizeof(position) * (row * col)); // 预分配内存
    *count = 0;
    
    for (size_t i = 0; i < row; i++) {
        for (size_t j = 0; j < col; j++) {
            bool suitable = true;
            if (i > 0) suitable &= (lands[i - 1][j] <= lands[i][j]);
            if (i < row - 1) suitable &= (lands[i + 1][j] <= lands[i][j]);
            if (j > 0) suitable &= (lands[i][j - 1] <= lands[i][j]);
            if (j < col - 1) suitable &= (lands[i][j + 1] <= lands[i][j]);
            if (suitable) {
                pos[(*count)++] = (position){i, j}; // 直接赋值
            }
        }
    }
    return pos;
}
int getMaxLength(int **land, int row, int col, position *startPoint, int **memo) {
    if (memo[startPoint->r][startPoint->c] != -1) {
        return memo[startPoint->r][startPoint->c];
    }

    int lengthAfter = 0;
    // 四个方向
    int d_row[] = {0, 0, -1, 1};
    int d_col[] = {1, -1, 0, 0};

    for (int i = 0; i < 4; i++) {
        int newRow = startPoint->r + d_row[i];
        int newCol = startPoint->c + d_col[i];
        if (newRow >= 0 && newRow < row && newCol >= 0 && newCol < col) {
            if (land[newRow][newCol] < land[startPoint->r][startPoint->c]) {
                position p2 = {newRow, newCol};
                lengthAfter = max(lengthAfter, getMaxLength(land, row, col, &p2, memo));
            }
        }
    }
    memo[startPoint->r][startPoint->c] = lengthAfter + 1; // 存储结果
    return memo[startPoint->r][startPoint->c];
}
int **createLands(int row, int col)
{
    int **lands_row = (int **)calloc(row, sizeof(int *));
    for (size_t i = 0; i < row; i++)
    {
        lands_row[i] = (int *)calloc(col, sizeof(int));
    }
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < col; j++)
        {
            scanf("%d", &lands_row[i][j]);
        }
    }
    return lands_row;
}
int main() {
    int col, row;
    scanf("%d %d", &row, &col);
    if (row == 1 && col == 1) {
        printf("1");
        return 0;
    }

    int **map = createLands(row, col);
    int count = 0;
    position *positions = getBeginPoints(map, row, col, &count);
    
    // 初始化记忆化数组
    int **memo = (int **)malloc(row * sizeof(int *));
    for (int i = 0; i < row; i++) {
        memo[i] = (int *)malloc(col * sizeof(int));
        for (int j = 0; j < col; j++) {
            memo[i][j] = -1; // -1 表示未计算
        }
    }

    int length = 0;
    for (size_t i = 0; i < count; i++) {
        length = max(length, getMaxLength(map, row, col, positions + i, memo));
    }
    printf("%d", length);

    // 释放内存
    for (int i = 0; i < row; i++) {
        free(map[i]);
        free(memo[i]);
    }
    free(map);
    free(memo);
    free(positions);

    return 0;
}