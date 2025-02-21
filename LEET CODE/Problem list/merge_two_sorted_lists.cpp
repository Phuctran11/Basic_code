/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.
*/

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy; // Create a dummy node to simplify the merge process
        ListNode *tail = &dummy; 
        // Traverse both lists
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }
        // Attach the remaining part of the list
        if (list1 != nullptr) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }
        return dummy.next;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Solution s;
    // Create list1: 1 -> 2 -> 4
    ListNode* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    // Create list2: 1 -> 3 -> 4
    ListNode* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
    // Merge the two lists
    ListNode* list3 = s.mergeTwoLists(list1, list2);
    // Print the merged list
    printList(list3);
    // Free the allocated memory
    while (list3 != nullptr) {
        ListNode* temp = list3;
        list3 = list3->next;
        delete temp;
    }
    return 0;
}