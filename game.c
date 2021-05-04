#include "game.h"
void InitBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
        
    }
    
}
void DisplayBoard(char board[ROW][COL], int row, int col)
{
    int i = 0;
    for ( i = 0; i < row; i++)
    {
        //打印一行的数据
        // printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        int j = 0;
        for ( j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if (j<col-1)
            {
                printf("|");
            }
        }
        printf("\n");
        //打印分割行
        if (i<row-1)
        {
            // printf("---|---|---\n");
            for ( j = 0; j < col; j++)
            {
                printf("---");
                if (j<col-1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }   
}
void PlayerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("Player play chess\n");
    while (1)
    {
        //
        printf("The coordonates of the player is:\n");
        scanf("%d%d", x, y);
        if (x>=1&&x<=row&&y>=1&&y<=col)
        {
            if (board[x-1][y-1]==' ')
            {
                board[x - 1][y - 1] = '*';
                break;
            }
            else
            {
                printf("The coordinate is occupied!\n");
            }
            
        }
        else
        {
            printf("Coordinate do not match,please re-enter!\n");
        }
        
    }
    
}
void ComputerMove(char board[ROW][COL], int row, int col)
{
    int x = 0;
    int y = 0;
    printf("Computer play chess\n");
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (board[x-1][y-1]==' ')
            {
                board[x - 1][y - 1] = '#';
                break;
            }
    }
    

}
//返回1表示棋盘满了
// 返回0表示棋盘没满
int IsFull(char board[ROW][COL], int row, int col)
{
    int i = 0;
    int j = 0;
    for ( i = 0; i < row; i++)
    {
        for ( j = 0; j < col; j++)
        {
            if (board[i][j]==' ')
            {
                return 0;
            }   
        }
    }
    return 1;
}
char IsWin(char board[ROW][COL], int row, int col)
{
    int i = 0;
    //判断横三行
    for ( i = 0; i < row; i++)
    {
        if (board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]==board[i][2]&&board[i][1]!=' ')
        {
            return board[i][1];
        }
    }
    //判断竖三列
    for ( i = 0; i < col; i++)
    {
        if (board[0][i]==board[1][i]&&board[1][i]==board[2][i]&&board[0][i]==board[2][i]&&board[1][i]!=' ')
        {
            return board[1][i];
        }
    }
    //判断对角线
    if (board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]==board[2][2]&&board[1][1]!=' ')
    {
        return board[1][1];
    }
    //判断平局
    if (1==IsFull(board,ROW,COL))
    {
        return 'Q';
    }
    return 'C';
}