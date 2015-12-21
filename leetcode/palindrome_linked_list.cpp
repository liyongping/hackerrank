#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given a singly linked list, determine if it is a palindrome.

1 --> 2 --> 3 --> 14 --> 3 --> 2 --> 1

Follow up:
Could you do it in O(n) time and O(1) space?


 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        
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

    for(int i=9; i >= 0; i--){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }

    printList(head);

    cout<<s.isPalindrome(head) <<endl;

    return 0;
}