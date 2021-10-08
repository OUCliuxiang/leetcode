/**        
 * Given the head of a sorted linked list, delete all nodes that have duplicate 
 * numbers, leaving only distinct numbers from the original list. Return the 
 * linked list sorted as well.          
 * 
 * Example 1:        
 * Input: head = [1,2,3,3,4,4,5]         
 * Output: [1,2,5]           
 * 
 * Example 2:          
 * Input: head = [1,1,1,2,3]            
 * Output: [2,3]            
 * 
 * Constraints:           
 * * The number of nodes in the list is in the range [0, 300].      
 * * -100 <= Node.val <= 100        
 * * The list is guaranteed to be sorted in ascending order.      
 */         

class Solution {
public:
    ListNode* deleteDuplicates_map(ListNode* head) {
        if(!head || !(head -> next)) return head;
        
        map<int, int> m;
        while(head){
            m[head -> val] ++;
            head = head -> next;
        }
        ListNode *pt1 = new ListNode();
        ListNode *pt2 = pt1;
        for(map<int, int>::iterator iter = m.begin(); 
            iter != m.end(); iter ++){
            if (iter -> second == 1){
                pt2 -> next = new ListNode(iter -> first);
                pt2 = pt2 -> next;
            }
        }
        return pt1 -> next;
    }

    ListNode* deleteDuplicates_recursive(ListNode* head) {
        if(!head || !(head -> next)) return head;
        int val = head -> val;
        ListNode*p = head -> next;
        if (p->val == val){
            while ( p &&  p -> val == val) 
                p = p -> next;
            return deleteDuplicates_recursive(p);
        }else{
            head -> next = deleteDuplicates_recursive(head -> next);
            return head;
        }
    }
};