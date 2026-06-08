/* Structure of linked list Node
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* smallr(Node* head)
    {
        Node* prev=nullptr;
        Node* curr=head;
        while(curr)
        {
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;

        }
        return prev;
    };
    Node *reverseKGroup(Node *head, int k) {
        // code here
        Node* dummy=head;
        int cnt=k;
        while(cnt)
        {
            if(dummy==nullptr) return smallr(head);
            dummy=dummy->next;
            cnt--;
        }
        Node* prev=nullptr;
        Node* curr=head;
        int a=k;
        while(a)
        {
            Node* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
            a--;
        }
        head->next=reverseKGroup(curr,k);
        return prev;
        
    }
};