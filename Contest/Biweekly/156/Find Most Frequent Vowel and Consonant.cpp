#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


class Solution {
public:
    int maxFreqSum(string s) {

        unordered_map<char,int>mp;

    for(auto i:s){
        mp[i]++;

    }
        int ovel=0;
        int consonent=0;
        for(auto i:mp){
            if(i.first=='a'||i.first=='e'||i.first=='i'||i.first=='o'||i.first=='u'){

                ovel=max(ovel,i.second);

            }
            else{
                consonent=max(consonent,i.second);
            }
        }


        return consonent+ovel;
        
    }
};

int main() {

    // Your code here

    return 0;
}