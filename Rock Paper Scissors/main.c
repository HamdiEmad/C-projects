#include "RPS.h"

int main()
{
    while (1)
    {
        display_menu();
        int8_t user = input_handler();
        if (user == EXIT_STATUS) {
            credits();
            break;
        } 
        if (user != UNDEFINED_INPUT) {
            int8_t computer = computer_choice();
            int8_t result = winner_or_loser(computer, user);
            print_winner(result);
        }
        else print_error();
    }
}