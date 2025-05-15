#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:
    
    long long maxScore(int n, vector<vector<int>>& edges) {
        long long int ans=(1LL * n * (n - 1));
        for(int i=n;i>2;i--){
            ans += 1LL*i*(i-2);
        }
        if(edges.size()==n){
            return ans+2;
        }
        else{
            return ans;
        }
    }
};

int main() {

    // Your code here

    return 0;
}