class Solution {
public:
    string reversePrefix(string word, char ch) {
        auto pos=find(word.begin(), word.end(), ch);
        if (pos==word.end()) return word;
        else {reverse(word.begin(), pos+1);}
        return word;
    }
};