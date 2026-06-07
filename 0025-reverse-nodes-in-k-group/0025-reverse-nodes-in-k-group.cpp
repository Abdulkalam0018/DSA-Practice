class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (check == nullptr) return head; 
            check = check->next;
        }

        ListNode* current = head;
        ListNode* prev = nullptr;
        int a = k;
        
        while(a) 
        {
            ListNode* temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
            a--;
        }
        
        head->next = reverseKGroup(current, k);
        
        return prev;
    }
};