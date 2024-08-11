class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string ans;
        if (a>=b)
        {
            while (a>b&&b>0) {ans+="aab"; a=a-2; b--;}
            while (a>0&&b>0) {ans+="ab"; a--;}
            while (a>0) {ans+="a"; a--;}
        }
        else
        {
            while (a<b&&a>0) {ans+="bba"; a--; b=b-2;}
            while (b>0&&a>0) {ans+="ba"; b--;}
            while (b>0) {ans+="b"; b--;}
        }
        return ans;
    }
};