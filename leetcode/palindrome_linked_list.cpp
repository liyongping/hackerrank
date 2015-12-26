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
    ListNode* reverseList(ListNode* head) {

        ListNode *pre= NULL, *curr=head;
        ListNode * saveNext = NULL;
        while(curr){
            saveNext = curr->next;
            curr->next = pre;
            pre = curr;
            curr = saveNext;
        }

        return pre;
    }

    bool isPalindrome(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *fast = &dummy, *slow = &dummy;

        // find mid node by slow and fast pointer
        while(fast && fast->next){
            fast = fast->next->next;
            slow = slow->next;
        }

        //slow->next will be the head of second list.
        //the length of slow > the length of fast (+1)
        ListNode *p2 = reverseList(slow->next);

        ListNode* p1 = dummy.next;
        while(p2){
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

    // recursive
    ListNode* temp;
    bool isPalindrome2(ListNode* head) {
        temp = head;
        return check(head);
    }

    bool check(ListNode* p) {
        if (NULL == p) return true;
        bool isPal = check(p->next) & (temp->val == p->val);
        temp = temp->next;
        return isPal;
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
    for(int i=1; i< 1; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }

    for(int i=-1; i >= 0; i--){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }

    printList(head);

    cout<<s.isPalindrome(head) <<endl;

    return 0;
}