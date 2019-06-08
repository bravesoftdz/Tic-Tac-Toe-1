#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void clear_screen();
static int init(int);
static void game();
static void menu();

enum {
    ID_X,
    ID_0
};

static char board[9];
static unsigned int queue;
static unsigned int counter;

static void clear_screen()
{
    unsigned int i;
    for (i = 0; i < 50; i++)
        fprintf(stdout, "\n");
}

static int init(int k)
{
    if (k < 0 || k > 8)
        return 0;

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
    return 1;
}

static void game()
{
    clear_screen();
    fprintf(stdout,
        "Menu:\n\n"
        " -1-|-2-|-3-\n"
        " -4-|-5-|-6-\n"
        " -7-|-8-|-9-\n\n\n");
    fprintf(stdout, "Board:\n\n");
    fprintf(stdout, " -%c-|-%c-|-%c-\n", board[0], board[1], board[2]);
    fprintf(stdout, " -%c-|-%c-|-%c-\n", board[3], board[4], board[5]);
    fprintf(stdout, " -%c-|-%c-|-%c-\n", board[6], board[7], board[8]);

    unsigned int end_game = 0;
    if (counter == 9)
        end_game = 3;
    else
    {
        if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') end_game = 1;
        if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') end_game = 1;
        if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') end_game = 1;
        if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') end_game = 1;
        if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') end_game = 1;
        if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') end_game = 1;
        if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') end_game = 1;
        if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') end_game = 1;

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
        fprintf(stdout, "\n!!! X wined !!!\n");
        break;
    case 2:
        fprintf(stdout, "\n!!! 0 wined !!!\n");
        break;
    case 3:
        fprintf(stdout, "\n;; Draw, keep trying ;;\n");
        break;
    }

    if (end_game)
    {
        getchar();
        menu();
    }

    fprintf(stdout, "\nEnter the number: ");

    char c = 0;
    while (!isdigit(c))
        fscanf(stdin, "%c", &c);
    fflush(stdin);

    init(c - '0' - 1);
    game();
}

static void menu()
{
    queue = ID_X;
    counter = 0;
    memset(board, '-', 9);
    clear_screen();

    fprintf(stdout,
        "Game Menu:\n\n"
        " 1 - New Game\n"
        " 2 - Exit\n\n"
        "Enter the number: ");

    char c = 0;
    while (!isdigit(c))
        fscanf(stdin, "%c", &c);
    fflush(stdin);

    switch (c)
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

int main(int argc, char *argv[])
{
    menu();
    return 0;
}
