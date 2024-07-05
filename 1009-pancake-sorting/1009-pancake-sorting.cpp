class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;
        int k;
        for (int i=arr.size()-1; i>0; i--)
        {
            if (arr[i]!=i+1)
            {
                k=distance(arr.begin(), find(arr.begin(), arr.end(), i+1));
                if (k!=0) {reverse(arr.begin(), arr.begin()+k+1);
                ans.push_back(k+1);}
                reverse(arr.begin(), arr.begin()+i+1);
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};