#include "../headers/main.h"
using namespace std;

void displayMenu() {
  int selected = 0;
  char input;
  while (true) {
    cout << CONSOLE_CLEAR;
    /*
    cout << "           _____           _____ _     _       " << endl;
    cout << "     /\   |  __ \   /\    / ____| |   (_)      " << endl;
    cout << "    /  \  | |  | | /  \  | (___ | |__  _ _ __  " << endl;
    cout << "   / /\ \ | |  | |/ /\ \  \___ \| '_ \| | '_ \ " << endl;
    cout << "  / ____ \| |__| / ____ \ ____) | | | | | |_) |" << endl;
    cout << " /_/    \_\_____/_/    \_\_____/|_| |_|_| .__/ " << endl;
    cout << "                                        | |    " << endl;
    cout << "                                        |_|    " << "\n\n" << endl;
    */

    cout << "\nWelcome to ADAShip! Please select an option using arrow keys and "
            "enter:\n"
         << endl;
    if (selected == 0) {
      cout << FG_GREEN << "1) Player vs Computer" << COLOUR_RESET << endl;
    } else {
      cout << "1) Player vs Computer" << endl;
    }
    if (selected == 1) {
      cout << FG_GREEN << "2) Player vs Player" << COLOUR_RESET << endl;
    } else {
      cout << "2) Player vs Player" << endl;
    }
    if (selected == 2) {
      cout << FG_GREEN << "3) Quit" << COLOUR_RESET << endl;
    } else {
      cout << "3) Quit" << endl;
    }
    input = getch();

    if (input == '\033') {
      getch();
      switch (getch()) {
      case 'A':
        if (selected == 0) {
          selected = 2;
        } else {
          selected--;
        }
        break;
      case 'B':
        if (selected == 2) {
          selected = 0;
        } else {
          selected++;
        }
      }
    } else if (input == '\n') {
      switch (selected) {
      case 0:
        setupVSComp();
        break;
      case 1:
        cout << "PLAY GAME VS PLAYER";
        break;
      case 2:
        cout << "QUIT";
        return;
        break;
      }
    }
  }
}