#include "RPS.h"

void display_menu()
{
    printf("##################################\n");
    printf("#         Choose a number        #\n");
    printf("##################################\n");
    printf("#            (1) Scissors        #\n");
    printf("#            (2) Paper           #\n");
    printf("#            (3) Rock            #\n");
    printf("#            (4) Exit            #\n");
    printf("##################################\n");
}

int8_t input_handler()
{
    char buffer[64];
    int input;

    if (!fgets(buffer, sizeof(buffer), stdin))
        return UNDEFINED_INPUT;

    if (sscanf(buffer, "%d", &input) != 1)
        return UNDEFINED_INPUT;

    if (input < 1 || input > 4)
        return UNDEFINED_INPUT;

    if (input == 4)
        return EXIT_STATUS;

    return (int8_t)input;
}

int8_t winner_or_loser(int8_t computer, int8_t user)
{
    if (computer == user)
        return TIE;
    if (computer == SCISSORS)
    {
        return user == ROCK ? WIN : LOSE;
    }
    else if (computer == PAPER)
    {
        return user == ROCK ? LOSE : WIN;
    }
    else
    {
        return user == PAPER ? WIN : LOSE;
    }
}

int8_t computer_choice()
{
    srand(time(NULL));
    int8_t comp = rand() % 3;
    printf("##################################\n");
    printf("#     Computer choose: %s#\n", choices[comp]);
    return comp + 1;
}

void print_winner(int8_t result)
{
    switch (result)
    {
    case WIN:
        printf("#             YOU WIN            #\n");
        printf("##################################\n");
        break;

    case LOSE:
        printf("#             YOU LOST           #\n");
        printf("##################################\n");
        break;

    default:
        printf("#               TIE              #\n");
        printf("##################################\n");
        break;
    }
}

void print_error()
{
    printf("##################################\n");
    printf("#          UNDEFINED INPUT       #\n");
    printf("#          Please try again      #\n");
    printf("##################################\n");
}

void credits()
{
    printf("##################################\n");
    printf("#       THANKS FOR PLAYING       #\n");
    printf("##################################\n");
}