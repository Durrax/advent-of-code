#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <tuple>


using namespace std;

const int rows = 137;
const int cols = 137;

int getMoveableRolls (char grid[rows][cols]) {
    int num_of_rolls = 0;
    list<tuple<int, int>> removed;
    
    int directions[8][2] = {{1,1}, {-1,1}, {1,-1}, {-1,-1}, {0,1}, {1,0}, {-1,0}, {0,-1}};
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == '@'){
                int rolls = 0;
                for (int dir = 0; dir<8; dir++) {
                    int newx = i + directions[dir][0]; 
                    int newy = j + directions[dir][1];
                    if (newx < 0 || newy < 0 || newx >= rows || newy >= cols) continue;
                    if (grid[newx][newy] == '@') rolls++;
                }
                if (rolls < 4){
                    num_of_rolls++;
                    removed.push_back({i,j});
                } 
            }
        }
    }

    // Mark removed rolls
    for (tuple<int,int> xy: removed){
        grid[get<0>(xy)][get<1>(xy)] = 'x';
    }

    return num_of_rolls;
}

void part1(){
    ifstream file("input.txt");
    string line;
    
    char grid[rows][cols];
    int output = 0;

    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            file>>grid[i][j];

    output = getMoveableRolls(grid);
    cout << output << endl;
}

void part2(){
    ifstream file("input.txt");
    string line;
    
    char grid[rows][cols];
    int output = 0;

    for (int i=0;i<rows;i++)
        for (int j=0;j<cols;j++)
            file>>grid[i][j];

    while(true){
        int removedRolls = getMoveableRolls(grid);
        if (removedRolls == 0) break;
        output += removedRolls;
    }
    
    cout << output << endl;
}

int main(){
    part1();
    part2();
}