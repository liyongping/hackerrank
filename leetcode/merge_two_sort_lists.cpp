#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
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

        ListNode newhead(-1);
        // l1 points to l1 list's current node
        // l2 points to l2 list's current node
        // pcurr points to new list's current node
        ListNode *pcurr = &newhead;
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

        return newhead.next;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;

    ListNode *head1 = new ListNode(-1); 
    ListNode *pcurr = head1;
    for(int i=1; i< 20; i+=2){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;

    }
    printList(head1);

    ListNode *head2 = new ListNode(-1); 
    pcurr = head2;
    for(int i=0; i< 20; i+=2){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;

    }
    printList(head2);

    printList(s.mergeTwoLists(head1,head2));
    cout<<head1->val<< endl;
    cout<<head2->val<<endl;

    return 0;
}