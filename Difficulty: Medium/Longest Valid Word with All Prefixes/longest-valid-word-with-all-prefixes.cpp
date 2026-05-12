class Node{
   public:
        Node* links[26];
        bool flag;
    
    Node(){
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
    void setEnd()
    {
        flag=true;
    }
    bool End()
    {
        return flag;
    }
};
class Trie{
    private:
        Node* root;
    public:
    Trie(){
        root=new Node();
    }
    
    void insert(string word)
    {
        Node* dummy=root;
        for(auto &ch:word)
        {
            if(!dummy->containkey(ch))
            {
                dummy->put(ch,new Node());
            }
            dummy=dummy->get(ch);
        }
        dummy->setEnd();
    }
    
    bool search(string word)
    {
        Node* dummy=root;
        for(auto &ch:word)
        {
            if(!dummy->containkey(ch)) return false;
            dummy=dummy->get(ch);
        }
        return dummy->End();
    }
    
};
class Solution {
    public:
    string longestValidWord(vector<string>& words) {
        
        sort(words.begin(),words.end());
        Trie* trie=new Trie();
        for(auto &x:words)
        {
            trie->insert(x);
        }
        
        int len=0;
        string ans="";
        for(auto &x:words)
        {
            if(x.size()>len)
            {
                bool isok=true;
                for(int i=1;i<=x.size();i++)
                {
                    string k=x.substr(0,i);
                    if(trie->search(k)==false)
                    {
                        isok=false;
                        break;
                    }
                }
                if(isok){
                    len=x.size();
                    ans=x;
                }
                
            }
        }
        return ans;
        
    }
};
