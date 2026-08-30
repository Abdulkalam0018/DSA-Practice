class Solution {
public:
    bool issafe(int i,int j,vector<pair<int,int>>&vis)
    {
        for(auto &x:vis)
        {
            if(x.second==j || i+j==x.first+x.second || x.first-x.second==i-j) return false;
        }
        return true;
    }
    void fun(vector<vector<string>> &ans,vector<string> &k,int m,int n,vector<pair<int,int>>&vis,string q)
    {
        if(m==n)
        {
            ans.push_back(k);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(issafe(m,i,vis))
            {
                string s=q;
                s[i]='Q';
                k.push_back(s);
                vis.push_back({m,i});
                fun(ans,k,m+1,n,vis,q);
                k.pop_back();
                vis.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        
        vector<vector<string>>ans;
        string s="";
        for(int i=0;i<n;i++)
        {
            s+=".";
        }
        for(int i=0;i<n;i++)    
        {
            vector<string>k;
            string p=s;
            p[i]='Q';
            k.push_back(p);
            vector<pair<int,int>>vis;
            vis.push_back({0,i});
            fun(ans,k,1,n,vis,s);

        }
        return ans;
    }
};