#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Given a linked list, return the node where the cycle begins. 
If there is no cycle, return null.

Note: Do not modify the linked list.

Follow up:
Can you solve it without using extra space? 
 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {

        ListNode * twostep = head;
        ListNode * onestep = head;
        // 因为fast指针比slow指针走得快，所以只要判断fast指针是否为空就好
        while(twostep !=NULL && twostep->next != NULL){
            twostep = twostep->next->next;
            onestep = onestep->next;
            // if they meet at same node, it's an cycle linked list.
            if(onestep == twostep){
                return true;
            }
        }
        return false;
    }

    /*
    slow: y = x + k1*c + b
    fast: 2y = x + k2*c + b
    ==>
        x + b = k*c
        x = k*c - b
     */
    ListNode *detectCycle(ListNode *head) {
        ListNode * twostep = head;
        ListNode * onestep = head;
        // 因为fast指针比slow指针走得快，所以只要判断fast指针是否为空就好
        while(twostep !=NULL && twostep->next != NULL){
            twostep = twostep->next->next;
            onestep = onestep->next;
            // if they meet at same node, it's an cycle linked list.
            if(onestep == twostep){
                break;
            }
        }
        // no cycle
        if(twostep == NULL || twostep->next == NULL)
            return NULL;

        onestep = head;

        while(onestep != twostep){
            onestep = onestep->next;
            twostep = twostep->next; // also move with one step
        }
        return twostep;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    /*
    0 --> 1 --> 2 --> 3 --> 4 --> 5
                      |           |
                      |           |
                      8 <-- 7 <-- 6
     */

    ListNode *head = new ListNode(0); 
    ListNode *pcurr = head;
    ListNode *px = NULL;
    int j = 3;
    for(int i=1; i< 9; i++){
        ListNode *node = new ListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;

        if(i == j){
            px = pcurr;
        }
    }

    pcurr->next = px;

    cout<<s.hasCycle(head)<< endl;
    cout<<s.detectCycle(head)->val<< endl;
    /* code */
    return 0;
}