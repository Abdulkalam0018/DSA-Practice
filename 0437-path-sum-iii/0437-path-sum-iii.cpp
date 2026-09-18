/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans;
    using ll=long long;
    void fun(TreeNode* root, int ts, ll sum, unordered_map<ll,int> &mp)
    {
        if(!root) return ;

        sum+=root->val;
        ll ch=sum-ts;
        if(mp.find(ch)!=mp.end())
        {
            ans+=mp[ch];
        }
        //cout<<sum<<" "<<ans<<endl;
        mp[sum]++;
        fun(root->left,ts,sum,mp);
        fun(root->right,ts,sum,mp);
        mp[sum]--;
    }
    int pathSum(TreeNode* root, int ts)
    {
        
        ans=0;
        if(!root) return ans;
        unordered_map<ll,int>mp;
        mp[0]=1;
        ll sum=0;
        //cout<<"X"<<endl;
        fun(root,ts,sum,mp);
        return ans;
    }
};