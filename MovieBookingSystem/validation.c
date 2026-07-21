#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 10
//needs editing
//Validating The Main menu options

int ValidateMainMenu(int option){
    return 1;
}
//Handling invalid  user inputs when choosing a movie

//Handling invalid user innputs when booking,canceling and searching seat


bool validSeat(char seatRow,int seatCol)
{
    if (seatRow< 'A' || seatRow >= 'E' || seatCol<1 || seatCol>= 10 )
    {
        printf("Invalid seat number.Please enter a row between A-E and a column between 1-10!\n");
        return false;
    }
    return true ;
}
