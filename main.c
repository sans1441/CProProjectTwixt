#include <stdio.h>
#include <stdlib.h>
#include "node.h"
#define MAX 24

int main()
{
    Node *board[MAX+1][MAX+1];

    for(int i=1; i<=MAX; i++)
        for(int j=1; j<=MAX; j++)
            board[i][j] = createNode(i, j);

    int player = 1;

    while(1)
    {
        printf("    ");
        for(int i=1; i<=MAX; i++)
        {
            if(i == 1)
            {
                printf("%2d   ", i);
                continue;
            }
            if(i == MAX)
            {
                printf("  %2d", i);
                continue;
            }
            printf("%2d ", i);
        }
        printf("\n");

        for(int j=1; j<=MAX; j++)
        {
            if(j == 2)
            {
                printf("    ");
                for(int k=1; k<=MAX*3+5; k++) printf("\033[31m-\033[0m");
                printf("\n");
            }

            if(j == MAX)
            {
                printf("    ");
                for(int k=1; k<=MAX*3+5; k++) printf("\033[31m-\033[0m");
                printf("\n");
            }

            printf("%2d   ", j);

            for(int i=1; i<=MAX; i++)
            {
                if(board[i][j]->player == 0) printf(".  ");
                else if(board[i][j]->player == 1) printf("\033[31mX\033[0m  ");
                else if(board[i][j]->player == 2) printf("\033[34mO\033[0m  ");

                if(i == 1) printf("\033[34m|\033[0m  ");
                if(i == MAX-1) printf("\033[34m|\033[0m  ");
            }

            printf("\n");
        }

        int x, y;
        printf("Player %d, enter x y coordinates (-1 -1 to exit): ", player);
        int ok = scanf("%d %d", &x, &y);

        if(ok != 2)
        {
            printf("Invalid syntax.\n");
            int ch;
            while((ch=getchar())!='\n' && ch!=EOF);
            continue;
        }

        if(x == -1 && y == -1) break;

        if(x < 1 || x > MAX || y < 1 || y > MAX)
        {
            printf("Out of bounds.\n");
            continue;
        }

        if(player == 1 && (x == 1 || x == MAX))
        {
            printf("Player 1 cannot play on the left or right border.\n");
            continue;
        }

        if(player == 2 && (y == 1 || y == MAX))
        {
            printf("Player 2 cannot play on the top or bottom border.\n");
            continue;
        }

        if(board[x][y]->player != 0)
        {
            printf("Cell occupied.\n");
            continue;
        }

        board[x][y]->player = player;

        if(player == 1) player = 2;
        else player = 1;

        printf("\n");
    }

    return 0;
}
