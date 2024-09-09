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
   vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> sp(m, vector<int>(n, -1));
        int top = 0, bottom = m - 1, left = 0, right = n - 1;
        int dir = 0;
        int i = 0, j = 0;
        ListNode* new_node = head;

        while (new_node != nullptr) {
            sp[i][j] = new_node->val;

            if (dir == 0) { 
                if (j == right) {
                    dir = 1;
                    top++; 
                    i++; 
                } else {
                    j++; 
                }
            } else if (dir == 1) {
                if (i == bottom) {
                    dir = 2;
                    right--;
                    j--;
                } else {
                    i++;
                }
            } else if (dir == 2) {
                if (j == left) {
                    dir = 3; 
                    bottom--;
                    i--; 
                } else {
                    j--;
                }
            } else if (dir == 3) {
                if (i == top) {
                    dir = 0; 
                    left++; 
                    j++;
                } else {
                    i--;
                }
            }
        
            new_node = new_node->next;
        }

        return sp;
   }

};