#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void clear_screen();
static void init(int);
static void game();
static void menu();

enum { ID_X, ID_0 };

static char board[9];
static int queue = ID_X;
static int counter = 0;

static void clear_screen()
{
    int n;
    for (n = 0; n < 30; n++)
        printf("\n");
}

static void init(int k)
{
    if (board[k] == '-')
    {
        if (queue == ID_X)
        {
            queue = ID_0;
            board[k] = 'X';
        }
        else if (queue == ID_0)
        {
            queue = ID_X;
            board[k] = '0';
        }
        counter++;
    }
}

static void game()
{
    clear_screen();
    printf(
        "Menu:\n\n"
        " -1-|-2-|-3-\n"
        " -4-|-5-|-6-\n"
        " -7-|-8-|-9-\n\n\n");
    printf("Board:\n\n");
    printf(" -%c-|-%c-|-%c-\n", board[0], board[1], board[2]);
    printf(" -%c-|-%c-|-%c-\n", board[3], board[4], board[5]);
    printf(" -%c-|-%c-|-%c-\n", board[6], board[7], board[8]);

    int end_game = 0;
    if (counter == 9)
        end_game = 3;
    else
    {
        // X
        if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') end_game = 1;
        if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') end_game = 1;
        if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') end_game = 1;
        if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') end_game = 1;
        if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') end_game = 1;
        if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') end_game = 1;
        if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') end_game = 1;
        if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') end_game = 1;

        // 0
        if (board[0] == '0' && board[1] == '0' && board[2] == '0') end_game = 2;
        if (board[3] == '0' && board[4] == '0' && board[5] == '0') end_game = 2;
        if (board[6] == '0' && board[7] == '0' && board[8] == '0') end_game = 2;
        if (board[0] == '0' && board[3] == '0' && board[6] == '0') end_game = 2;
        if (board[1] == '0' && board[4] == '0' && board[7] == '0') end_game = 2;
        if (board[2] == '0' && board[5] == '0' && board[8] == '0') end_game = 2;
        if (board[0] == '0' && board[4] == '0' && board[8] == '0') end_game = 2;
        if (board[2] == '0' && board[4] == '0' && board[6] == '0') end_game = 2;
    }
    switch (end_game)
    {
    case 1:
        printf("\n!!! X peremih !!!\n");
        break;
    case 2:
        printf("\n!!! 0 peremih !!!\n");
        break;
    case 3:
        printf("\n!!! nichya !!!\n");
        break;
    }
    if (end_game)
    {
        getchar();
        menu();
    }

    printf("\nEnter the number: ");
    char str[2];
    gets(str);

    init(atoi(str) - 1);
    game();
}

static void menu()
{
    queue = ID_X;
    counter = 0;
    memset(board, '-', 9);
    clear_screen();

    printf(
        "Game Menu:\n\n"
        " 1 - New Game\n"
        " 2 - Exit\n\n"
        "Enter the number: ");

    char str[16];
    gets(str);
    switch (str[0])
    {
    case '1':
        game();
        break;

    case '2':
        exit(0);
        break;

    default:
        menu();
    }
}

int main()
{
    menu();
    return 0;
}
