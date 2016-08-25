#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3. 

 */


/* Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode *head);

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        newHead->next = head;

        ListNode* pre = newHead;
        ListNode* cur = newHead->next;

        while(pre && cur){
            bool hadDuiplicate = false;
            while(cur != NULL && cur->next != NULL){
                if(cur->val == cur->next->val){
                    hadDuiplicate = true;
                    //remove cur->next
                    cur->next = cur->next->next;
                    printList(newHead);
                }else{
                    break;
                }

            }
            if(hadDuiplicate){
                // remove the last duplicate node
                pre->next = cur->next;
                cur = cur->next;
                printList(newHead);
            }else{
                ListNode* tmp = cur;
                cur = tmp->next;
                pre = tmp;
                
            }
        }

        return newHead->next;
    }
    
    //http://bangbingsyb.blogspot.jp/2014/11/leetcode-remove-duplicates-from-sorted_19.html
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

    ListNode *l1 = new ListNode(1); head->next = l1;
    ListNode *l2 = new ListNode(1); l1->next = l2;
    ListNode *l3 = new ListNode(3); l2->next = l3;
    ListNode *l4 = new ListNode(3); l3->next = l4;
    ListNode *l5 = new ListNode(4); l4->next = l5;
    ListNode *l6 = new ListNode(4); l5->next = l6;
    ListNode *l7 = new ListNode(5); l6->next = l7;
    ListNode *l83 = new ListNode(6); l7->next = NULL;
    printList(head);
    printList(s.deleteDuplicates(head));

    /* code */
    return 0;
}