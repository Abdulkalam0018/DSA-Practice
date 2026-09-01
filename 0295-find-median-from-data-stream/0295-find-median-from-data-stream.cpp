class MedianFinder {
    priority_queue<double>pq1;
    priority_queue<double,vector<double>,greater<>>pq2;
public:
    MedianFinder() {
    }
    // 1 2 3 4 5
    void addNum(int num) {
        if(pq1.empty())
        {
            pq1.push(num);
        }
        else
        {
            if(pq2.empty())
            {
                pq1.push(num);
                pq2.push(pq1.top());
                pq1.pop();
            }
            else
            {
                if(pq1.size()==pq2.size())
                {
                    if(pq2.top()<num)
                    {

                        pq1.push(pq2.top());
                        pq2.pop();
                        pq2.push(num);
                        
                    }
                    else
                    {
                        pq1.push(num);
                    }
                }
                else
                {
                    if(pq1.top()>num)
                    {
                        pq2.push(pq1.top());
                        pq1.pop();
                        pq1.push(num);
                    }
                    else
                    {
                        pq2.push(num);
                    }
                }
            }
        }
    }
    
    double findMedian() {
        if(pq1.size()==pq2.size())
        {
            return (pq1.top()+pq2.top())/2;
        }
        return pq1.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */