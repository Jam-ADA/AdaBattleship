#pragma once

#include <vector>
#include "Config.h"
using namespace std;

vector<vector<char>> constructBoard(Config config);
void displayBoard(vector<vector<char>> board);
vector<vector<char>> playerPlace(Config config, vector<vector<char>> board, int shipLength, char shipType);
vector<vector<char>> setupVSComp();