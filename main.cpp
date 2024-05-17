#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib> //for rand
#include <ctime>   //for time
#include "declarations.h"

int main() {

  std::string guessList[6] = {};
  std::string enter = "y";
  while (enter == "y" || enter == "Y") {
    std::string guess = " ", enter = "y";
    int count = 0, index = rand() % 20;
    bool truth = true;
    std::string choose[20] = {"plays", "homes", "zebra", "house", "grade", "tiger", "loose", "moose", "ghost", "gross","mouse","knife","night","dance","froze","gnome","boots","slant", "moles", "grain"};

    //std::string word = "boots"; testing feature
    std::string word = ranb_word();

    std::cout << "\nWelcome to "
              << "\x1b[36m" << "W"
              << "\x1b[35m" << "o"
              << "\x1b[34m" << "r"
              << "\x1b[33m" << "d"
              << "\x1b[32m" << "l"
              << "\x1b[31m" << "e"
              << "\x1b[30m" << "!\n"
              << RESET
              << std::endl;

    std::cout
      << "You have 6 tries to guess the word. \nA "
      << RED << "red" << RESET
      << " letter means the letter is incorrect. \nA "
      << YELLOW << "yellow" << RESET
      << " letter means the letter is in the word but in the wrong position. \nA "
      << GREEN << "green" << RESET
      << " letter means the letter is in the correct position."
      << std::endl << std::endl;

    //std::cout << word << std::endl; testing

    while (truth) {

      std::cout << "Guess the word: ";
      getline(std::cin, guess);
      if (guess.length() != 5) {
        std::cout << "Only 5 letters, retry: ";
        continue;
      }

      std::cout << CLEAR;

      guessList[count] = guess;

      bool correct = true;

      for (int i = 0; i <= count; i++) {
        if (i == count) {
          std::string currentWord = word; // Store the current word in a separate variable
          std::string currentGuess = guessList[i]; // Store the current guess in a separate variable
          std::string colorDisplay = ""; // String to store the colors for display

          for (int x = 0; x < currentGuess.length(); x++) {
            std::size_t charchek = currentWord.find(currentGuess[x]);
            if (currentGuess[x] == currentWord[x]) {
              colorDisplay += GREEN + std::string(1, currentGuess[x]) + RESET + " ";
            }
            else if (charchek != std::string::npos) {
              colorDisplay += YELLOW + std::string(1, currentGuess[x]) + RESET + " ";
              correct = false;
            }
            else {
              colorDisplay += RED + std::string(1, currentGuess[x]) + RESET + " ";
              correct = false;
            }
          }

          std::cout << colorDisplay << std::endl;
        }
        else {
          std::string currentGuess = guessList[i]; // Store the current guess in a separate variable
          std::string currentWord = word; // Store the current word in a separate variable
          std::string colorDisplay = ""; // String to store the colors for display

          for (int x = 0; x < currentGuess.length(); x++) {
            std::size_t finder = currentWord.find(currentGuess[x]);

            if (currentGuess[x] == currentWord[x]) {
              colorDisplay += GREEN + std::string(1, currentGuess[x]) + RESET + " ";
            }
            else if (finder != std::string::npos && int(finder) == x) {
              colorDisplay += YELLOW + std::string(1, currentGuess[x]) + RESET + " ";
            }
            else {
              colorDisplay += RED + std::string(1, currentGuess[x]) + RESET + " ";
            }
          }

          std::cout << colorDisplay << std::endl;
        }
      }
      std::cout << std::endl;

      if (correct) {
        std::cout << "Correct, Game Over\n" << std::endl;
        truth = false;
        std::cout << "Do you want to play again? (Y/N): ";
        getline(std::cin, enter);
        if (enter == "y" || enter == "Y") {
          break;
        }
        else {
          std::cout << "Have a good day" << std::endl;
          exit(0);
        }
      }

      count++;

      if (count == 6) {
        std::cout << "Out of attempts, the word was: " << word << std::endl;
        truth = false;
        std::cout << "Do you want to try again (Y/N): ";
        getline(std::cin, enter);
        if (enter == "y" || enter == "Y") {
          break;
        }
        else {
          std::cout << "Have a good day";
          exit(0);
        }
      }
    }
  }
}
