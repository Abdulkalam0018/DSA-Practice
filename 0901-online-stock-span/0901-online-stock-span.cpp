#include <stack>
#include <utility>

class StockSpanner {
public:
    int idx;
    std::stack<std::pair<int, int>> st; // {price, index}

    StockSpanner() {
        idx = 0;
    }
    
    int next(int price) {

        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int span = st.empty() ? (idx + 1) : (idx - st.top().second);
        st.push({price, idx});
        idx++;

        return span;
    }
};