#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
// #define ROW 3
// #define COL 3
void menu()
{
    printf("----------TIC-TAC-TOC GAME-----------\n");
    printf("-----1.Begin----------0.Sign out-----\n");
    printf("-------------------------------------\n");
}
void game()//游戏代码实现
{
    char ret = 0;
    char board[ROW][COL]={0};
    //初始化棋盘
    InitBoard(board, ROW, COL);
    //打印棋盘
    DisplayBoard(board,ROW,COL);
    //下棋
    while (1)
    {
        //玩家下棋
        PlayerMove(board, ROW, COL);
        DisplayBoard(board,ROW,COL);
        //判断电脑是否赢
        ret = IsWin(board,ROW,COL);
        if (ret!='c')
        {
            break;
        }
        //电脑下棋
        ComputerMove(board, ROW, COL);
        DisplayBoard(board,ROW,COL);
        ret = IsWin(board,ROW,COL);
        if (ret!='c')
        {
            break;
        }
    }
    if (ret=='*')
    {
        printf("The player won!\n");
    }
    else if(ret=='#')
    {
        printf("Computer won!\n");
    }
    else
    {
        printf("It ends in a draw!\n");
    }
    
    
}
void test()
{
    int start = 0;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("Please choose whether to start the game\n");
        scanf("%d", &start);
        switch (start)
        {
        case 1:
            game();
            break;
        case 0:
            printf("----------Sign out game-----------\n");
            break;
        default:
            printf("----------Choose  Again-----------\n");
            break;
        }
    } while (start);
}
main()
{
    test();
    getchar();
    getchar();
}