class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int len=1;

        for(int i=0;i<n;i++)    
        {
            unordered_map<int,int>freq;
            unordered_map<int,int>fof;
            int unq=0;
            int max_freq=0;

            for(int j=i;j<n;j++)
            {
                if(freq[nums[j]]==0)
                {
                    unq++;
                }
                else
                {
                    fof[freq[nums[j]]]--;
                }
                freq[nums[j]]++;
                fof[freq[nums[j]]]++;
                max_freq=max(max_freq,freq[nums[j]]);
                if(unq==1)
                {
                    len=max(len,j-i+1);
                }
                else
                {
                    int a=max_freq/2;
                    if(max_freq%2==0 && fof[a]>0 && fof[max_freq]>0 && fof[a]+fof[max_freq]==unq )
                    {
                        len=max(len,j-i+1);
                    }
                }
            }
            


        }
        return len;
    }
    
};