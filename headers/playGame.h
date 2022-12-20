#pragma once

#include <vector>
#include "Config.h"
using namespace std;

vector<vector<char>> constructBoard(Config config);
void displayBoard(vector<vector<char>> board);
vector<vector<char>> playerPlace(Config config, vector<vector<char>> board, int shipLength, char shipType);
vector<vector<char>> computerPlace(Config config, vector<vector<char>> board, int shipLength, char shipType);
vector<vector<vector<char>>> playerAttack(vector<vector<char>> target, vector<vector<char>> board);

vector<vector<vector<char>>> computerAttack(vector<vector<char>> target, vector<vector<char>> board);
void playVSComp();
