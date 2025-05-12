class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& d) {
        vector<int> arr(10, 0);
        for (int i=0; i!=d.size(); i++) arr[d[i]]++;
        vector<int> ans;
        for (int i=100; i<=999; i += 2)
        {
            bool isit = 1;
            vector<int> t(10, 0);
            t[i%10]++;
            t[(i/10)%10]++;
            t[(i/100)]++;
            for (int j=0; j<10; j++) if (t[j] > arr[j])
            {
                isit = 0;
                break;
            }
            if (isit == 1) ans.push_back(i);
        }
        return ans;
    }
};