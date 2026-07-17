#include <string.h>

#define MOVIES 5
#define SHOWTIMES 2
#define ROWS 5
#define COLS 10

void initializeDataToMoviesArray();

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

void initializeDataToMoviesArray()
{
    // Initialize the movie titles
    strcpy(movies[0][0].movieTitle, "Avengers: Endgame");
    strcpy(movies[0][1].movieTitle, "Avengers: Endgame");

    strcpy(movies[1][0].movieTitle, "Oppenheimer");
    strcpy(movies[1][1].movieTitle, "Oppenheimer");

    strcpy(movies[2][0].movieTitle, "Interstellar");
    strcpy(movies[2][1].movieTitle, "Interstellar");

    strcpy(movies[3][0].movieTitle, "Deadpool & Wolverine");
    strcpy(movies[3][1].movieTitle, "Deadpool & Wolverine");

    strcpy(movies[4][0].movieTitle, "The Batman");
    strcpy(movies[4][1].movieTitle, "The Batman");

    //initialize the show times
    for(int i = 0; i < MOVIES; i++)
    {
        strcpy(movies[i][0].showTime, "10:00 AM - 1:00 PM");
        strcpy(movies[i][1].showTime, "3:00 PM - 6:00 PM");
    }

    // Initialize the revenue and tickets sold for each movie show
    for(int i = 0; i < MOVIES; i++)
    {
        for(int j = 0; j < SHOWTIMES; j++)
        {
            movies[i][j].revenue = 0;
            movies[i][j].ticketsSold = 0;
        }
    }
    // Initialize the seat data for each movie show
    for(int i = 0; i < MOVIES; i++)
    {
        for(int j = 0; j < SHOWTIMES; j++)
        {
            for(int r = 0; r < ROWS; r++)
            {
                for(int c = 0; c < COLS; c++)
                {
                    movies[i][j].seats[r][c].booked = 0;
                    strcpy(movies[i][j].seats[r][c].customerName, "");


                    if(r < 2) // Regular
                    {
                        movies[i][j].seats[r][c].seatPrice = 500.0;
                    }
                    else if(r < 4) // Premium
                    {
                        movies[i][j].seats[r][c].seatPrice = 750.0;
                    }
                    else // VIP
                    {
                        movies[i][j].seats[r][c].seatPrice = 1000.0;
                    }


                    movies[i][j].seats[r][c].pricePaid = 0.0;
                }
            }
        }
    }
}





