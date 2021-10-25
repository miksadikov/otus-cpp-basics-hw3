#include <cstdlib>
#include <ctime>
#include <iostream>

#include "high_scores.h"

int main(int argc, char** argv) {
  int max_value = 100;
  const std::string high_scores_filename = "high_scores.txt";
  int current_value = 0;
  int attempts_count = 0;
  bool not_win = true;
  
  if (argc >= 2) {	
    std::string arg1_value{argv[1]};
    if (arg1_value != "-max") {
      std::cout << "Error: unknown command line argument: " << arg1_value << std::endl; 
      return -1;
    } else {
      if (argc < 3) {
        std::cout << "Error: the argument '-max' requires some value!" << std::endl;
		return -1;
	  }
	}
	max_value = std::stoi(argv[2]);
  }

  std::srand(
      std::time(nullptr));  // use current time as seed for random generator

  const int target_value = std::rand() % max_value;

  // Ask about name
  std::cout << "Hi! Enter your name, please:" << std::endl;
  std::string user_name;
  std::cin >> user_name;

  std::cout << "Enter your guess:" << std::endl;

  do {
    std::cin >> current_value;

    if (current_value < target_value) {
      std::cout << "greater than " << current_value << std::endl;
      attempts_count++;
    } else if (current_value > target_value) {
      std::cout << "less than " << current_value << std::endl;
      attempts_count++;
    } else {
      std::cout << "you win! attempts = " << attempts_count <<  std::endl;
      if (saveAttemptsCount(high_scores_filename, user_name, attempts_count)) {
        return -1;
      }
      if (printHighScores(high_scores_filename) < 0) {
        return -1;
      }
      break;
    }

  } while (true);

  return 0;
}
