#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1 = l1, *p2 = l2;
        int carry = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode*pcurr = dummy;
        while(p1 != NULL || p2 != NULL){
            int x1 = p1 != NULL ? p1->val : 0;
            int x2 = p2 != NULL ? p2->val : 0;

            int sum = x1 + x2 + carry;
            carry = sum / 10;
            pcurr->next = new ListNode(sum % 10);

            pcurr = pcurr->next;
            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }

        if(carry > 0)
            pcurr->next = new ListNode(carry);

        ListNode * newhead = dummy->next;
        delete dummy;
        return newhead;
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

    ListNode *head1 = new ListNode(2); 
    ListNode *l1 = new ListNode(4); head1->next = l1;
    ListNode *l2 = new ListNode(3); l1->next = l2;

    printList(head1);

    ListNode *head2 = new ListNode(5); 
    ListNode *h1 = new ListNode(6); head2->next = h1;
    ListNode *h2 = new ListNode(4); h1->next = h2;
    ListNode *h3 = new ListNode(4); h2->next = h3;
    printList(head2);

    printList(s.addTwoNumbers(head1,head2));


    return 0;
}