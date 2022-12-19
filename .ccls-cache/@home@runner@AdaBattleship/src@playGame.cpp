#include "../headers/main.h"
using namespace std;

vector<vector<char>> constructBoard(Config config) {
  vector<vector<char>> board;
  for(int x = 0; x < config.BoardX; x++) {
    vector<char> column;
    for(int y = 0; y < config.BoardY; y++) {
      column.push_back('.');
    }
    board.push_back(column);
  }
  return board;
}

void displayBoard(vector<vector<char>> board) {
  cout << "\nYour Board:" << endl;;
  for(int y = 0; y < board[0].size(); y++) {
    string lineToDisplay;
    for(int x = 0; x < board.size(); x++) {
      if(board[x][y] == '.') {
        lineToDisplay += BG_BLUE + ". " + COLOUR_RESET;
      } else if (board[x][y] == 'C') {
        lineToDisplay += BG_MAGENTA + "C " + COLOUR_RESET;
      } else if (board[x][y] == 'B') {
        lineToDisplay += BG_MAGENTA + "B " + COLOUR_RESET;
      } else if (board[x][y] == 'D') {
        lineToDisplay += BG_MAGENTA + "D " + COLOUR_RESET;
      } else if (board[x][y] == 'S') {
        lineToDisplay += BG_MAGENTA + "S " + COLOUR_RESET;
      } else if (board[x][y] == 'P') {
        lineToDisplay += BG_MAGENTA + "P " + COLOUR_RESET;
      }
    }
    cout << lineToDisplay << endl;
  }
  cout << "\nUse Arrow Keys To Move and R To Rotate Ship" << endl;
  cout << "Press enter to confirm selection" << endl;
  cout << "C - Carrier\nB - Battleship\nD - Destroyer\nS - Submarine\nP - Patrol";
  
}

vector<vector<char>> playerPlace(Config config, vector<vector<char>> board, int shipLength, char shipType) {
  bool placed = false;
  int posX = 2;
  int posY = 2;
  vector<vector<char>> originalBoard = board;
  bool rotated = false;
  char input;
  bool canPlace = false;
  while(placed != true) {
    cout << CONSOLE_CLEAR;
    canPlace = true;
    board = originalBoard;
    for(int l = 0; l < shipLength; l++) {
      if(rotated == true) {
        if(board[posX + l][posY]) {
          if(board[posX + l][posY] == '.') {
            board[posX + l][posY] = shipType;
          } else {
            canPlace = false;
          }
        }
      } else if(rotated == false) {
        if(board[posX][posY + l]) {
          if(board[posX][posY + l] == '.') {
            board[posX][posY + l] = shipType;
          } else {
            canPlace = false;
          }
        }
      }  
    }
    displayBoard(board);
    input = getch();
    if (input == '\033') {
      getch();
      switch (getch()) {
      case 'A':
        if(board[posX][posY - 1]) {
          posY--;
        }
        break;
      case 'B':
        posY++;
        break;
      case 'C':
        posX++;
        break;
      case 'D':
        posX--;
        break;
      } 
    } else if (input == '\n') {
      if(canPlace == true) {
        return board;
      } else {
        cout << "\nCan't Place There!" << endl;
        sleep(2);
      }
    } else if (input == 'r') {
      if(rotated) {
        rotated = false;
      } else {
        rotated = true;
      }
    }
    
  }
}

vector<vector<char>> setupVSComp() {
  Config config;
  vector<vector<char>> playerBoard = constructBoard(config);
  vector<vector<char>> computerBoard = constructBoard(config);
  playerBoard = playerPlace(config, playerBoard, config.BoatCarrier, 'C');
  playerBoard = playerPlace(config, playerBoard, config.BoatBattleship, 'B');
  playerBoard = playerPlace(config, playerBoard, config.BoatDestroyer, 'D');
  playerBoard = playerPlace(config, playerBoard, config.BoatSubmarine, 'S');
  playerBoard = playerPlace(config, playerBoard, config.BoatPatrol, 'P');
  
}

vector<vector<char>> computerPlace(Config config, vector<vector<char>> board, int shipLength, char shipType) {
  bool placed = false;
  int posX;
  int posY;
  vector<vector<char>> originalBoard = board;
  bool rotated = false;
  char input;
  bool canPlace = false;
  while(placed != true) {
    cout << CONSOLE_CLEAR;
    canPlace = true;
    board = originalBoard;
    for(int l = 0; l < shipLength; l++) {
      if(rotated == true) {
        if(board[posX + l][posY]) {
          if(board[posX + l][posY] == '.') {
            board[posX + l][posY] = shipType;
          } else {
            canPlace = false;
          }
        }
      } else if(rotated == false) {
        if(board[posX][posY + l]) {
          if(board[posX][posY + l] == '.') {
            board[posX][posY + l] = shipType;
          } else {
            canPlace = false;
          }
        }
      }  
    }
  }
}
  
