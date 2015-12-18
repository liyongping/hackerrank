#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode*curr = dummy;

        while(curr){
            if(curr->next && curr->next->val == val){ 
                // remove next, and keep curr not to move, need to check next->next
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            }else{// curr makes a step
                curr = curr->next;
            }
        }

        curr = dummy->next;
        delete dummy;
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

    ListNode *head = new ListNode(1); 
    ListNode *pcurr = head;

    for(int i=1; i< 10; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }
    printList(head);

    printList(s.removeElements(head,1));

    return 0;
}