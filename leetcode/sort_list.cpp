#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Sort a linked list in O(n log n) time using constant space complexity.

use merge sort
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head){
    if(head == NULL)
        return ;

    ListNode *curr = head;
    while(curr != NULL){
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode dummy(-1);
        // l1 points to l1 list's current node
        // l2 points to l2 list's current node
        // pcurr points to new list's current node
        ListNode *pcurr = &dummy;
        while(l1 && l2){
            if(l1->val < l2->val){
                pcurr->next = l1;
                l1 = l1->next;
            }else{
                pcurr->next = l2;
                l2 = l2->next;
            }
            pcurr = pcurr->next;
        }

        // if l1 goes to end node, just append l2 to new list.
        // if l2 goes to end node, just append l1 to new list.
        pcurr->next = l1 == NULL ? l2 : l1;

        return dummy.next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;

        ListNode *mid = getMidNode(head);

        ListNode *list2 = mid->next;
        mid->next = NULL;

        return mergeTwoLists(sortList(head), sortList(list2));
        
    }

    // return mid node, mid->next will be second list.
    ListNode * getMidNode(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;

    ListNode *head1 = new ListNode(10); 
    ListNode *pcurr = head1;
    for(int i=2; i > 1; i--){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;

    }
    printList(head1);

    printList(s.sortList(head1));

    return 0;
}