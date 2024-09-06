/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <unordered_set>
#include <vector>

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> numSet(nums.begin(), nums.end());

        ListNode* dummy = new ListNode(0);
        ListNode* ans = dummy;

        ListNode* new_node = head;
        while (new_node != nullptr) {
            if (numSet.find(new_node->val) == numSet.end()) {
                ans->next = new ListNode(new_node->val);
                ans = ans->next; 
            }
            new_node = new_node->next; 
        }

        return dummy->next;
    }
};
