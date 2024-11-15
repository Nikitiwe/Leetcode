class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        for (int i=arr.size()-2; i>=0; i--)
        {
            int a=-1;
            for (int j=i+1; j<arr.size(); j++)
            {
                if (a==-1&&arr[i]>arr[j]) a=j;
                else if (arr[i]>arr[j])
                {
                    if (arr[j]>arr[a]) a=j;
                }
            }
            if (a!=-1)
            {
                swap(arr[i], arr[a]);
                return arr;
            }
        }
        return arr;
    }
};