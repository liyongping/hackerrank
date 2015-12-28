#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list. 
 */


/**
 * Definition for singly-linked list with a random pointer. */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // 1. create new nodes, and insert it after orignal node.
        RandomListNode *curr = head;
        while(curr) {
            RandomListNode* node= new RandomListNode(curr->label);
            node->next = curr->next;
            node->random = curr->random;
            curr->next = node;
            curr = curr->next->next;
        }

        // correct random for new copy list
        curr = head;
        while(curr){
            if(curr->random != NULL)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        RandomListNode dummy(-1);
        dummy.next = head;
        // extract new list, recover original next pointer
        curr = head;
        RandomListNode * pnew = &dummy;
        while(curr){
            pnew->next = curr->next;

            curr->next = curr->next->next;
            curr = curr->next;

            pnew = pnew->next;
        }

        return dummy.next;
    }

};

void printList(RandomListNode *head){
    if(head == NULL)
        return ;

    RandomListNode *curr = head;
    while(curr != NULL){
        cout << curr->label << " ";
        if(curr->random)
            cout<< "(" << curr->random->label << ") "; 
        curr = curr->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Solution s;

    RandomListNode *head = new RandomListNode(0); 
    RandomListNode *pcurr = head;

    for(int i=1; i< 3; i++){
        RandomListNode *node = new RandomListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }
    head->random = pcurr;
    RandomListNode *tmp = pcurr;
    for(int i=4; i< 10; i++){
        RandomListNode *node = new RandomListNode(i);
        pcurr->next = node;
        pcurr = pcurr->next;
    }
    tmp->random = pcurr;

    printList(head);

    printList(s.copyRandomList(head));

    return 0;
}