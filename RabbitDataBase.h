#include "Rabbit.h"
#include <iostream>
#include <fstream>
using namespace std;

class RabbitDataBase{
  public:
  RabbitDataBase();
  void read();
  void printRabbits(ostream &out, bool printIndex);
  void save();
  void remove();
  void add();
  private:
    enum {MAX_RABBITS = 50};
    Rabbit rabbitArray[MAX_RABBITS];
    int numRabbits;
};