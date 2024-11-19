class Solution {
public:
    int findBestValue(vector<int>& arr, int t) {
        sort(arr.begin(), arr.end());
        int d=1000000, sum=0, l=0;
        for (int i=0; i<=t; i++)
        {
            while(l<arr.size()&&arr[l]<i)
            {
                sum+=arr[l];
                l++;
            }
            if (abs(t-sum-((int)arr.size()-l)*i)<d)
            {
                d=abs(t-sum-((int)arr.size()-l)*i);
            }
            else return i-1;
        }
        return -5;
    }
};