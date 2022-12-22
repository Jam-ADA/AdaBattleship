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
  cout << endl;
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
      } else if (board[x][y] == 'x') {
        lineToDisplay += BG_BLUE + "x " + COLOUR_RESET;
      } else if (board[x][y] == 'X') {
        lineToDisplay += BG_RED + "X " + COLOUR_RESET;
      } else if (board[x][y] == '+') {
        lineToDisplay += BG_CYAN + "+ " + COLOUR_RESET;
      }
    }
    cout << lineToDisplay << endl;
  }
  cout << "\nUse Arrow Keys To Move Ship/Target And Press R To Rotate Ship" << endl;
  cout << "Press enter to confirm selection/attack" << endl;
  cout << "C - Carrier\nB - Battleship\nD - Destroyer\nS - Submarine\nP - Patrol\n\nX - Hit";
  
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
        } else {
          canPlace = false;
        }
      } else if(rotated == false) {
        if(board[posX][posY + l]) {
          if(board[posX][posY + l] == '.') {
            board[posX][posY + l] = shipType;
          } else {
            canPlace = false;
          }
        } else {
          canPlace = false;
        }
      }  
    }
    cout << endl << "Your Board:" << endl;
    displayBoard(board);
    input = getch();
    if (input == '\033') {
      getch();
      switch (getch()) {
      case 'A':
        if(posY - 1 >= 0 && posY < board[1].size()) {
          posY--;
        }
        break;
      case 'B':
        if(posY >= 0 && posY + 1 < board[1].size()) {
          posY++;
        }
        break;
      case 'C':
        if(rotated) {
          if(posX >= 0 && posX + 1 < board.size() - shipLength + 1) {
            posX++;
          }
        } else if(posX >= 0 && posX + 1 < board.size()) {
          posX++;
        }
        break;
      case 'D':
        if(posX - 1 >= 0 && posX < board.size()) {
          posX--;
        }
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
        if(posX > board.size() - shipLength) {
          posX = posX - shipLength;
        }
        rotated = true;
      }
    }
    
  }
}



vector<vector<char>> computerPlace(Config config, vector<vector<char>> board, int shipLength, char shipType) {
  bool placed = false;
  int posX = randomInt(0,board.size());
  int posY = randomInt(0,board[0].size());
  vector<vector<char>> originalBoard = board;
  bool rotated = false;
  bool canPlace = false;
  while(placed != true) {
    board = originalBoard;
    posX = randomInt(0,board.size());
    sleep(1);
    posY = randomInt(0,board[0].size());
    if(randomInt(0,1) == 1) {
      rotated = true;
    } else {
      rotated = false;
    }
    canPlace = true;
    for(int l = 0; l < shipLength; l++) {
      if(rotated == true) {
        if(posX + l < config.BoardX && posY < config.BoardY) {
          if(board[posX + l][posY] == '.') {
            board[posX + l][posY] = shipType;
          } else {
            canPlace = false;
          }
        } else {
          canPlace = false;
        }
      } else if(rotated == false) {
        if(posX < config.BoardX && posY+ l < config.BoardY) {
          if(board[posX][posY + l] == '.') {
            sleep(1);
            board[posX][posY + l] = shipType;
          } else {
            canPlace = false;
          }
        } else {
          canPlace = false;
        }
      }  
    }
    if(canPlace == true) {
      return board;
    }
  }
}

vector<vector<vector<char>>> computerAttack(vector<vector<char>> target, vector<vector<char>> board) {
  vector<vector<char>> originalTarget = target;
  int targetX = randomInt(0,board.size());
  int targetY = randomInt(0,board[1].size());
  char hit;
  vector<vector<vector<char>>> affectedBoards;
  while(true) {
    targetX = randomInt(0,board.size() - 1);
    sleep(1);
    targetY = randomInt(0,board[1].size() - 1);
    target = originalTarget;
    target[targetX][targetY] = '+';
    sleep(1);
    cout << "Computer's target board:" << endl;
    displayBoard(target);
    if(target[targetX][targetY] != 'x' && target[targetX][targetY] != 'X') {
      hit = board[targetX][targetY];
        if(hit == '.') {
          board[targetX][targetY] = 'x';
          target[targetX][targetY] = 'x';
          affectedBoards = {target, board};
          return affectedBoards;
        } else if(hit == 'C' || hit == 'B' || hit == 'D' || hit == 'S' || hit == 'P'){
            board[targetX][targetY] = 'X';
            target[targetX][targetY] = 'X';
            affectedBoards = {target, board};
            return affectedBoards;
        }
      } 
    
    }
}


