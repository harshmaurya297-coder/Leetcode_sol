class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        if (head == NULL || head->next == NULL || head->next->next == NULL) {
            return {-1, -1};
        }

        ListNode* temp = head;

        stack<int> st;
        vector<int> v;

        int diff;

        // First difference
        diff = temp->val - temp->next->val;
        st.push(diff);

        temp = temp->next;

        int pos = 1;

        while (temp->next != NULL) {

            diff = temp->val - temp->next->val;

            // Sign change => critical point
            if ((st.top() > 0 && diff < 0) ||
                (st.top() < 0 && diff > 0)) {
                
                v.push_back(pos);
            }

            st.push(diff);

            temp = temp->next;
            pos++;
        }

        // Less than 2 critical points
        if (v.size() < 2) {
            return {-1, -1};
        }

        int shortest = INT_MAX;

        for (int i = 0; i < v.size() - 1; i++) {
            shortest = min(shortest, v[i + 1] - v[i]);
        }

        int longest = v[v.size() - 1] - v[0];

        return {shortest, longest};
    }
};
