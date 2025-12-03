#include <fstream>
#include <iostream>
#include <string>


using namespace std;

void part1(){
    ifstream file("input.txt");
    string line;

    int output = 0;
    while (getline(file, line)) {
        int maxTensIndex = -1;
        int maxOnesIndex = -1;
        
        for (int i = 0; i < 99; i++){
            if (line[i] > line[maxTensIndex]){
                maxTensIndex = i;
            }
        }
        for (int j = maxTensIndex+1; j <= 99; j++){
            if (line[j] > line[maxOnesIndex]){
                maxOnesIndex = j;
            }
        }
        int maxJolt = stoi(to_string(line[maxTensIndex] - '0') + to_string(line[maxOnesIndex] - '0'));
        output += maxJolt;
    }
    cout << output << endl;
}

void part2(){
    ifstream file("input.txt");
    string line;

    long long output = 0ll;
    while (getline(file, line)) {
        // 10s place
        int Twelve = -1;
        int Eleven = -1;
        int Ten = -1;
        int Nine = -1;
        int Eight = -1;
        int Seven = -1;
        int Six = -1;
        int Five = -1;
        int Four = -1;
        int Three = -1;
        int Two = -1;
        int One = -1;

        for (int i = 0; i <= 88; i++){
            if (line[i] > line[Twelve]){
                Twelve = i;
            }
        }
        for (int j = Twelve+1; j <= 89; j++){
            if (line[j] > line[Eleven]){
                Eleven = j;
            }
        }
        for (int i = Eleven+1; i <= 90; i++){
            if (line[i] > line[Ten]){
                Ten = i;
            }
        }
        for (int j = Ten+1; j <= 91; j++){
            if (line[j] > line[Nine]){
                Nine = j;
            }
        }
        for (int i = Nine+1; i <= 92; i++){
            if (line[i] > line[Eight]){
                Eight = i;
            }
        }
        for (int j = Eight+1; j <= 93; j++){
            if (line[j] > line[Seven]){
                Seven = j;
            }
        }
        for (int i = Seven+1; i <= 94; i++){
            if (line[i] > line[Six]){
                Six = i;
            }
        }
        for (int j = Six+1; j <= 95; j++){
            if (line[j] > line[Five]){
                Five = j;
            }
        }
        for (int i = Five+1; i <= 96; i++){
            if (line[i] > line[Four]){
                Four = i;
            }
        }
        for (int j = Four+1; j <= 97; j++){
            if (line[j] > line[Three]){
                Three = j;
            }
        }
        for (int i = Three+1; i <= 98; i++){
            if (line[i] > line[Two]){
                Two = i;
            }
        }
        for (int j = Two+1; j <= 99; j++){
            if (line[j] > line[One]){
                One = j;
            }
        }
        
        long long maxJolt = stoll(
            to_string(line[Twelve] - '0') + 
            to_string(line[Eleven] - '0') + 
            to_string(line[Ten] - '0') + 
            to_string(line[Nine] - '0') + 
            to_string(line[Eight] - '0') + 
            to_string(line[Seven] - '0') + 
            to_string(line[Six] - '0') + 
            to_string(line[Five] - '0') + 
            to_string(line[Four] - '0') + 
            to_string(line[Three] - '0') + 
            to_string(line[Two] - '0') + 
            to_string(line[One] - '0'));
        output += maxJolt;
    }
    cout << output << endl;
}

int main(){
    part1();
    part2();
}