#ifndef RPS_H
#define RPS_H

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SCISSORS 1
#define PAPER 2
#define ROCK 3

#define TIE 0
#define WIN 1
#define LOSE -1

#define EXIT_STATUS 0
#define UNDEFINED_INPUT -1

char *choices[] = {"SCISSORS  ", "  PAPER   ", "  ROCK    "};

void display_menu();
int8_t input_handler();
int8_t winner_or_loser(int8_t computer, int8_t user);
int8_t computer_choice();
void print_winner(int8_t result);
void print_error();
void credits();

#endif