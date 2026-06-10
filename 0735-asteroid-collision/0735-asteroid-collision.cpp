class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int>st;
        int n=ast.size();

        vector<int>ans;

        for(int i=n-1;i>=0;i--)
        {
            int a=ast[i];
            if(st.empty())
            {
                if(a>0)
                {
                    ans.push_back(a);
                }
                else
                {
                    st.push(a);
                }
            }
            else
            {
                if(a>0)
                {
                    bool check=true;
                    while(!st.empty() && abs(st.top())<=a)
                    {
                        if(abs(st.top())==a)
                        {
                            st.pop();
                            check=false;
                            break;
                        }
                        st.pop();
                    }
                    if(check && st.empty())
                    {
                        ans.push_back(a);
                    }
                }
                else
                {
                    st.push(a);
                }
            }
        }
        vector<int>k;
        while(!st.empty())
        {
            k.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        for(auto &x:ans)
        {
            k.push_back(x);
        }

        return k;

    }
};