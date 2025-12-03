#include <fstream>
#include <iostream>
#include <string>


using namespace std;

void part1(){
    ifstream file("input.txt");
    string line;

    int dialPointer = 50;
    int password = 0;
    
    while (getline(file, line)) {
        int rotation = line[0] == 'L'? -1: 1;
        int step = stoi(line.substr(1));
        
        dialPointer += step * rotation;
        dialPointer = (dialPointer + 100) % 100;
        
        if (dialPointer == 0){
            password++;
        }
    }
    cout << password << endl;
}

void part2(){
    ifstream file("input.txt");
    string line;

    int dialPointer = 50;
    int password = 0;
    
    while (getline(file, line)) {
        int rotation = line[0] == 'L'? -1: 1;
        int step = stoi(line.substr(1));

        for (int i = 0; i < step; i++) {
            if (rotation == 1) dialPointer ++;
            else if (rotation == -1) dialPointer--;
            dialPointer = (dialPointer + 100) % 100;
            if (dialPointer == 0) password++;
        }
    }
    cout << password << endl;
}

int main(){
    part1();
    part2();
}