#include <stdio.h>

#define MOVIES 5
#define SHOWTIMES 2
#define ROWS 5
#define COLS 10

typedef struct {
    int booked;
    char customerName[50];
    float seatPrice;
    float pricePaid;

} Seat;

typedef struct
{
    char movieTitle[50];
    char showTime[20];

    Seat seats[ROWS][COLS];

    float revenue;
    int ticketsSold;

} MovieShow;

extern MovieShow movies[MOVIES][SHOWTIMES];

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

void viewShowtimes(MovieShow movies[MOVIES][SHOWTIMES])
{
    int availableSeats;

    printf("\n=====================================================================================\n");
    printf("%-4s %-30s %-22s %-18s\n", "No.", "Movie Title", "Show Time", "Available Seats");
    printf("=====================================================================================\n");

    int no = 1;

    for (int i = 0; i < MOVIES; i++)
    {
        for (int j = 0; j < SHOWTIMES; j++)
        {
            availableSeats = (ROWS * COLS) - movies[i][j].ticketsSold;

            printf("%-4d %-30s %-22s %9d\n",
                   no++,
                   movies[i][j].movieTitle,
                   movies[i][j].showTime,
                   availableSeats);
        }
    }

    printf("=====================================================================================\n");
}



 //Print options to book,choose seat, cancel a boooking

 //Print the seatmap
