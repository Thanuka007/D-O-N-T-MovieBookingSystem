// operations for booking,canceling & searching  seats go here
#include <stdio.h>
#include <string.h>
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


int isSeatAvailable(int movieIndex,int showtimeIndex,int row,int col)
{
    return movies[movieIndex][showtimeIndex].seats[row][col].booked == 1;
}
