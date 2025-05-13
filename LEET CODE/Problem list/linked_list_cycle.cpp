/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.

 

Example 1:


Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:


Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.
Example 3:


Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.
*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
    public:
    bool hasCycle(ListNode *head) {
        if ( head == nullptr) return false;
        ListNode* p1 = head;
        ListNode* p2 = head;

        while(p2 != nullptr && p2->next != nullptr){
            p1 = p1->next;
            p2 = p2->next->next;

            if(p1 == p2) return true;
        }   
        return false;
    }
};

int main() {
    // Example usage
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next; // Creating a cycle

    Solution solution;
    bool result = solution.hasCycle(head);
    cout << (result ? "Cycle detected" : "No cycle detected") << endl;

    return 0;
}