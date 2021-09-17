/* Given the head of a singly linked list, return the middle node of 
 * the linked list.        
 * If there are two middle nodes, return the second middle node.        
 * 
 * Example 1:       
 * Input: head = [1,2,3,4,5]       
 * Output: [3,4,5]       
 * Explanation: The middle node of the list is node 3.       
 * 
 * Example 2:       
 * Input: head = [1,2,3,4,5,6]       
 * Output: [4,5,6]        
 * Explanation: Since the list has two middle nodes with values 3 and 
 * 4, we return the second one.        
 * 
 * Constraints:       
 * The number of nodes in the list is in the range [1, 100].       
 * 1 <= Node.val <= 100  
 */ 

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
    ListNode* middleNode(ListNode* head) {
        ListNode* node = head;
        int length = 1;
        while(node -> next){
            length ++;
            node = node -> next;
        }
        length /= 2;
        length += 1;
        for(int i = 1; i < length; i++){
            head = head -> next;
        }
        return head;
    }

    ListNode* middleNode_discuss(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        return slow;
    }

};