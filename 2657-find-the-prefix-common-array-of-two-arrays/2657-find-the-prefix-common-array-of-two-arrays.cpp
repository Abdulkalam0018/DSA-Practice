class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        
        int cnt=2;

        vector<int>ans;
        set<int>st;
        int n=A.size();
        for(int i=0;i<n;i++)
        {
            st.insert(A[i]);
            st.insert(B[i]);
            int p=cnt-st.size();
            ans.push_back(p);
            cnt+=2;
        }
        return ans;
    }
};