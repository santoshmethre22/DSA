#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;


 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *slow=head;
        ListNode *fast=head->next;
        while(fast!=NULL){
            if(slow->val ==fast->val){
                //delete node 
                ListNode * temp=fast->next;
                slow->next=temp;
               // free(fast);
                fast=temp;

            }
            else{

                slow =fast;
                fast->next;
            }

        }
        return head;

    }
};

int main() {

    // Your code here

    return 0;
}