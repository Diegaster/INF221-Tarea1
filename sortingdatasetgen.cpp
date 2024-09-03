#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std; 
int main() {
    int totalnum;
    cin >> totalnum; 
    vector<int> nums, nums_aux;
    nums.reserve(totalnum); 
    srand(static_cast<unsigned>(std::time(nullptr)));
    ofstream output_parcord("sorting-parcord-dataset.txt");
    ofstream output_semiord("sorting-semiord-dataset.txt");
    ofstream output_desord("sorting-desord-dataset.txt");
    int randomnum = rand() % 10000;

    while (nums.size() < (totalnum/2)) {
        nums.push_back(randomnum++);
        output_desord << randomnum << " "; 
        randomnum = rand() % 10000;
    }
    nums_aux = nums;
    sort(nums_aux.begin(), nums_aux.end());
    for (auto outp:nums_aux){
        output_semiord << outp << " ";
    }
    while (nums.size() < totalnum) {
        nums.push_back(randomnum++);
        output_desord << randomnum << " ";
        output_semiord << randomnum << " ";
        randomnum = rand() % 10000;
    }
    output_desord.close();
    output_semiord.close();
    for (size_t i = 0; i < nums.size(); i += 2) {
        sort(nums.begin() + i, nums.begin() + min(i + 2, nums.size()));
    }
    for (auto outp:nums) {
        output_parcord << outp << " ";
    }
    output_parcord.close();
    return 0;
}
