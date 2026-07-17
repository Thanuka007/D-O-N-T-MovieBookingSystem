#define MOVIES 5
#define SHOWTIMES 2
#define ROWS 6
#define COLS 10

// Define all the structs

//Hard coded movie list


// Avengers: Endgame | Show time :10.00 am to 1.00 pm and 3.00 pm to 6.00 pm
// Oppenheimer       | Show time :10.00 am to 1.00 pm and 3.00 pm to 6.00 pm
// Interstellar      | Show time :10.00 am to 1.00 pm and 3.00 pm to 6.00 pm
// Deadpool & Wolverine | Show time :10.00 am to 1.00 pm and 3.00 pm to 6.00 pm
// The Batman        | Show time :10.00 am to 1.00 pm and 3.00 pm to 6.00 pm

//Seat pricing list

//Regular (Rows 1-2) Rs. 500
//Premium (Rows 3-4) Rs. 750
//VIP (Row 5)        Rs. 1000




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





