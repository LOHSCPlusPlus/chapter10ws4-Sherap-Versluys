#include "RabbitDataBase.h"
#include "ReadUtils.h"
using namespace std;

RabbitDataBase::RabbitDataBase(){
  numRabbits = 0;
  read();
}

void RabbitDataBase::read() {
    ifstream rabbitFile("rabbits.txt");
    numRabbits = 0;
    while(rabbitFile.peek() != EOF && numRabbits < MAX_RABBITS) {
        rabbitArray[numRabbits].readFromFile(rabbitFile);
        numRabbits++;
    }
}

void RabbitDataBase::printRabbits(ostream &out, bool printIndex) {
    for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbitArray[index].isvalid()) {
            if (printIndex) {
                out << "Index " << index << ": ";
            }
          rabbitArray[index].print(out);
        } 
    }
} 

void RabbitDataBase::save() {
    ofstream out("rabbits.txt");
    printRabbits(out, false);
}

void RabbitDataBase::remove(){
int index = 0;
    do {
        index = readInt("Enter an index to remove between 0 and 7: ");
    }while (index < 0 || index >= MAX_RABBITS);
    rabbitArray[index].makeinValid();
}
void RabbitDataBase::add(){
for (int index = 0; index < MAX_RABBITS; index++) {
        if (rabbitArray[index].isvalid() == false) {
            rabbitArray[index].readFromUser();
            return;
        }
    }
    cout << "Too many rabbits! No room for more!" << endl;
}

// Interact with the database functions using a menu to choose what to do