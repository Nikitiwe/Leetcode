class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        vector<int> isit, rans;
        rans.push_back(A.size());
        for (int i=A.size()-1; i>0; i--)
        {
            if (find(isit.begin(), isit.end(), A[i])==isit.end()) isit.push_back(A[i]);
            if (find(isit.begin(), isit.end(), B[i])==isit.end()) isit.push_back(B[i]);
            rans.push_back(A.size()-isit.size());
        }
        reverse(rans.begin(), rans.end());
        return rans;
    }
};