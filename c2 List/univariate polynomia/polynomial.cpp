#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string str;
        int cnt = 0;
        for (int i = s.length() - 1; i >= 0; --i) {
            if (s[i] == '-')continue;
            if (cnt == 4) { str += '-'; cnt = 0; }
            if (s[i] > 'a' && s[i] < 'z')
                s[i] += 'a' - 'A';
            str += s[i];
            ++cnt;
        }
        int p = 0, q = str.length() - 1;
        while (p < q)swap(str[p++], str[q--]);
        return str;
    }
};
int main() {
    Solution s;
    cout<<s.licenseKeyFormatting("5F3Z-2e-9-w",4);
}