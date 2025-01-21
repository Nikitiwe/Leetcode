class Solution {
public:
    bool validUtf8(vector<int>& nums) {
        int t=0;
        for (int i=0; i!=nums.size(); i++)
        {
            vector<int> arr(8, 0);
            int l=7;
            while (nums[i]>0)
            {
                arr[l]=nums[i]%2;
                nums[i]/=2;
                l--;
            }
            if (arr[0]==0)
            {
                if (t!=0) return 0;
            }
            else if (t==0)
            {
                if (arr[0]==1&&arr[1]==0) return 0;
                l=0;
                while (l<8&&arr[l]==1) l++;
                if (l>=5||l==1) return 0;
                t=l-1;
            }
            else if (t>0)
            {
                if (arr[0]==1&&arr[1]==0) t--;
                else return 0;
            }
        }
        if (t==0) return 1;
        else return 0;
    }
};