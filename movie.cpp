#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ROWS = 5;
const int NUM_COLS = 10;
const double TICKET_PRICE = 10.00;

void displayMenu();
void displaySeats(vector<vector<char>>& seats);
bool bookSeats(vector<vector<char>>& seats, int numSeats);
double calculateTotalCost(int numSeats);

int main() {
    vector<vector<char>> seats(NUM_ROWS, vector<char>(NUM_COLS, 'O')); 

    char choice;
    do {
        displayMenu();
        cin >> choice;

        switch(choice) {
            case '1':
                displaySeats(seats);
                break;
            case '2':
                int numSeats;
                cout << "Enter the number of seats to book: ";
                cin >> numSeats;
                if (bookSeats(seats, numSeats))
                    cout << "Seats booked successfully!\n";
                else
                    cout << "Failed to book seats. Please try again with a different number of seats.\n";
                break;
            case '3':
                cout << "Thank you for using our booking system. Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '3');

    return 0;
}

void displayMenu() {
    cout << "\nMovie Ticket Booking System\n";
    cout << "1. View available seats\n";
    cout << "2. Book seats\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}

void displaySeats(vector<vector<char>>& seats) {
    cout << "\nSeats\n";
    cout << "     ";
    for (int i = 1; i <= NUM_COLS; ++i) {
        cout << setw(3) << i;
    }
    cout << "\n";
    for (int i = 0; i < NUM_ROWS; ++i) {
        cout << "Row " << setw(2) << i + 1 << " ";
        for (int j = 0; j < NUM_COLS; ++j) {
            cout << setw(3) << seats[i][j];
        }
        cout << "\n";
    }
}

bool bookSeats(vector<vector<char>>& seats, int numSeats) {
    int count = 0;
    for (int i = 0; i < NUM_ROWS; ++i) {
        for (int j = 0; j < NUM_COLS; ++j) {
            if (seats[i][j] == 'O') {
                ++count;
                if (count == numSeats) {
                    for (int k = j - numSeats + 1; k <= j; ++k) {
                        seats[i][k] = 'X'; 
                    }
                    cout << "Your seats are booked. Enjoy the movie!\n";
                    cout << "Total cost: $" << calculateTotalCost(numSeats) << endl;
                    return true;
                }
            } else {
                count = 0;
            }
        }
        count = 0;
    }
    return false;
}

double calculateTotalCost(int numSeats) {
    return numSeats * TICKET_PRICE;
}
