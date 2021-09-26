/** 
 * Merge two sorted linked lists and return it as a sorted list. The 
 * list should be made by splicing together the nodes of the first 
 * two lists.            
 * 
 * Example 1:        
 * Input: l1 = [1,2,4], l2 = [1,3,4]           
 * Output: [1,1,2,3,4,4]            
 * 
 * Example 2:           
 * Input: l1 = [], l2 = []             
 * Output: []              
 * 
 * Example 3:         
 * Input: l1 = [], l2 = [0]            
 * Output: [0]           
 * 
 * Constraints:          
 * The number of nodes in both lists is in the range [0, 50].      
 * -100 <= Node.val <= 100      
 * Both l1 and l2 are sorted in non-decreasing order.
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1 && !l2)
            return l1;
        deque<int> tmp;
        while(l1){
            tmp.push_back(l1-> val); 
            //ListNode* node = l1;      
            l1 = l1 -> next;
            //node = nullptr;          
        }
        while(l2){
            tmp.push_back(l2-> val);
            //ListNode* node = l2;
            l2 = l2 -> next;
            //node = nullptr;
        }
        sort(tmp.begin(), tmp.end());
        ListNode* node = new ListNode(tmp.front());
        tmp.pop_front();
        ListNode* head = node;
        while (!tmp.empty()){
            node -> next = new ListNode();
            node = node -> next;
            node -> val = tmp.front();
            tmp.pop_front();
            }
        return head;
    }

    ListNode* mergeTwoLists_discuss(ListNode* l1, ListNode* l2) {
        if (!l1)    return l2;
        if (!l2)    return l1;
        
        if (l1 -> val < l2 -> val){
            l1 -> next = mergeTwoLists(l1 -> next, l2);
            return l1;
        }else{
            l2 -> next = mergeTwoLists(l1, l2 -> next);
            return l2;
        }
    }
};