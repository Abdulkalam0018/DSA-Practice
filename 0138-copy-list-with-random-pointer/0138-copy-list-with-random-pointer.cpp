/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        Node* dummy=new Node(head->val);
        Node* cur=dummy;
        
        unordered_map<Node* ,Node*>mp;
        mp[head]=dummy;
        while(head!=nullptr)
        {

            if(head->random){
                if(mp.find(head->random)==mp.end()){

                    Node* randomn= new Node(head->random->val);
                    cur->random=randomn;
                    mp[head->random]=randomn;
                }
                else
                {
                    cur->random=mp[head->random];
                }

            }
            if(head->next)
            {
                if(mp.find(head->next)==mp.end()){

                    Node* nextn= new Node(head->next->val);
                    cur->next=nextn;
                    mp[head->next]=nextn;
                    
                }
                else
                {
                    cur->next=mp[head->next];

                }
            }
            cur=cur->next;
            head=head->next;
        }
        return dummy;
    }
};