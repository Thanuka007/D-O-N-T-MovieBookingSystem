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
void viewShowtimes(MovieShow movies[MOVIES][SHOWTIMES]);
void getCustomerMovie();
void selectSeat();
void bookSeat(char seatRow, int seatColumn,int movieIndex,int ShowtimeIndex);
void viewSeatMap(int movieIndex, int showtimeIndex);


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

    switch(UserOption){

        case 1:
            viewShowtimes(movies);
            break;
        case 2:
            viewShowtimes(movies);
            getCustomerMovie();
            break;
        case 3:
            viewShowtimes(movies);
            getCustomerMovie();

            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            return;

    }
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

void getCustomerMovie(){
    int movieChoice = 0;
    printf("Please select an option: ");
    scanf("%d",&movieChoice);

    if(movieChoice>=1 && movieChoice <=10){
        switch(movieChoice){
            case 1:
                viewSeatMap(0,0);
                break;
            case 2:
                viewSeatMap(0,1);
                break;
            case 3:
                viewSeatMap(1,0);
                break;
            case 4:
                viewSeatMap(1,1);
                break;
            case 5:
                viewSeatMap(2,0);
                break;
            case 6:
                viewSeatMap(2,1);
                break;
            case 7:
                viewSeatMap(3,0);
                break;
            case 8:
                viewSeatMap(3,1);
                break;
            case 9:
                viewSeatMap(4,0);
                break;
            case 10:
                viewSeatMap(4,1);
                break;

        }
    }

}



void selectSeat(){

    char userName[12];
    int seatcount;

    printf("Enter your name: ");
    scanf("%s",&userName);

    printf("How many seats u want to book? ");
    scanf("%d",&seatcount);



    for(int i = 0; i <seatcount;i++){
        char seatRow;
        char seatCol;

        printf("Select a seat row (A-E): ");
        scanf(" %c",&seatRow);

        printf("Select a seat column (1-10)");
        scanf("%d",&seatCol);

        //seat availability should be checked
        //bookSeat()
    }


}



//printing the seatmap
void viewSeatMap(int movieIndex, int showtimeIndex)
{
    printf("\n");
    printf("Movie    : %s\n",movies[movieIndex][showtimeIndex].movieTitle);
    printf("Showtime : %s\n\n",movies[movieIndex][showtimeIndex].showTime);

    printf("      ");
    for (int col = 0;col<COLS;col++)
    {
        printf("%-6d",col + 1);
    }
    printf("\n\n");

    for (int row = 0;row<ROWS;row++)
    {
        printf(" %c    ", 'A' + row);

        for (int col = 0;col < COLS; col++)
        {
            if (movies[movieIndex][showtimeIndex].seats[row][col].booked)
            {
                printf("[X]   ");
            }
            else
            {
                printf("[.]   ");
            }
        }

        printf("\n\n");
    }

    printf("                [.] = Available   [X] = Booked    \n");
}

// booking funtion
void bookSeat(char seatRow, int seatColumn,int movieIndex, int showtimeIndex)
{

    int row = seatRow - 'A';
    int col = seatColumn - 1;

    if (movies[movieIndex][showtimeIndex].seats[row][col].booked== 1)
    {
        printf("\nSeat %c%d is already booked.\n", seatRow, seatColumn);
    }
    else
    {
        movies[movieIndex][showtimeIndex].seats[row][col].booked = 1;
        printf("\nSeat %c%d has been booked successfully!\n", seatRow, seatColumn);
    }
}