vector<vector<vector<char>>> playerAttack(vector<vector<char>> target, vector<vector<char>> board) {
  vector<vector<char>> originalTarget = target;
  int targetX = 2;
  int targetY = 2;
  char input;
  char hit;
  vector<vector<vector<char>>> affectedBoards;
  while(true) {
    cout << CONSOLE_CLEAR;
    target = originalTarget;
    target[targetX][targetY] = '+';
    cout << "Your target board:" << endl;
    displayBoard(target);
    input = getch();
    if (input == '\033') {
      getch();
      switch (getch()) {
      case 'A':
        if(targetY - 1 >= 0 && targetY < target[1].size()) {
          targetY--;
        }
        break;
      case 'B':
        if(targetY >= 0 && targetY + 1 < target[1].size()) {
          targetY++;
        }
        break;
      case 'C':
        if(targetX >= 0 && targetX + 1 < target[1].size()) {
          targetX++;
        }
        break;
      case 'D':
        if(targetX -1 >= 0 && targetX< target[1].size()) {
          targetX--;
        }
        break;
      } 
    } else if (input == '\n') {
      if(target[targetX][targetY] != 'x' && target[targetX][targetY] != 'X') {
        hit = board[targetX][targetY];
        if(hit == '.') {
          board[targetX][targetY] = 'x';
          target[targetX][targetY] = 'x';
          affectedBoards = {target, board};
          return affectedBoards;
        } else if(hit == 'C' || hit == 'B' || hit == 'D' || hit == 'S' || hit == 'P') {
            board[targetX][targetY] = 'X';
            target[targetX][targetY] = 'X';
            affectedBoards = {target, board};
            return affectedBoards;
          }
      }
      cout << "Can't fire there!" << endl;
      sleep(1);
      cout << CONSOLE_CLEAR;
    }
    
    
  }
}

bool checkScore(vector<vector<char>> board) {
  int totalCount = 0;
  int carrier = 0;
  int battleship = 0;
  int destroyer = 0;
  int submarine = 0;
  int patrol = 0;
  char currentSquare;
  for(int y = 0; y < board[0].size(); y++) {
    for(int x = 0; x < board.size(); x++) {
        currentSquare = board[x][y];
        switch(currentSquare) {
          case 'C':
            carrier++;
            break;
          case 'B':
            battleship++;
            break;
          case 'D':
            destroyer++;
            break;
          case 'S':
            submarine++;
            break;
          case 'P':
            patrol++;
            break;
        }
      }
    }
    cout << "Ships left:" << endl;
    if(carrier > 0) {
      cout << "Carrier" << endl;
      totalCount++;
    } if(battleship > 0) {
      cout << "Battleship" << endl;
      totalCount++;
    } if(destroyer > 0) {
      cout << "Destroyer" << endl;
      totalCount++;
    } if(submarine > 0) {
      cout << "Submarine" << endl;
      totalCount++;
    } if(patrol > 0) {
      cout << "Patrol Ship" << endl;
      totalCount++;
    }
  cout << "Total ships: " << totalCount << endl;
  if(totalCount == 0) {
    return true;
    
  } else {
    return false;
  }
}

void playVSComp() {
  vector<vector<vector<char>>> affectedBoards;
  bool playing = true;
  bool playerWin = false;
  bool computerWin = false;
  Config config;
  vector<vector<char>> playerBoard = constructBoard(config);
  vector<vector<char>> computerBoard = constructBoard(config);
  vector<vector<char>> playerTarget = constructBoard(config);
  vector<vector<char>> computerTarget = constructBoard(config);
  playerBoard = playerPlace(config, playerBoard, config.BoatCarrier, 'C');
  playerBoard = playerPlace(config, playerBoard, config.BoatBattleship, 'B');
  playerBoard = playerPlace(config, playerBoard, config.BoatDestroyer, 'D');
  playerBoard = playerPlace(config, playerBoard, config.BoatSubmarine, 'S');
  playerBoard = playerPlace(config, playerBoard, config.BoatPatrol, 'P');
  cout << "\nComputer loading board..." << endl;
  computerBoard = computerPlace(config, computerBoard, config.BoatCarrier, 'C');
  computerBoard = computerPlace(config, computerBoard, config.BoatBattleship, 'B');
  computerBoard = computerPlace(config, computerBoard, config.BoatDestroyer, 'D');
  computerBoard = computerPlace(config, computerBoard, config.BoatSubmarine, 'S');
  computerBoard = computerPlace(config, computerBoard, config.BoatPatrol, 'P');
  cout << "Get Ready to play..." << endl;
  sleep(1);
  while(playing) {
    cout << CONSOLE_CLEAR;
    cout << endl << "Your turn..." << endl;
    sleep(1);
    cout << CONSOLE_CLEAR;
    affectedBoards = playerAttack(playerTarget, computerBoard);
    playerTarget = affectedBoards[0];
    computerBoard = affectedBoards[1];
    cout << CONSOLE_CLEAR;
    cout << "Your target board:" << endl;
    displayBoard(playerTarget);
    cout << "\nPress any key to continue...";
    getch();
    cout << CONSOLE_CLEAR << "\nComputer's turn...";
    sleep(1);
    cout << CONSOLE_CLEAR;
    affectedBoards = computerAttack(computerTarget, playerBoard);
    computerTarget = affectedBoards[0];
    playerBoard = affectedBoards[1];
    cout << CONSOLE_CLEAR;
    cout << "Computer's target board:" << endl;
    displayBoard(computerTarget);
    cout << "\n\nYour Board:\n";
    displayBoard(playerBoard);
    cout << "\nPress any key to continue...";
    getch();
    cout << CONSOLE_CLEAR << "\nYour Score:" << endl;
    playerWin = checkScore(playerBoard);
    cout << "\nPress any key to continue...";
    getch();
    cout << CONSOLE_CLEAR << "\nComputer Score:" << endl;
    computerWin = checkScore(computerBoard);
    cout << "\nPress any key to continue...";
    getch();
    cout << CONSOLE_CLEAR;
    if(playerWin == true) {
      cout << "THE PLAYER HAS WON!\n" << endl;
      cout << "\nPress any key to continue...";
      getch();
      playing = false;
    } else if(computerWin == true) {
      cout << "THE COMPUTER HAS WON!\n" << endl;
      cout << "\nPress any key to continue...";
      getch();
      playing = false;
    }
    
  }
}

