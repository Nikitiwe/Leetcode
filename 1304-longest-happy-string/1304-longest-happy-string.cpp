class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        int temp;
        if (a>=b&&a>=c) {ans+="a"; a--;}
        else if (b>=a&&b>=c) {ans+="b"; b--;}
        else  {ans+="c"; c--;}
        if (a>=b&&a>=c) {ans+="a"; a--;}
        else if (b>=a&&b>=c) {ans+="b"; b--;}
        else  {ans+="c"; c--;}
        while (a+b>0&&a+c>0&&c+b>0)
        {
            temp=ans.size();
            if (a>=b&&a>=c&&(ans.back()!='a'||ans[ans.size()-2]!='a')) {ans+="a"; a--;}
            else if (b>=a&&b>=c&&(ans.back()!='b'||ans[ans.size()-2]!='b')) {ans+="b"; b--;}
            else if (c>=a&&c>=b&&(ans.back()!='c'||ans[ans.size()-2]!='c')) {ans+="c"; c--;}
            else if (b>=c&&(ans.back()=='a'&&ans[ans.size()-2]=='a')) {ans+="b"; b--;}
            else if (b<c&&(ans.back()=='a'&&ans[ans.size()-2]=='a')) {ans+="c"; c--;}
            else if (a>=c&&(ans.back()=='b'&&ans[ans.size()-2]=='b')) {ans+="a"; a--;}
            else if (a<c&&(ans.back()=='b'&&ans[ans.size()-2]=='b')) {ans+="c"; c--;}
            else if (b>=a&&(ans.back()=='c'&&ans[ans.size()-2]=='c')) {ans+="b"; b--;}
            else if (b<a&&(ans.back()=='c'&&ans[ans.size()-2]=='c')) {ans+="a"; a--;}
            if (temp==ans.size()) break;
        }
        if (a>0&&(ans.back()!='a'||ans[ans.size()-2]!='a')) {ans+="a"; a--;}
        if (a>0&&(ans.back()!='a'||ans[ans.size()-2]!='a')) {ans+="a"; a--;}
        if (b>0&&(ans.back()!='b'||ans[ans.size()-2]!='b')) {ans+="b"; b--;}
        if (b>0&&(ans.back()!='b'||ans[ans.size()-2]!='b')) {ans+="b"; b--;}
        if (c>0&&(ans.back()!='c'||ans[ans.size()-2]!='c')) {ans+="c"; c--;}
        if (c>0&&(ans.back()!='c'||ans[ans.size()-2]!='c')) {ans+="c"; c--;}

        return ans;
    }
};