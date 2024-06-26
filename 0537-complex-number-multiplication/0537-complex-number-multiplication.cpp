class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int a1=stoi(num1.substr(0, num1.find('+'))),
            a2=stoi(num1.substr(num1.find('+')+1, num1.size())),
            b1=stoi(num2.substr(0, num2.find('+'))),
            b2=stoi(num2.substr(num2.find('+')+1, num2.size()));
        int x=a1*b1-a2*b2, y=a1*b2+a2*b1;
        return to_string(x)+"+"+to_string(y)+"i";
    }
};
