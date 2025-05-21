#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string, int> freq;

        for (auto& response : responses) {
            unordered_set<string> unique(response.begin(), response.end());
            for (auto& s : unique) {
                freq[s]++;
            }
        }

        string best = "";
        int maxFreq = -1;

        for (auto& p : freq) {
            if (p.second > maxFreq) {
                maxFreq = p.second;
                best = p.first;
            } else if (p.second == maxFreq && p.first < best) {
                best = p.first;
            }
        }

        return best;
    }
};


int main() {

    // Your code here

    return 0;
}