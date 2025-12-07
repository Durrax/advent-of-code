#include <fstream>
#include <iostream>
#include <string>
#include <queue>
#include <list>
#include <algorithm>
#include <map>

using namespace std; 


const int rows = 142;
const int cols = 141;

char grid [rows][cols];

map<pair<int,int>, long long> cache;

long long countPaths(pair<int,int> pos){

    if (cache.find(pos) != cache.end()) return cache[pos];
    
    int x = pos.first;
    int y = pos.second + 1;

    if (grid[y][x] == '^') cache[pos] = countPaths({x-1,y}) + countPaths({x+1,y});
    else if (y != rows - 1) cache[pos] = countPaths({x,y});
    else cache[pos] = 1;

    return cache[pos];
}

void part1(){
    ifstream file("input.txt");
    int output = 0;

    char grid [rows][cols];
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            file >> grid[r][c];
        }
    }

    pair<int,int> start = {cols/2, 0};
    queue<pair<int,int>> q;
    list<pair<int,int>> visited;
    q.push(start);

    while(!q.empty()){
        pair<int,int> node = q.front();
        q.pop();

        if (find(visited.begin(), visited.end(), node) != visited.end()) continue;
        visited.push_back(node);
        
        int x = node.first;
        int y = node.second + 1;

        if (grid[y][x] == '^'){
            q.push({x-1,y});
            q.push({x+1,y});
            output ++;
        }
        else if (y != rows-1) q.push({x,y});
    }
    
    cout << output << endl;
}

void part2(){
    
    ifstream file("input.txt");

    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            file >> grid[r][c];
        }
    }

    pair<int,int> start = {cols/2, 0};

    cout << countPaths(start) << endl;
}

int main(){
    part1();
    part2();
}