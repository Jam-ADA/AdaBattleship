#include "../headers/main.h"
using namespace std;

int randomInt(int min, int max) {
  srand(time(0));
  return rand()%(max+1) + min;
}