class Solution {
public:
    string largestMultipleOfThree(vector<int>& nums) {
        vector<int> arr;
        string ans;
        int b=0, c=0;
        sort(nums.rbegin(), nums.rend());
        for (int i=0; i!=nums.size(); i++)
        {
            if (nums[i]%3==0) arr.push_back(nums[i]);
            else if (nums[i]%3==1) b++;
            else if (nums[i]%3==2) c++;
        }
        int x=b, y=c;
        b=x%3; x-=b;
        c=y%3; y-=c;

        if (x>0&&c==2&&b==0)
        {
            x-=3;
            b+=2;
        }
        if (y>0&&b==2&&c==0)
        {
            y-=3;
            c+=2;
        }

        c=min(b, c);
        b=c;
        for (int i=0; i!=nums.size(); i++)
        {
            if (b+c+x+y==0) break;
            else if (b>0&&nums[i]%3==1) {arr.push_back(nums[i]); b--;}
            else if (x>0&&nums[i]%3==1) {arr.push_back(nums[i]); x--;}
            else if (c>0&&nums[i]%3==2) {arr.push_back(nums[i]); c--;}
            else if (y>0&&nums[i]%3==2) {arr.push_back(nums[i]); y--;}
        }
        sort(arr.rbegin(), arr.rend());
        for (int i=0; i<arr.size(); i++)
        {
            ans+=to_string(arr[i]);
        }
        if (ans.size()>1&&ans[0]=='0') return "0";
        return ans;
    }
};