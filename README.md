# Movie Ticket Booking System

A command-line Movie Ticket Booking System developed in **C**. The system allows users to manage movie ticket bookings, view seat availability, calculate ticket prices with discounts, search bookings, cancel reservations, and generate revenue reports.

---

## Features

- View available movies and showtimes
- Display seat map (Available/Booked seats)
- Book one or multiple seats
- Student Discount (10%)
- Senior Citizen Discount (20%)
- Group Discount (10% for 4 or more seats)
- Cancel booked seats
- Search bookings by customer name or seat number 
- Revenue report for each showtime
- Input validation to prevent invalid bookings
- Prevent booking already reserved seats
- Prevent cancellation of unbooked seats

---

# 📷 Program Preview

## Main Menu

<img width="322" height="249" alt="Main Menu" src="https://github.com/user-attachments/assets/cfe3be8a-db6b-485a-bee3-979d5e1f009f" />


---

## View Showtimes

<img width="637" height="289" alt="Showtimes" src="https://github.com/user-attachments/assets/6a90bc25-1d10-4273-902a-e23c23aac46f" />


---

## Seat Map

<img width="572" height="251" alt="Seat Map" src="https://github.com/user-attachments/assets/f528030a-11ec-4a2d-b691-6423968ddd76" />


---


## Successful Seat Booking

<img width="362" height="341" alt="Booking a Ticket" src="https://github.com/user-attachments/assets/15648a7b-794e-450c-a830-287503fa04d8" />


---

## Search Booking

<img width="367" height="130" alt="Search Booking" src="https://github.com/user-attachments/assets/f240773e-ce4a-47e1-95de-e90ef51c2db9" />


---

## Revenue Report

<img width="609" height="261" alt="Revenue Report" src="https://github.com/user-attachments/assets/1f41dfe9-acaf-4dad-8175-6a9df82605a8" />


---

## Technologies Used

- C Programming Language
- GCC Compiler
- Command Line Interface (CLI)

---

## Project Structure

```
MovieBookingSystem/
│
├── main.c          # Program entry point
├── booking.c       # Booking, cancellation and search operations
├── pricing.c       # Ticket pricing and discount calculations
├── display.c       # User interface and display functions
├── data.c          # Movie and seat data initialization
└── README.md
```

---

## How to Compile

Using GCC:

```bash
gcc *.c -o booking
```

Or

```bash
gcc main.c booking.c pricing.c display.c data.c -o booking
```

---

## How to Run

Windows

```bash
booking.exe
```

---

## Ticket Pricing

| Seat Tier | Rows  | Price    |
|-----------|-------|----------|
| Regular   | A - B | Rs. 500  |
| Premium   | C - D | Rs. 750  |
| VIP       | E     | Rs. 1000 |

### Available Discounts

- Student Discount → **10%**
- Senior Citizen Discount → **20%**
- Group Discount → **10%** (4 or more seats)

> Group discounts can be combined with Student or Senior discounts.

---

## Menu

```
1. View Showtimes
2. View Seat Map
3. Book a Seat
4. Cancel a Booking
5. Search Booking
6. View Revenue Report
7. Exit
```

---

## Input Validation

The program validates user input by:

- Preventing booking of already reserved seats
- Preventing cancellation of unbooked seats
- Preventing seat selections outside the valid range
- Handling invalid input without crashing
- Updating revenue correctly after booking or cancellation

---

## Revenue Tracking

The system keeps track of:

- Total tickets sold
- Total revenue per showtime
- Revenue updates after cancellations

---

## Authors
- [Omira Karannagoda](https://github.com/omiragk05)
- [Dinuka Gunawardana](https://github.com/senathx-web)
- [Thanuka Gunawardhana](https://github.com/Thanuka007)
- [Nisandi Kumarage](https://github.com/nishukumarage2025-droid)
