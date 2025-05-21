#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;
// Maximum Profit from Valid Topological Order in DAG


class Solution {
public:
    vector<int> khans(vector<vector<int>>& edges, vector<int>& score, int n) {
        queue<int> q;
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n, 0);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];
            indegree[v]++;
            adj[u].push_back(v);
        }

        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;

        auto comp = [&](int a, int b) {
            return score[a] <= score[b];
        };

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            vector<int> p;
            for (auto v : adj[node]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    p.push_back(v);
                }
            }

            sort(p.begin(), p.end(), comp);
            for (auto t : p) {
                q.push(t);
            }
        }

        return ans;
    }

    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {

        int t = 0;
        if(edges.size()==0){
            sort(score.begin(),score.end());
            for(int i=0;i<score.size();i++){
                t+=(i+1)*score[i];

            }
                return t;
        }
        vector<int> ans = khans(edges, score, n);

        for (int i = 0; i < n; ++i) {
            t += ((i+1) * score[ans[i]]);
        }

        return t;
    }
};

int main() {

    // Your code here

    return 0;
}