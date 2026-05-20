/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        // code here
        while(head->next!=nullptr)
        {
            head=head->next;
        }
        Node* dummy=head;
        while(dummy->prev!=nullptr)
        {
            dummy->next=dummy->prev;
            dummy->prev=nullptr;
            dummy=dummy->next;
        }
        dummy->next=nullptr;
        return head;
    }
};