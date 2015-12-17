#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:
Given n will always be valid.
Try to do this in one pass. 
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL)
            return NULL;

        ListNode* f = head, 
                * s = head;

        for (int i = 0; i < n; ++i)
         {
             f = f->next != NULL ? f->next : NULL;
         } 

        // deal with just one node
        if(f == NULL)
            return head->next;

        while(f->next != NULL) {
            f = f->next;
            s = s->next;
        }

        s->next = s->next->next;

        return head;

    }

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

int main(int argc, char const *argv[])
{
    Solution s;

    ListNode *head = new ListNode(0); 
    ListNode *pcurr = head;

    for(int i=1; i< 10; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }
    printList(head);

    printList(s.removeNthFromEnd(head,3));

    return 0;
}