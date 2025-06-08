class Solution {
public:
    void f(vector<int> &ans, int n, int a)
    {
        for (int k=0; k<=9; k++)
        {
            if (10*a + k > 0 && 10*a + k <= n)
            {
                ans.push_back(10*a + k);
                f(ans, n, 10*a + k);
            }
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        f(ans, n, 0);
        return ans;
    }
};