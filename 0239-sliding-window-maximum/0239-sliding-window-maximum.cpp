class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int>dq;
        vector<int>ans;
        int n=nums.size();
        if(k>n) return ans;

        for(int i=0;i<k;i++)
        {
            if(dq.empty())
            {
                dq.push_front(i);
            }
            else
            {
                while(!dq.empty() && nums[dq.back()]<nums[i])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
        }
        ans.push_back(nums[dq.front()]);

        for(int i=k;i<n;i++)
        {
            if(dq.empty())
            {
                dq.push_front(i);
            }
            else
            {
                while(!dq.empty() && nums[dq.back()]<nums[i])
                {
                    dq.pop_back();
                }
                dq.push_back(i);
            }
            while(dq.front()<=i-k)
            {
                dq.pop_front();
            }
            ans.push_back(nums[dq.front()]);
        }
        return ans;


    }
};