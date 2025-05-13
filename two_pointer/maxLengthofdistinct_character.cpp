#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

int solve(string s,int k){

    if(k==0) return 0;
        unordered_map<char,int>mp;

int left=0;
int right=0;


int maxleng=0;

while(right<s.size()){


    while(mp.size()>k){

        mp[s[left]]--;

        if(mp[s[left]]==0) {

            mp.erase(s[left]);
            
        }
        left++;
    }

    maxleng=max(maxleng,right-left +1);


    mp[s[right]]++;


}

    return maxleng;


}

int main() {

    // Your code here

    return 0;
}