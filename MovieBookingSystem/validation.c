#include <stdio.h>

//Validating The Main menu options

int ValidateMainMenu(int option){
    if (option<1 || option>7){
        printf("Invalid Menu option.Enter a Valid option\n");
        return 1;
    }
    return 0;
}
//Handling invalid  user inputs when choosing a movie

//Handling invalid user innputs when booking,canceling and searching seat


