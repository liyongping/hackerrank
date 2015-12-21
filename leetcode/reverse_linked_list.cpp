#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Reverse a singly linked list.

click to show more hints.
Hint:

A linked list can be reversed either iteratively or recursively. Could you implement both?


 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head ==NULL){
            return NULL;
        }
        ListNode*pre = NULL;
        ListNode*curr = head;
        ListNode*tmp = NULL;
        while(curr->next !=NULL){
            tmp = curr->next;// tmp =2
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        curr->next = pre;
        return curr;
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
    for(int i=1; i< 9; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }


    printList(head);

    printList(s.reverseList(head));

    return 0;
}