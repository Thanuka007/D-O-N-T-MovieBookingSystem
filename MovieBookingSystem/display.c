#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

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

void displayMainMenu();
int getUserInputFromMainMenu();
void viewShowtimes(MovieShow movies[MOVIES][SHOWTIMES]);
void getCustomerMovieToViewSeatMap();
void getCustomerMovieToBookSeat();
void getCustomerMovieToCancelBooking();
void bookSeatUI(int movieIndex,int ShowtimeIndex);
float calculateTicketPrice(float basePrice, int totalTickets, int isStudent, int isSenior);
void addDataToArray(int movieIndex,int showtimeIndex,int row,int col, char userName[50], float finalPrice);
void removeDataFromArray(int movieIndex,int showtimeIndex,int row,int col);
bool isSeatAvailable(int movieIndex,int showtimeIndex,int row,int col);
void viewSeatMap(int movieIndex, int showtimeIndex);
void cancelBookingUI(int movieIndex, int showtimeIndex);
void clearScreen();
void searchByNumberUI();
void searchByNameUI();
void searchOption();
int searchByNumber(char seatRow, int seatColumn);
int searchByName(char searchName[]);
void exitProgram();
void viewRevenueReport();
int PostActionMenu();


//Printing the option menu
void displayMainMenu(){
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
int getUserInputFromMainMenu(){

    int UserOption= 0;

    do{
            displayMainMenu();
        do
        {
            printf("Please select an option (1-7): ");

            if(scanf("%d",&UserOption)!=1)
            {
                printf("Invalid input! Enter a number (1-7).\n");
                while(getchar()!='\n');
                UserOption=0;
            }
            else if(UserOption<1 || UserOption>7)
            {
                printf("Please enter a number between 1 and 7.\n");
            }

        }while(UserOption<1 || UserOption>7);

        switch(UserOption){
            case 1:
                clearScreen();
                viewShowtimes(movies);
                break;
            case 2:
                clearScreen();
                viewShowtimes(movies);
                getCustomerMovieToViewSeatMap();
                break;
            case 3:
                clearScreen();
                viewShowtimes(movies);
                getCustomerMovieToBookSeat();
                break;
            case 4:
                clearScreen();
                viewShowtimes(movies);
                getCustomerMovieToCancelBooking();
                break;
            case 5:
                clearScreen();
                searchOption();
                break;
            case 6:
                clearScreen();
                viewRevenueReport();
                break;
            case 7:
                clearScreen();
                exitProgram();
                return 0;
        }
        return PostActionMenu();

    }while(UserOption !=7);

}


//Searching by name or row/col
void searchOption(){

    int userChoice = 0;
    printf("------------------------------------\n");
    printf("         Search  booking            \n");
    printf("------------------------------------\n");
    printf("    1. Search by Customer Name\n");
    printf("    2. Search by Seat Number\n");
    printf("------------------------------------\n");

    do
    {
        printf("Enter your choice (1-2): ");

        if(scanf("%d",&userChoice)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            userChoice=0;
        }
        else if(userChoice<1 || userChoice>2)
        {
            printf("Enter 1 or 2 only.\n");
        }

    }while(userChoice<1 || userChoice>2);
    //needs to Validate the user choice


    //implementing a switch based on user choice
    switch(userChoice){
        case 1:
            searchByNameUI();
            break;
        case 2:
            searchByNumberUI();
            break;
        default:
            printf("Invalid Input\n");
            break;
    }
}

void searchByNameUI()
{
    char searchName[50];

    printf("\nEnter customer name to search: ");
    scanf(" %49[^\n]", searchName);

    if(!searchByName(searchName))
    {
        printf("No booking found for %s\n",searchName);
    }
}

void searchByNumberUI()
{
    char seatRow;
    int seatCol;

    do
    {
        printf("\nSelect a seat row (A-E) of the ticket ");
        scanf(" %c",&seatRow);

        if(seatRow>='a' && seatRow<='e')
            seatRow -= 32;
        if(seatRow<'A' || seatRow>'E')
            printf("Invalid row! Choose A-E.\n");

    }while(seatRow<'A' || seatRow>'E');


    do
    {
        printf("Select a seat column (1-10) of the ticket ");
        if(scanf("%d",&seatCol)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            seatCol=0;
        }
        else if(seatCol<1 || seatCol>10)
        {
            printf("Column should be between 1 and 10.\n");
        }

    }while(seatCol<1 || seatCol>10);


    if(!searchByNumber(seatRow,seatCol))
    {
        printf("No booking found for Seat %c%d\n",seatRow, seatCol);
    }

}
void printSearchedBookings(char movieTitle[50], char showTime[20], char customerName[50],
                           char seatRow,int seatColumn, float pricePaid)
{
    printf("Movie     : %s\n", movieTitle );
    printf("Showtime  : %s\n", showTime);
    printf("Customer  : %s\n", customerName);
    printf("Seat      : %c%d\n", seatRow, seatColumn);
    printf("Price Paid: Rs. %.2f\n", pricePaid);
    printf("---------------------------------\n\n");
}

//Showing the movie details table
void viewShowtimes(MovieShow movies[MOVIES][SHOWTIMES])
{
    int availableSeats = 0;

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


//asking customers for their preferred movie to view Seat Map
void getCustomerMovieToViewSeatMap(){
    int movieChoice = 0;

    do
    {
        printf("Please select a show (1-10): ");

        if(scanf("%d",&movieChoice)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            movieChoice=0;
        }
        else if(movieChoice<1 || movieChoice>10)
        {
            printf("Please enter a number between 1 and 10.\n");
        }

    }while(movieChoice<1 || movieChoice>10);

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

//asking customers for their preferred movie to Book Seat
void getCustomerMovieToBookSeat(){
    int movieChoice = 0;
    do
    {
        printf("Please select a show (1-10): ");

        if(scanf("%d",&movieChoice)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            movieChoice=0;
        }
        else if(movieChoice<1 || movieChoice>10)
        {
            printf("Please enter a number between 1 and 10.\n");
        }

    }while(movieChoice<1 || movieChoice>10);


    if(movieChoice>=1 && movieChoice <=10){
        switch(movieChoice){
            case 1:
                viewSeatMap(0,0);
                bookSeatUI(0,0);
                break;
            case 2:
                viewSeatMap(0,1);
                bookSeatUI(0,1);
                break;
            case 3:
                viewSeatMap(1,0);
                bookSeatUI(1,0);
                break;
            case 4:
                viewSeatMap(1,1);
                bookSeatUI(1,1);
                break;
            case 5:
                viewSeatMap(2,0);
                bookSeatUI(2,0);
                break;
            case 6:
                viewSeatMap(2,1);
                bookSeatUI(2,1);
                break;
            case 7:
                viewSeatMap(3,0);
                bookSeatUI(3,0);
                break;
            case 8:
                viewSeatMap(3,1);
                bookSeatUI(3,1);
                break;
            case 9:
                viewSeatMap(4,0);
                bookSeatUI(4,0);
                break;
            case 10:
                viewSeatMap(4,1);
                bookSeatUI(4,1);
                break;

        }
    }

}

void getCustomerMovieToCancelBooking(){
    int movieChoice = 0;
    do
    {
        printf("Please select a show (1-10): ");

        if(scanf("%d",&movieChoice)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            movieChoice=0;
        }
        else if(movieChoice<1 || movieChoice>10)
        {
            printf("Please enter a number between 1 and 10.\n");
        }

    }while(movieChoice<1 || movieChoice>10);


    if(movieChoice>=1 && movieChoice <=10){
        switch(movieChoice){
            case 1:
                viewSeatMap(0,0);
                cancelBookingUI(0,0);
                break;
            case 2:
                viewSeatMap(0,1);
                cancelBookingUI(0,1);
                break;
            case 3:
                viewSeatMap(1,0);
                cancelBookingUI(1,0);
                break;
            case 4:
                viewSeatMap(1,1);
                cancelBookingUI(1,1);
                break;
            case 5:
                viewSeatMap(2,0);
                cancelBookingUI(2,0);
                break;
            case 6:
                viewSeatMap(2,1);
                cancelBookingUI(2,1);
                break;
            case 7:
                viewSeatMap(3,0);
                cancelBookingUI(3,0);
                break;
            case 8:
                viewSeatMap(3,1);
                cancelBookingUI(3,1);
                break;
            case 9:
                viewSeatMap(4,0);
                cancelBookingUI(4,0);
                break;
            case 10:
                viewSeatMap(4,1);
                cancelBookingUI(4,1);
                break;

        }
    }

}


//printing the seat map
void viewSeatMap(int movieIndex, int showtimeIndex)
{
    printf("\n");
    printf("Movie    : %s\n", movies[movieIndex][showtimeIndex].movieTitle);
    printf("Showtime : %s\n\n", movies[movieIndex][showtimeIndex].showTime);

    // Column header - 13 spaces to line up with the row label column below
    printf("             ");
    for (int col = 0; col < COLS; col++)
    {
        printf("%-6d", col + 1);
    }
    printf("\n\n");

    for (int row = 0; row < ROWS; row++)
    {
        const char *tier;

        if (row < 2)
        {
            tier = "Regular";
        }
        else if (row < 4)
        {
            tier = "Premium";
        }
        else
        {
            tier = "VIP";
        }

        char rowLabel[15];
        sprintf(rowLabel, "%c (%s)", 'A' + row, tier);
        printf("%-13s", rowLabel);

        for (int col = 0; col < COLS; col++)
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
    printf("        Regular = Rs. 500   Premium = Rs. 750   VIP = Rs. 1000\n");
}

// booking function
void bookSeatUI(int movieIndex, int showtimeIndex)
{
    char userName[50];
    int seatcount = 0;
    int isStudent = 0;
    int isSenior = 0;
    int discountChoice = 0;

    printf("Enter your name: ");
    scanf(" %49[^\n]", userName);

    do
    {
        printf("How many seats do you want to book?");
        //need to check seat avilability from backend.
        if(scanf("%d",&seatcount)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            seatcount=0;
        }
        else if(seatcount<1)
        {
            printf("You must book at least one seat.\n");
        }

    }while(seatcount<1);

    //discount UI

    do
    {
    printf("\nAre you eligible for a discount?\n");
    printf("1. No discount\n");
    printf("2. Student (10%% off)\n");
    printf("3. Senior Citizen (20%% off)\n");
    printf("Enter choice (1-3): ");

        if(scanf("%d",&discountChoice)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            discountChoice=0;
        }
        else if(discountChoice<1 || discountChoice>3)
        {
            printf("Please enter 1-3.\n");
        }

    }while(discountChoice<1 || discountChoice>3);

    if (discountChoice == 2) {
        isStudent = 1;
    } else if (discountChoice == 3) {
        isSenior = 1;
    }

    for (int i = 0; i < seatcount; i++) {
        char seatRow;
        int seatCol;


        do
        {
            printf("\nSelect a seat row (A-E) for ticket %d: ", i + 1);
            scanf(" %c",&seatRow);

            if(seatRow>='a' && seatRow<='e')
                seatRow -= 32;

            if(seatRow<'A' || seatRow>'E')
                printf("Invalid row! Choose A-E.\n");

        }while(seatRow<'A' || seatRow>'E');


        do
        {
            printf("Select a seat column (1-10) for ticket %d: ", i + 1);
            if(scanf("%d",&seatCol)!=1)
            {
                printf("Invalid input!\n");
                while(getchar()!='\n');
                seatCol=0;
            }
            else if(seatCol<1 || seatCol>10)
            {
                printf("Column should be between 1 and 10.\n");
            }

        }while(seatCol<1 || seatCol>10);


        int row = seatRow - 'A';
        int col = seatCol - 1;


        // Check seat availability
        if (!isSeatAvailable(movieIndex, showtimeIndex, row, col))
        {
            printf("Sorry, Seat %c%d is already booked. Please pick another.\n", seatRow, seatCol);
            i--;
            continue;
        }

        float basePrice = movies[movieIndex][showtimeIndex].seats[row][col].seatPrice;

        float finalPrice = calculateTicketPrice(basePrice, seatcount, isStudent, isSenior);

        addDataToArray(movieIndex,showtimeIndex,row,col,userName,finalPrice);

        printf("Seat %c%d booked successfully! Price paid: Rs. %.2f\n", seatRow, seatCol, finalPrice);

    }
}



//booking canceling function
void cancelBookingUI(int movieIndex, int showtimeIndex)
{
    char seatRow;
    int seatCol;
    do
    {
        printf("\nSelect a seat row (A-E) of the ticket ");
        scanf(" %c",&seatRow);

        if(seatRow>='a' && seatRow<='e')
            seatRow -= 32;
        if(seatRow<'A' || seatRow>'E')
            printf("Invalid row! Choose A-E.\n");

    }while(seatRow<'A' || seatRow>'E');


    do
    {
        printf("Select a seat column (1-10) of the ticket ");
        if(scanf("%d",&seatCol)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            seatCol=0;
        }
        else if(seatCol<1 || seatCol>10)
        {
            printf("Column should be between 1 and 10.\n");
        }

    }while(seatCol<1 || seatCol>10);


    int row = seatRow - 'A';
    int col = seatCol - 1;


    if (movies[movieIndex][showtimeIndex].seats[row][col].booked == 0)
    {
        printf("\nSeat %c%d is not currently booked.\n", seatRow, seatCol);
    }
    else
    {
        removeDataFromArray(movieIndex,showtimeIndex,row,col);

        printf("\nBooking for seat %c%d has been cancelled successfully!\n",seatRow, seatCol);
    }

}




//Revenue Report


// Revenue Report - shows tickets sold and revenue per showtime, plus totals
void viewRevenueReport()
{
    float totalRevenue = 0.0;
    int totalTicketsSold = 0;

    printf("\n=====================================================================================\n");
    printf("                              REVENUE REPORT                                           \n");
    printf("=====================================================================================\n");
    printf("%-4s %-30s %-22s %-12s %-12s\n", "No.", "Movie Title", "Show Time", "Tickets", "Revenue");
    printf("=====================================================================================\n");

    int no = 1;

    for (int i = 0; i < MOVIES; i++)
    {
        for (int j = 0; j < SHOWTIMES; j++)
        {
            printf("%-4d %-30s %-22s %-12d Rs. %-8.2f\n",
                   no++,
                   movies[i][j].movieTitle,
                   movies[i][j].showTime,
                   movies[i][j].ticketsSold,
                   movies[i][j].revenue);

            totalTicketsSold += movies[i][j].ticketsSold;
            totalRevenue += movies[i][j].revenue;
        }
    }

    printf("=====================================================================================\n");
    printf("%-4s %-30s %-22s %-12d Rs. %-8.2f\n",
           "", "TOTAL", "", totalTicketsSold, totalRevenue);
    printf("=====================================================================================\n");
}

void clearScreen()
{
    system("cls");
}

void exitProgram()
{
    printf("----------------------------------------\n");
    printf("        Lights Camera Goodbye!     \n");
    printf("----------------------------------------\n");
    printf(" Thanks for choosing our booking system.\n");
    printf("----------------------------------------\n");

    exit(0);
}


//Post action menu
int PostActionMenu()
{
    int choice;

    do
    {
        printf("\n-----------------------------------\n");
        printf("    1. Back to Main Menu\n");
        printf("    2. Exit\n");
        printf("-----------------------------------\n");
        printf("Enter your choice: ");

        if(scanf("%d",&choice)!=1)
        {
            printf("Invalid input!\n");
            while(getchar()!='\n');
            choice=0;
        }
        else if (choice != 1 && choice != 2)
        {
            printf("Invalid input. Please enter 1 or 2.\n");
        }

    }while(choice<1 || choice>2);
    clearScreen();
    return (choice == 1) ? 1 : 0;
}
