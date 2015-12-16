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
        if(l1 == NULL)
            return l2;
        if(l2 == NULL)
            return l1;

        ListNode* newhead = new ListNode(-1);
        // p1 points to l1 list's current node
        // p2 points to l2 list's current node
        // pcurr points to new list's current node
        ListNode* p1 = l1, *p2 = l2, *pcurr = newhead;
        while(p1 && p2){
            if(p1->val < p2->val){
                pcurr->next = p1;
                p1 = p1->next;
            }else{
                pcurr->next = p2;
                p2 = p2->next;
            }
            pcurr = pcurr->next;
        }

        // if l1 goes to end node, just append l2 to new list.
        if (p1 == NULL){
            pcurr->next = p2;
        }
        // if l2 goes to end node, just append l1 to new list.
        if (p2 == NULL){
            pcurr->next = p1;
        }
        pcurr = newhead->next;
        delete newhead;

        return pcurr;
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

    return 0;
}