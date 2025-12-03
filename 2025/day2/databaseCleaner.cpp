#include <fstream>
#include <iostream>
#include <string>
#include <regex>


using namespace std;

void part1(){
    ifstream file("input.txt");
    string range;
    long long output = 0ll;
    while (getline(file, range, ',')) {        
        int pos = range.find("-");
        long long rangeStart = stoll(range.substr(0, pos));
        long long rangeEnd = stoll(range.substr(pos + 1, range.length()));

        for (long long id = rangeStart; id <= rangeEnd; id++){
            string strId = to_string(id);
            int len = strId.length();
            if (len % 2 == 0){
                if (strId.substr(0,len/2) == strId.substr(len/2,len)){
                    output += id;
                }
            }
        }
    }
    cout << output << endl;
}

void part2(){
    ifstream file("input.txt");
    string range;
    long long output = 0ll;
    while (getline(file, range, ',')) {
        int pos = range.find("-");
        long long rangeStart = stoll(range.substr(0, pos));
        long long rangeEnd = stoll(range.substr(pos + 1, range.length()));

        for (long long id = rangeStart; id <= rangeEnd; id++){
            string strId = to_string(id);
            regex r("([0-9]+)\\1+");
            if (regex_match(strId, r)) output += id;
        }
    }
    cout << output << endl;
}

int main(){
    part1();
    part2();
}