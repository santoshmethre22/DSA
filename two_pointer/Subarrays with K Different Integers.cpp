#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;

class Solution {
public:

    int solve(vector<int>&nums,int k){
        
            unordered_map<int,int>mp;
            int ans=0;
            int left=0;
            int right=0;
            while(right<nums.size()){
                    mp[nums[right]]++;
                    while(mp.size()>k){
                        mp[nums[left]]--;
                        if(mp[nums[left]]==0){
                            mp.erase(nums[left]);
                        }
                        left++;
                    }

                    ans+=right-left+1;
                    right++;

            }

        return ans ;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {


        int ans=solve(nums,k);

        ans-=solve(nums,k-1);

        return ans;
    }
};

int main() {

    // Your code here

    return 0;
}