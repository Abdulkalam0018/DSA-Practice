class Node{
    public:
        Node* links[26];
        bool flag;
        
    
    Node()
    {
        for(int i=0;i<26;i++)
        {
            links[i]=nullptr;
        }
        flag=false;
    }
    bool containkey(char ch)
    {
        return links[ch-'a']!=nullptr;
    }
    void put(char ch,Node* node)
    {
        links[ch-'a']=node;
    }
    Node* get(char ch)
    {
        return links[ch-'a'];
    }
    
};
class Solution {
  public:
    int countSubs(string& s)
    {

        int cnt=0;
        int n=s.size();
        Node* root=new Node();
        for(int i=0;i<n;i++)
        {
            Node* dummy=root;
            for(int j=i;j<n;j++)
            {
    
                char k=s[j];
    
                    if(!dummy->containkey(k))
                    {
                        dummy->put(k,new Node());
                        cnt++;
                    }
                    dummy=dummy->get(k);
    
            }
                
            
        }
        return cnt;
        
    }
};