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
void printSearchedBookings(char movieTitle[50], char showTime[20], char customerName[50],
                           char seatRow,int seatColumn, float pricePaid);
char getSeatRowChar(int rowNumber);

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

//cancel booking
void removeDataFromArray(int movieIndex,int showtimeIndex,int row,int col)
{

    // Update movie show totals
    movies[movieIndex][showtimeIndex].ticketsSold--;
    movies[movieIndex][showtimeIndex].revenue -= movies[movieIndex][showtimeIndex].seats[row][col].pricePaid;

    //update seat data
    movies[movieIndex][showtimeIndex].seats[row][col].booked = 0;
    strcpy(movies[movieIndex][showtimeIndex].seats[row][col].customerName,"");
    movies[movieIndex][showtimeIndex].seats[row][col].pricePaid = 0.0;
}


int searchByName(char searchName[])
{
    int found = 0;

    for (int i = 0; i < MOVIES; i++)
    {
        for (int j = 0; j < SHOWTIMES; j++)
        {
            for (int row = 0; row < ROWS; row++)
            {
                for (int col = 0; col < COLS; col++)
                {
                    if (movies[i][j].seats[row][col].booked
                        && strcmp(movies[i][j].seats[row][col].customerName, searchName) == 0)
                    {
                        printSearchedBookings(movies[i][j].movieTitle, movies[i][j].showTime,
                                      movies[i][j].seats[row][col].customerName,
                                     getSeatRowChar(row+1),col+1,movies[i][j].seats[row][col].pricePaid);

                        found = 1;
                    }
                }
            }
        }
    }
    return found;

}

//return Seat letter from Number
char getSeatRowChar(int rowNumber)
{
    switch(rowNumber)
    {
        case 1: return 'A'; break;
        case 2: return 'B'; break;
        case 3: return 'C'; break;
        case 4: return 'D'; break;
        case 5: return 'E'; break;
        default: return ' ';
    }

}



//search by number
int searchByNumber(char seatRow, int seatColumn)
{
    int row = seatRow - 'A';
    int col = seatColumn - 1;
    int found = 0;

    for (int i = 0; i < MOVIES; i++)
    {
        for (int j = 0; j < SHOWTIMES; j++)
        {
            if (movies[i][j].seats[row][col].booked)
            {
                printSearchedBookings(movies[i][j].movieTitle, movies[i][j].showTime,
                                      movies[i][j].seats[row][col].customerName,
                                     seatRow,seatColumn,movies[i][j].seats[row][col].pricePaid);

                found = 1;
            }
        }
    }

    return found;
}
