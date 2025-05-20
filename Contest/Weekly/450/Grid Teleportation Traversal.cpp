#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
#include<queue>


using namespace std;


struct tri{
    int i;
    int j;
    int val;
};

class Solution {
public:
    int n,m;


    bool issafe(int i,int j,vector<string>&matrix){
         return (i>=0 &&i<m)&&(j>=0 &&j<n)&&(matrix[i][j]!='#');
    }


    int minMoves(vector<string>& matrix) {
        vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};


         m=matrix.size();
         n=matrix[0].size();

        vector<vector<int>>vis(m,vector<int>(n,0));

        unordered_map<char,vector<pair<int,int>>>mp;

        for(int i=0;i<m;i++){
           for(int j=0;j<n;j++){
         
           if(matrix[i][j]>=65 && matrix[i][j]<=90)
            {
                mp[matrix[i][j]].push_back({i,j});
            }
        }

    }



//-------------------------------------------------->
        queue<tri>q;
        int ans=INT_MAX;

        q.push({0,0,0});
        //vis[]
        vis[0][0]=true;
    
        while(!q.empty()){

            auto [i,j,dis]=q.front();
            q.pop();
            
            // prosec the element
                if(i==m-1 && j==n-1) return dis;

                if (matrix[i][j] >= 'A' && matrix[i][j] <= 'Z') {
    for (auto k : mp[matrix[i][j]]) {
        if (!vis[k.first][k.second]) {
            q.push({k.first, k.second, dis});
        }
    }
    mp[matrix[i][j]].clear(); // ✅ Prevent infinite teleportation
}

                //--------

            for(auto d:dir){
                int n_i=i+d[0];
                int n_j=j+d[1];
                
            
               if (issafe(n_i, n_j, matrix) && !vis[n_i][n_j]) {        
                   q.push({n_i, n_j, dis + 1});
vis[n_i][n_j] = true;     
                }
            }
            ans=min(ans,dis);
        }

        return ans==INT_MAX?-1:ans;
    }
};
int main() {

    // Your code here

    return 0;
}