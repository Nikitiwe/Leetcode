class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int pen=1000, m=1000000000, f=0;
        long long count;
        while (m-pen>1)
        {
            count=0;
            for (int i=0; i!=nums.size(); i++)
            {
                count+=nums[i]/pen;
                if (nums[i]%pen==0) count--;
            }
            if (count<maxOperations) {m=pen; pen=(pen)/2;}
            else if (count>maxOperations) {if (f==1) break; else pen=(pen+m)/2;}
            else {pen--; f=1;}
        }
        pen++;
        count=0;
        for (int i=0; i!=nums.size(); i++)
        {
            count+=nums[i]/pen;
            if (nums[i]%pen==0) count--;
        }
        pen--;
        if (pen==0) return 1;
        int count1=0;
        for (int i=0; i!=nums.size(); i++)
        {
            count1+=nums[i]/pen;
            if (nums[i]%pen==0) count1--;
        }
        if (count<=maxOperations&&count1>maxOperations) return pen+1;
        else return pen;
    }
};