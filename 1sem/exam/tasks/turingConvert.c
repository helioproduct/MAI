#include <stdio.h>

// Action: L, R, S
struct Turing5 {

    unsigned currentState;
    char currentChar;
    char newChar;
    char action;
    unsigned newState;

};

// Action: I, L, R, S
struct Turing4 {

    unsigned currentState;
    char currentChar;
    char newChar;
    unsigned newState;

};


// Разбить команду в пятерках на 2 команды в четверках
int main(void)
{

    return 0;
}