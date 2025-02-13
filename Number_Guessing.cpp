#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function to display the game instructions to the player
void display_instructions() {
    cout << "\n=== Number Guessing Game ===\n";
    cout << "Instructions:\n";
    cout << "1. The program will generate a random number between 1 and 100.\n";
    cout << "2. You need to guess the correct number.\n";
    cout << "3. If your guess is too low or too high, you will be prompted accordingly.\n";
    cout << "4. The game continues until you guess the correct number.\n";
    cout << "5. Type '0' to exit the game.\n\n";
}

// Function to execute the main logic of the number guessing game
void number_guessing_game() {
    srand(time(0)); // Seed random number generator
    int number_to_guess = rand() % 100 + 1; // Generate random number between 1 and 100
    int user_guess = -1;
    int attempts = 0;
    
    display_instructions(); // Show game instructions
    cout << "Guess a number between 1 and 100." << endl;
    
    while (user_guess != number_to_guess) {
        cout << "Enter your guess: ";
        cin >> user_guess;
        
        // Handle invalid input
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a valid number." << endl;
            continue;
        }
        
        // Allow user to exit the game
        if (user_guess == 0) {
            cout << "You have exited the game. The correct number was " << number_to_guess << "." << endl;
            return;
        }
        
        attempts++; // Increase attempt counter
        
        // Provide hints to the user
        if (user_guess < number_to_guess) {
            cout << "Too low! Try again." << endl;
        } else if (user_guess > number_to_guess) {
            cout << "Too high! Try again." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts." << endl;
        }
    }
}

// Main function that starts and manages the game loop
int main() {
    char play_again;
    do {
        number_guessing_game(); // Start the game
        cout << "\nWould you like to play again? (y/n): ";
        cin >> play_again;
        
        // Validate user input for replay option
        while (play_again != 'y' && play_again != 'n') {
            cout << "Invalid input! Please enter 'y' to play again or 'n' to exit: ";
            cin >> play_again;
        }
    } while (play_again == 'y'); // Loop if user chooses to play again
    
    cout << "Thank you for playing! Goodbye." << endl;
    return 0;
}

