class Node{
    public:
        Node* links[10];
    
        Node()
        {
            for(int i=0;i<=9;i++) links[i]=nullptr;

        }
        bool containkey(char ch)
        {
            return links[ch-'0']!=nullptr;
        }
        void put(char ch,Node* node)
        {
            links[ch-'0']=node;
        }
        Node* get(char ch)
        {
            return links[ch-'0'];
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
        Node* node=root;
        for(auto &ch:word)
        {
            if(!node->containkey(ch))
            {
                node->put(ch,new Node());
            }
            node=node->get(ch);
        }

    }

    bool prefix(string word)
    {
        Node* node=root;
        for(auto &ch:word)
        {
            if(!node->containkey(ch)) return false;
            node=node->get(ch);
        }
        return true;
    }
    
};
class Solution {
public:

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie* trie=new Trie();

        for(auto &x:arr1)
        {
            string s=to_string(x);
            trie->insert(s);
        }
        int ans=0;

        for(auto &x:arr2)
        {
            string s=to_string(x);

            int n=s.size();
            for(int i=1;i<=n;i++)
            {
                string p=s.substr(0,i);
                if(trie->prefix(p))
                {
                    ans=max(ans,i);
                }
                else
                {
                    break;
                }
            }
        }
        return ans;


    }
};