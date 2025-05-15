#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:

    bool issum(vector<int>rows,int sum){

       int m=rows.size();

        int total=0;

        for(int i=0;i<m;i++){
            

            if(sum==total) return true;
            
            total+=rows[i];



        }


            return false;

    }

    bool canPartitionGrid(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();
        vector<int>rows(m,0);
        vector<int>col(n,0);
        int total=0;
        for(int i=0;i<m;i++){
            int sum=0;
            for(int j=0;j<n;j++){

                sum+=grid[i][j];

                total+=grid[i][j];

            }

            rows[i]=sum;
        }


        for(int i=0;i<n;i++){
            
            int sum =0;
            for(int j =0;j<m;j++){

                    sum+=grid[j][i];

            }   

            col[i]=sum;
        }


        if(total%2!=0) return false;


        total=total/2;
        bool isrow=false,iscol=false;
        isrow=issum(rows,total);
        iscol=issum(col,total);

        return isrow||iscol;
    }
};

int main() {

    // Your code here

    return 0;
}