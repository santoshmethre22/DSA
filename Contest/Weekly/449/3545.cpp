#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char, int> mp;

        for (char ch : s) {
            mp[ch]++;
        }

        // Move (char, frequency) into a vector
        vector<pair<char, int>> freqVec(mp.begin(), mp.end());

        // Sort by frequency
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second < b.second;
        });

        // Optional: print the sorted result
        for (auto& p : freqVec) {
            cout << p.first << ": " << p.second << endl;
        }


        int n=s.size();

        int ans=0;

        for (int i=0;i<freqVec.size()-k-1;i++){

            ans+=mp[i];
        }

        return ans; 
    }
};

int main() {
    Solution sol;
    sol.minDeletion("aabbbcc", 1); // Example call
    return 0;
}
