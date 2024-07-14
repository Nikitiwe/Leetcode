class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> a={0, 1};
        int add=2;
        for (int i=1; i!=n; i++)
        {
            for (int j=a.size()-1; j>=0; j--)
            {
                a.push_back(a[j]+add);
            }
            add*=2;
        }
        return a;
    }
};