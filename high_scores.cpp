#include <fstream>
#include <iostream>
#include <string>

#include "high_scores.h"

// Write new high score to the records table
int saveAttemptsCount(const std::string filename, const std::string user,
                      const int count) {
  std::ofstream out_file{filename, std::ios_base::app};
  if (!out_file.is_open()) {
    std::cout << "Failed to open file for write: " << filename
              << "!" << std::endl;
    return -1;
  }
  // Append new results to the table:
  out_file << user << ' ';
  out_file << count;
  out_file << std::endl;

  return 0;
}

// Read the high score file and print all results
int printHighScores(const std::string filename) {
  std::ifstream in_file{filename};
  if (!in_file.is_open()) {
    std::cout << "Failed to open file for read: " << filename << "!"
              << std::endl;
    return -1;
  }

  std::cout << "High scores table:" << std::endl;

  std::string username;
  int high_score = 0;
  while (true) {
    // Read the username first
    in_file >> username;
    // Read the high score next
    in_file >> high_score;
    // Ignore the end of line symbol
    in_file.ignore();

    if (in_file.fail()) {
      break;
    }

    // Print the information to the screen
    std::cout << username << '\t' << high_score << std::endl;
  }
  return 0;
}