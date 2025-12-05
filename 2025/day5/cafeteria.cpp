#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <tuple>
#include <vector>
#include <algorithm>


using namespace std;

void part1(){
    ifstream file("input.txt");
    string line;

    int output = 0;
    list<tuple<long long, long long>> ranges;
    list<long long> products; 
    
    bool at_products = false;
    while (getline(file, line)) {
        if (line.empty()){
            at_products = true;
            continue;
        } 
        if (!at_products) ranges.push_back({stoll(line.substr(0, line.find('-'))), stoll(line.substr(line.find('-') + 1, line.length()))});
        if (at_products) products.push_back(stoll(line));
        
    }
    for (long long product: products) {
        for (tuple<long long, long long> range: ranges){
            long long start = get<0>(range);
            long long end = get<1>(range);
            if (product >= start && product <= end){
                output++;
                break;
            }
        }
    }

    cout << output << endl;
}

void part2(){
    ifstream file("input.txt");
    string line;

    long long output = 0;

    vector<tuple<long long, long long>> ranges;

    while (getline(file, line) && !line.empty()) {
        ranges.push_back({stoll(line.substr(0, line.find('-'))), stoll(line.substr(line.find('-') + 1, line.length()))});
    }

    sort(ranges.begin(), ranges.end());

    vector<tuple<long long, long long>> merged;
    merged.push_back(ranges[0]);

    for (long long i = 1; i < ranges.size(); i++) {
        long long s = get<0>(ranges[i]);
        long long e = get<1>(ranges[i]);

        auto &last = merged.back();

        if (s > get<1>(last) + 1) {
            merged.emplace_back(s, e);
        } else {
            get<1>(last) = max(get<1>(last), e);
        }
    }

    for (auto &p : merged) {
        output += (get<1>(p) - get<0>(p) + 1);
    }

    cout << output << endl;
}

int main(){
    part1();
    part2();
}