void playVSplay() {
  vector<vector<vector<char>>> affectedBoards;
  bool playing = true;
  bool playerWin = false;
  bool computerWin = false;
  Config config;
  vector<vector<char>> player1Board = constructBoard(config);
  vector<vector<char>> player2Board = constructBoard(config);
  vector<vector<char>> player1Target = constructBoard(config);
  vector<vector<char>> player2Target = constructBoard(config);
  cout << "\nPlayer 1's turn..." << endl;
  cout << "Enter any key to continue..." << endl;
  player1Board = playerPlace(config, player1Board, config.BoatCarrier, 'C');
  player1Board = playerPlace(config, player1Board, config.BoatBattleship, 'B');
  player1Board = playerPlace(config, player1Board, config.BoatDestroyer, 'D');
  player1Board = playerPlace(config, player1Board, config.BoatSubmarine, 'S');
  player1Board = playerPlace(config, player1Board, config.BoatPatrol, 'P');
  cout << "\nPlayer 2's turn..." << endl;
  cout << "Enter any key to continue..." << endl;
  player2Board = playerPlace(config, player2Board, config.BoatCarrier, 'C');
  player2Board = playerPlace(config, player2Board, config.BoatBattleship, 'B');
  player2Board = playerPlace(config, player2Board, config.BoatDestroyer, 'D');
  player2Board = playerPlace(config, player2Board, config.BoatSubmarine, 'S');
  player2Board = playerPlace(config, player2Board, config.BoatPatrol, 'P');
  cout << "Get Ready to play..." << endl;
  sleep(1);
  while(playing) {
    cout << CONSOLE_CLEAR;
    cout << endl << "Player 1 turn..." << endl;
    sleep(1);
    cout << CONSOLE_CLEAR;
    affectedBoards = playerAttack(player1Target, player2Board);
    player1Target = affectedBoards[0];
    player2Board = affectedBoards[1];
    cout << CONSOLE_CLEAR;
    cout << "Player 1's target board:" << endl;
    displayBoard(player1Target);
    cout << "\nPress any key to continue...";
    getch();
    cout << CONSOLE_CLEAR << "\nPlayer 2's turn...";
    sleep(1);
    cout << CONSOLE_CLEAR;
    affectedBoards = playerAttack(player2Target, player1Board);
    player2Target = affectedBoards[0];
    player1Board = affectedBoards[1];
    cout << CONSOLE_CLEAR;
    cout << "Player 2's target board:" << endl;
    displayBoard(player2Target);
    cout << "\n\nPlayer 1's target board:\n";
    displayBoard(player1Target);
    cout << "\nPress any key to continue...";
    getch();
    cout << CONSOLE_CLEAR << "\nPlayer 1's Score:" << endl;
    playerWin = checkScore(player1Board);
    cout << "\nPress any key to continue...";
    getch();
    cout << CONSOLE_CLEAR << "\nPlayer 2's Score:" << endl;
    computerWin = checkScore(player2Board);
    cout << "\nPress any key to continue...";
    getch();
    cout << CONSOLE_CLEAR;
    if(playerWin == true) {
      cout << "THE PLAYER 1 HAS WON!\n" << endl;
      cout << "\nPress any key to continue...";
      getch();
      playing = false;
    } else if(computerWin == true) {
      cout << "THE PLAYER 2 HAS WON!\n" << endl;
      cout << "\nPress any key to continue...";
      getch();
      playing = false;
    }
    
  }
}
  
