#include <bits/stdc++.h>

using namespace std;
using ll = long long;

///src = https://gist.github.com/ar-pa/957297fb3f88996ead11

class bignum {
    const int base = 1000000000, baseDigits = 9;
    vector<int> a;
    int sign;
    int size() {
        if (a.empty()) return 0;
        int ans = (a.size()-1)*baseDigits;
        int ac = a.back();
        while (ac) ans++,ac/=10;
        return ans;
    }
    void operator=(const bignum &b) {
        sign = b.sign, a = b.a;
    }
    void operator=(long long b) {
        sign = 1;
        a.clear();
        if (b < 0) sign = -1, b = -b;
        for(;b > 0; b = b/base) a.push_back(b%base);
    }
};

int main() {
    return 0;
}