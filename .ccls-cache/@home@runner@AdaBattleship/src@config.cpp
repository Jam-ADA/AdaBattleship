#include "../headers/main.h"
using namespace std;

Config::Config() {
  //Loads defaults incase config file doesn't have them
  BoardX = 10;
  BoardY = 10;
  BoatCarrier = 5;
  BoatBattleship = 4;
  BoatDestroyer = 3;
  BoatSubmarine = 3;
  BoatPatrol = 2;

  
  vector<vector<string>> configVector = getConfig();
  for(int c = 0; c < configVector.size(); c++) {
    if(configVector[c][0] == "BoardX") {
      BoardX = stoi(configVector[c][1]);
    } else if(configVector[c][0] == "BoardY") {
      BoardY = stoi(configVector[c][1]);
    } else if(configVector[c][0] == "BoatCarrier") {
      BoatCarrier = stoi(configVector[c][1]);
    } else if(configVector[c][0] == "BoatBattleship") {
      BoatBattleship = stoi(configVector[c][1]);
    } else if(configVector[c][0] == "BoatDestroyer") {
      BoatDestroyer = stoi(configVector[c][1]);
    } else if(configVector[c][0] == "BoatSubmarine") {
      BoatSubmarine = stoi(configVector[c][1]);
    } else if(configVector[c][0] == "BoatSubmarine") {
      BoatSubmarine = stoi(configVector[c][1]);
    }    
  }
}