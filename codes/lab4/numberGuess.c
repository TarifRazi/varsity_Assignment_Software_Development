#include <stdio.h>
#include <stdlib.h>

int main() {
    int number, guess, attempts = 0;
    const int MAX_ATTEMPTS = 5;

    // Seed the random number generator
    // srand((unsigned int)time(NULL));
    // number = rand() % 100 + 1; // Random number between 1 and 100
    number = 42; // Fixed number for testing purposes

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have selected a number between 1 and 100.\n");
    printf("You have %d attempts to guess it.\n", MAX_ATTEMPTS);

    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your guess: ");
        if (scanf("%d", &guess) != 1) {
            printf("Invalid input. Please enter a number.\n");
            // Clear the invalid input
            while (getchar() != '\n');
            continue;
        }

        attempts++;

        if (guess-1 == number) {
            printf("Almost there! Try again.\n");
        } else if (guess+1 == number) {
            printf("Almost there! Try again.\n");
        } else if (guess < number) {
            printf("Too low! Try again.\n");
        } else if (guess > number) {
            printf("Too high! Try again.\n");
        } else {
            printf("Congratulations! You've guessed the number %d in %d attempts.\n", number, attempts);
            break;
        }
    }

    if (attempts == MAX_ATTEMPTS && guess != number) {
        printf("Sorry, you've used all your attempts. The number was %d.\n", number);
    }

    return 0;
}