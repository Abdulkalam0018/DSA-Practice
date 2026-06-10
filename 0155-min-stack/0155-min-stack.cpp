class MinStack {
private:
  stack<pair<int,int>>st;
  int minval;
public:
    MinStack() {
        minval=INT_MAX;
    }
    
    void push(int value) {
        if(value<minval)
        {
            minval=value;
        }
        st.push({value,minval});
    }
    
    void pop() {
        
        st.pop();
        if(!st.empty()){
            auto [a,b]=st.top();
            minval=b;
        }
        else
        {
            minval=INT_MAX;
        }

    }
    
    int top() {
        auto [a,b]=st.top();
        return a;
    }
    
    int getMin() {
        auto [a,b]=st.top();
        return b;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */