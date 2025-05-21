#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


class Solution {
public:
    const int MOD = 1e9 + 7;

    int dfs(unordered_map<int, vector<pair<int, int>>>& adj, 
        int node, int dest, long long prod, vector<bool>& visited,vector<vector<int>>&dp) {
            if (node == dest) return prod % MOD;

        visited[node] = true;

        if(dp[node][dest]!=-1) return dp[node][dest ];

        for (auto& v : adj[node]) {
            if (!visited[v.first]) {
                long long nextProd = (prod % MOD * v.second % MOD) % MOD;
                int result = dfs(adj, v.first, dest, nextProd, visited,dp);
                dp[node][dest]=nextProd;
            }
        }

        return dp[node][dest];
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        unordered_map<int, vector<pair<int, int>>> adj;
        int n = conversions.size() + 1;

        for (auto& i : conversions) {
            int u = i[0];
            int v = i[1];
            int w = i[2];
            adj[u].push_back({v, w});
        }

        vector<vector<int>>dp(n,vector<int>(n,-1));

        vector<int> baseUnit(n, 0);
        baseUnit[0] = 1;  // unit 0 is always 1

        dp[0][0]=1;

        for (int i = 1; i < n; i++) {
            vector<bool> visited(n, false);
            baseUnit[i] = dfs(adj, 0, i, 1, visited,dp);
        }

        return baseUnit;
    }
};



int main() {

    // Your code here

    return 0;
}