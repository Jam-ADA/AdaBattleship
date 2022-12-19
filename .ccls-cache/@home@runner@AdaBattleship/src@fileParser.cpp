#include "../headers/main.h"
using namespace std;

vector<vector<string>> getConfig() {
  vector<vector<string>> configVector;
  ifstream configFile("./adaship_config.ini");
  string line;
  bool equalsFound;
  while(getline(configFile, line)) {
    equalsFound = false;
    vector<string> configLine = {"",""};
    for(int c = 0; c < line.size(); c++) {
      if(line[c] == '=') {
        equalsFound = true;
      } else if(equalsFound == false) {
        configLine[0] = configLine[0] + line.at(c);
      } else if (equalsFound == true) {
        configLine[1] = configLine[1] + line.at(c);
      }
    }
    configVector.push_back(configLine);
  }
  return configVector;
} 