#include <stdio.h>
int ValidateMainMenu(int option);
//Printing the option menu
void DisplayMenu(){

    printf("-----------------------------------\n");
    printf("        Lights Camera Book!        \n");
    printf("-----------------------------------\n");

    printf("Welcome to the Movie Booking system!\n");
    printf("-----------------------------------\n");

    printf("    1. View Showtimes\n");
    printf("    2. View Seat Map\n");
    printf("    3. Book a Seat\n");
    printf("    4. Cancel a Booking\n");
    printf("    5. Search Booking\n");
    printf("    6. View Revenue Report\n");
    printf("    7. Exit\n");

    printf("-----------------------------------\n\n");

}

//Asking for user input


void GetUserInput(){
    int UserOption= 0;

    do{
        printf("Please select an option: ");
        scanf("%d",&UserOption);

    }while(ValidateMainMenu(UserOption));

}


 // Show the list of all movies

 //Print options to book,choose seat, cancel a boooking

 //Print the seatmap
