#include<iostream>
#include<vector>
#include<map>
#include<unordered_map>
using namespace std;



  struct ListNode {
     int val;
     ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:     
   ListNode* detectCycle(ListNode* head) {
    if (!head || !head->next) return NULL;

    ListNode* slow = head;
    ListNode* fast = head;

    // Step 1: Detect if cycle exists
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Cycle detected
            // Step 2: Find start of the cycle
            slow = head;
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Start node of the cycle
        }
    }

    return NULL; // No cycle
}

};

int main() {

    // Your code here

    return 0;
}