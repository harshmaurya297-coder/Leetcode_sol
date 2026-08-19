/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;

        ListNode* mainHead = lists[0];

        for (int i = 1; i < lists.size(); i++) {

            ListNode* head = lists[i];
            if (head == NULL) continue;

            if (head->val < mainHead->val) {
                ListNode* temp = head;

                while (temp->next != NULL && temp->next->val < mainHead->val) {
                    temp = temp->next;
                }

                ListNode* NN = temp->next;
                temp->next = mainHead;
                mainHead = head;
                head = NN;
            }



            ListNode* temp = mainHead;

            while (head != NULL) {

                if (temp->next == NULL) {
                    temp->next = head;
                    break;
                }

                if (temp->next->val <= head->val) {
                    temp = temp->next;
                }
                else {
                    ListNode* NN = temp->next;
                    ListNode* NN1 = head->next;

                    temp->next = head;
                    head->next = NN;

                    head = NN1;
                    temp = temp->next;
                }
            }
        }
        return mainHead;
    }
};