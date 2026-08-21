class Solution {
public:
    bool parseBoolExpr(string exp) {
        
        stack<char>st;
                int a=0;
                int b=0;

        for(auto &x:exp)
        {
            if(x==',') continue;

            if(x!=')')
            {
                st.push(x);
            }
            else
            {

                while(st.top()!='(')
                {
                    if(st.top()=='t')
                    {
                        a=1;
                    }
                    if(st.top()=='f')
                    {
                        b=1;
                    }
                    st.pop();
                }
                st.pop();

                char op=st.top();
                st.pop();
                if(op=='!')
                {
                    if(a) a=0,b=1;
                    else b=0,a=1;
                }
                else if(op=='&')
                {
                    if(b)
                    {
                        a=0;
                        b=1;
                    }
                    else
                    {
                        a=1;
                        b=0;
                    }
                }
                else
                {
                    if(a)
                    {
                        b=0;
                        a=1;
                    }
                    else
                    {
                        a=0;
                        b=1;
                    }
                }
                if(a)
                st.push('t');
                else st.push('f');
                
            }

        }

        return st.top()=='t'?true:false;
    }
};