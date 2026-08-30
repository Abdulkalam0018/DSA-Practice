class Solution {
public:
    void fun(vector<vector<int>>&ans1,vector<int>&k,vector<int>& cand,int tar,int i,int sum,int n)
    {
        if(i>=n) return ;
        if(sum>tar) return ;
        if(sum==tar)
        {
            ans1.push_back(k);
            return ;
        }
        k.push_back(cand[i]);
        fun(ans1,k,cand,tar,i,sum+cand[i],n);
        k.pop_back();
        fun(ans1,k,cand,tar,i+1,sum,n);

    }   
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        int n=cand.size();
        
        vector<vector<int>>ans1;
        vector<int>k;
        fun(ans1,k,cand,tar,0,0,n);
        return ans1;

    }
};