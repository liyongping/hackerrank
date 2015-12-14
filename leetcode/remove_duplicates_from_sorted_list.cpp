#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3. 

 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL)
            return NULL;

        ListNode *curr = head;
        while(curr != NULL && curr->next != NULL){
            if(curr->val == curr->next->val){
                ListNode *newNext = curr->next->next;
                delete curr->next; // remember to release the momery
                curr->next = curr->next->next;
            }
            else // note: this case: 1 1 1, to 1
            {
                curr = curr->next;
            }
        }

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

    ListNode *l1 = new ListNode(1); head->next = l1;
    ListNode *l2 = new ListNode(2); l1->next = l2;
    ListNode *l3 = new ListNode(3); l2->next = l3;
    ListNode *l4 = new ListNode(3); l3->next = l4;
    ListNode *l5 = new ListNode(5); l4->next = l5;
    ListNode *l6 = new ListNode(6); l5->next = l6;
    ListNode *l7 = new ListNode(6); l6->next = l7;
    ListNode *l83 = new ListNode(8); l7->next = NULL;

    printList(head);
    printList(s.deleteDuplicates(head));

    /* code */
    return 0;
}