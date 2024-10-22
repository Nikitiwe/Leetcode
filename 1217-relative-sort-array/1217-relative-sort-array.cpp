class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> m;
        for (int i=0; i!=arr2.size(); i++) m[arr2[i]]++;
        vector<int> ans;
        for (int i=0; i!=arr1.size(); i++)
        {
            if (m.count(arr1[i])==0) ans.push_back(arr1[i]);
            else m[arr1[i]]++;
        }
        sort(ans.begin(), ans.end());
        int l=0;
        for (int i=0; i!=arr2.size(); i++)
        {
            while (m[arr2[i]]>1)
            {
                arr1[l]=arr2[i];
                l++;
                m[arr2[i]]--;
            }
        }
        for (int i=0; i<ans.size(); i++)
        {
            arr1[l]=ans[i];
            l++;
        }
        return arr1;
    }
};