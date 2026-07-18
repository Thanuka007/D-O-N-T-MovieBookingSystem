// operations for booking,canceling & searching  seats go here
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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


bool isSeatAvailable(int movieIndex,int showtimeIndex,int row,int col)
{
    return movies[movieIndex][showtimeIndex].seats[row][col].booked == 1;
}

void addDataToArray(int movieIndex,int showtimeIndex,int row,int col, char userName[50], float finalPrice)
{
    //update seat data
    movies[movieIndex][showtimeIndex].seats[row][col].booked = 1;
    strcpy(movies[movieIndex][showtimeIndex].seats[row][col].customerName, userName);
    movies[movieIndex][showtimeIndex].seats[row][col].pricePaid = finalPrice;

    // Update movie show totals
    movies[movieIndex][showtimeIndex].ticketsSold++;
    movies[movieIndex][showtimeIndex].revenue += finalPrice;
}

void removeDataFromArray(int movieIndex,int showtimeIndex,int row,int col,float paidPrice)
{
    //update seat data
    movies[movieIndex][showtimeIndex].seats[row][col].booked = 0;
    strcpy(movies[movieIndex][showtimeIndex].seats[row][col].customerName," ");
    movies[movieIndex][showtimeIndex].seats[row][col].pricePaid = 0.0;

    // Update movie show totals
    movies[movieIndex][showtimeIndex].ticketsSold--;
    movies[movieIndex][showtimeIndex].revenue -= paidPrice;
}
