#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

void part1(){
    ifstream file("input.txt");

    const int rows = 5;
    const int cols = 1000;

    int numbers[rows][cols];
    char ops[cols];

    long long output = 0;

    for (int r = 0; r < rows - 1; r++) for (int c = 0; c < cols; c++) file >> numbers[r][c];
    
    for (int i = 0; i < cols; i++) file >> ops[i];
    
    for (int c = 0; c < cols; c++){
        long long result = numbers[0][c];
        for (int r = 1; r < rows - 1; r++){
            if (ops[c] == '+') result += numbers[r][c];
            if (ops[c] == '*') result *= numbers[r][c]; 
        }
        output += result;
    }

    cout << output << endl;
}

void part2(){
    ifstream file("input.txt");
    string line;

    const int rows = 5;
    const int cols = 3732;

    char columns[cols][rows];
    vector<tuple<char, int>> ops;
    vector<int> numbers;
    
    long long output = 0;
    
    int rowCount = 0;
    while (getline(file, line)) {
        for (int i = 0; i < line.length(); i++) columns[i][rowCount] = line[i];
        rowCount ++;
    }

    string op_str;
    for (int i = 0; i < cols; i++){
        string number;
        for (int j = 0; j < rows; j++){
            number += columns[i][j]; 
        }
        op_str += columns[i][rows-1];
        if(!all_of(number.begin(),number.end(),isspace)) numbers.push_back(stoi(number)); 
    }

    for (int i = 0; i < op_str.size(); ++i) {
        if (op_str[i] == '+' || op_str[i] == '*') {
            char op = op_str[i];
            int spaces = 0;
            int j = i + 1;

            while (j < op_str.size() && op_str[j] == ' ') {
                spaces++;
                j++;
            }

            if (j == op_str.size()) spaces++;
            ops.push_back({op, spaces});

            i = j - 1;
        }
    }

    for (tuple<char, int> op: ops){
        long long result = numbers.front();
        numbers.erase(numbers.begin());
        
        if (get<0>(op) == '+') for (int i = 0; i < get<1>(op) - 1; i++) {
            result += (numbers.front());
            numbers.erase(numbers.begin());
        }
        if (get<0>(op) == '*') for (int i = 0; i < get<1>(op) - 1; i++) {
            result *= numbers.front();
            numbers.erase(numbers.begin());
        }
        
        output += result;
    }

    cout << output << endl;
}

int main(){
    part1();
    part2();
}