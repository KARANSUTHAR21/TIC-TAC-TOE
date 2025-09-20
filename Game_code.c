#include <stdio.h>

void board(char matrix[3][3]);
void x_and_o();
int winner_case(char matrix[3][3], int player); // updated to take player

void board(char matrix[3][3])
{
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf(" %c ", matrix[i][j]);
            if (j < 2)
            {
                printf("|");
            }
        }
        printf("\n");
        if (i < 2)
        {
            printf("---|---|---\n");
        }
    }
    printf("\n");
}

void x_and_o()
{
    char matrix[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    int n = 0, rows, column;
    char character;
    int player = 1;

    while (n < 9)
    {
        printf("Player %d, enter row (1-3): ", player);
        scanf("%d", &rows);
        if (rows == -1)
            break;

        printf("Player %d, enter column (1-3): ", player);
        scanf("%d", &column);

        if ((rows >= 1 && rows <= 3) && (column >= 1 && column <= 3) && matrix[rows - 1][column - 1] == ' ')
        {
            character = (player == 1) ? 'X' : 'O';
            matrix[rows - 1][column - 1] = character;
            board(matrix);

            if (winner_case(matrix, player))  // pass player to check only their symbol
            {
                printf("Player %d wins!\n", player);
                return; 
            }

            player = (player == 1) ? 2 : 1; 
            n++;
        }
        else
        {
            printf("Invalid move! Please choose an empty spot within range.\n");
        }
    }

    printf("It's a draw!\n"); 
}

int winner_case(char matrix[3][3], int player)
{
    char symbol = (player == 1) ? 'X' : 'O';

    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == symbol && matrix[i][1] == symbol && matrix[i][2] == symbol)
            return 1;
    }
    for (int j = 0; j < 3; j++)
    {
        if (matrix[0][j] == symbol && matrix[1][j] == symbol && matrix[2][j] == symbol)
            return 1;
    }
    if (matrix[0][0] == symbol && matrix[1][1] == symbol && matrix[2][2] == symbol)
        return 1;
    if (matrix[0][2] == symbol && matrix[1][1] == symbol && matrix[2][0] == symbol)
        return 1;

    return 0; 
}

int main()
{
    x_and_o();
    return 0;
}
