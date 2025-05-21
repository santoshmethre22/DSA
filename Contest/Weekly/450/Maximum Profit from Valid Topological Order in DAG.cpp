#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>
#include<algorithm>
using namespace std;


class Solution {
public:

    bool comp(int a,int b,vector<int>&score){

            return score[a]<=score[b];
    }

    vector<int> khans(vector<vector<int>>&edges,vector<int>&score,int n){
        queue<int>q;
       // int n=score.size();

        unordered_map<int,vector<int>>adj;
        vector<int>indgree(n,0);
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            indgree[v]++;

            adj[u].push_back(v);
        
        }

        //for()

        for(auto i:indgree){

            if(i==0)
            {
                q.push(i);
            }
        }

        vector<int>ans;

        while (!q.empty())
        {
            int node =q.front();
            int size=q.size();
            ans.push_back(node);
            q.pop();

           // for(auto node :)

            /* code */
            for(int i=0;i<n;i++){
                vector<int>p;
                for(auto v:adj[node]){
                    indgree[v]--;
                    if(indgree[v]==0){
                        p.push_back(v);
                    }
                }
                sort(p.begin(),p.end(),comp);

                for(auto t:p){
                    q.push(t);
                }

            }


        }

        return ans;
        

    }



    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        
        vector<int>ans=khans(edges,score,n);

      int t=0;

        int size=ans.size();

        for(int i=0;i<n;i++){
            t+= (i*score[ans[i]]);
        }

        return t;
    }
}; 




int main() {

    // Your code here

    return 0;
}