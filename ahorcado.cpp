#include <iostream>

using namespace std;

const int maxLength = 20;

void printWord(char guessedWord[], int length) {
  for (int i = 0; i < length; i++) {
    cout << guessedWord[i] << " ";
  }
  cout << endl << endl;
}

void printProgress(int lives) {
  cout << "Lives: ";
  for (int i = 0; i < lives; i++) {
    cout << "❤️ ";
  }
  cout << endl << endl;
  if (lives == 4) {
    cout << "   ______" << endl;
    cout << "   |    |" << endl;
    cout << "   |    |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "________|______" << endl;
    cout << endl;
  }
  if (lives == 3) {
    cout << "   ______" << endl;
    cout << "   |    |" << endl;
    cout << "   |    |" << endl;
    cout << "  (_)   |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "        |" << endl;
    cout << "________|______" << endl;
    cout << endl;
  }
  if (lives == 2) {
    cout << "   ______" << endl;
    cout << "   |    |" << endl;
    cout << "   |    |" << endl;
    cout << "  (_)   |" << endl;
    cout << "   |    |" << endl;
    cout << "   |    |" << endl;
    cout << "        |" << endl;
    cout << "________|______" << endl;
    cout << endl;
  }
  if (lives == 1) {
    cout << "   ______" << endl;
    cout << "   |    |" << endl;
    cout << "   |    |" << endl;
    cout << "  (_)   |" << endl;
    cout << "  /|\\   |" << endl;
    cout << "   |    |" << endl;
    cout << "        |" << endl;
    cout << "________|______" << endl;
    cout << endl;
  }
  if (lives == 0) {
    cout << "   ______" << endl;
    cout << "   |    |" << endl;
    cout << "   |    |" << endl;
    cout << "  (_)   |" << endl;
    cout << "  /|\\   |" << endl;
    cout << "   |    |" << endl;
    cout << "  / \\   |" << endl;
    cout << "________|______" << endl;
    cout << endl;
  }
}

bool verifyTry(char guess, char (&guessedWord)[maxLength], int length, string word) {
  bool correct = false;
  for (int i = 0; i < length; i++) {
    if (guessedWord[i] == toupper(guess)) {
      return true;
    }
    if (toupper(word[i]) == toupper(guess)) {
      guessedWord[i] = toupper(guess);
      correct = true;
    }
  }
  return correct;
}

bool verifyWin(char (&guessedWord)[20], int length) {
  for (int i = 0; i < length; i++) {
    if (guessedWord[i] == '_') {
      return false;
    }
  }
  return true;
}

int main() {
  string word;
  int lives = 4;

  system("clear");
  cout << "Enter a word to start the game: ";
  cin >> word;

  char guessedWord[maxLength];
  int length = 0;
  for (auto i : word) {
    length++;
  }

  for (int i = 0; i < length; i++) {
    guessedWord[i] = '_';
  }

  while (lives > 0) {
    bool win = false;
    bool correctTry = true;
    char guess;

    system("clear");
    printProgress(lives);
    printWord(guessedWord, length);

    cout << "Enter a letter: ";
    cin >> guess;
    correctTry = verifyTry(guess, guessedWord, length, word);
    win = verifyWin(guessedWord, length);

    if (win) {
      system("clear");
      printProgress(lives);
      printWord(guessedWord, length);
      cout << "You win" << endl;
      break;
    }
    if (!correctTry) {
      lives -= 1;
    }
    if (lives == 0) {
      system("clear");
      printProgress(lives);
      printWord(guessedWord, length);
      cout << "You lost" << endl;
      cout << "The word was: " << word << endl;
    }
  }

  cout << endl << "Game over" << endl;
}