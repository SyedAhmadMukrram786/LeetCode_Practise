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
class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* h=head;
        while (h != nullptr && h->next != nullptr) {
            int gcd = std::gcd(h->val, h->next->val);
            ListNode* newNode = new ListNode(gcd);
            newNode->next = h->next;
            h->next = newNode;
            h = newNode->next;
        }
        return head;
    }
};