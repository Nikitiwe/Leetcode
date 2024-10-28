class Solution {
public:
    vector<int> distributeCandies(int c, int num) {
        vector<int> nums(num, 0);
        int i=0;
        while (c>0)
        {
            if (c>=i+1)
            {
                nums[i%num]+=i+1;
                c-=i+1;
                i++;
            }
            else
            {
                nums[i%num]+=c;
                break;
            }
        }
        return nums;
    }
};