#include <stdio.h>
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

typedef struct {
    char movieTitle[50];
    char showTime[20];
    Seat seats[ROWS][COLS];
    float revenue;
    int ticketsSold;
} MovieShow;

MovieShow movies[MOVIES][SHOWTIMES];


void initializeDataToMoviesArray();
void viewShowtimes(MovieShow movies[MOVIES][SHOWTIMES]);
void viewSeatMap(int movieIndex, int showtimeIndex);
void bookSeat(char seatRow, int seatColumn,int movieIndex, int showtimeIndex);
void cancelBooking(char seatRow, int seatColumn, int movieIndex, int showtimeIndex);


int main() {

    initializeDataToMoviesArray();
    return 0;
}
