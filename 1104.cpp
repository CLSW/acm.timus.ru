#include <iostream>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <climits>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <utility>
#include <sstream>
#include <numeric>
#include <functional>
#include <bitset>
#include <deque>

using namespace std;

#if __cplusplus >= 201103
    #include <unordered_map>
    #include <future>
    #include <atomic>
    #include <chrono>
    #include <unordered_set>
    #include <array>
    #include <random>
    #include <mutex>
#endif

#define pii pair<int, int>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define f first
#define s second

typedef long long ll;
typedef long double ld;

const int inf = (int)1e9 + 7;
const int linf = (int)1e16 + 7;
const int maxn = (int)2e5 + 7;
const int lmaxn = (int)1e6 + 7;

const ld eps = ld(1e-11);

char a[lmaxn];
int mn;

main(){
    cin >> a;
    mn = 2;
    int n = strlen(a);
    for(int i = 0; i < n; ++i){
        if(a[i] >= 'A')
            mn = max(mn, (a[i] - 'A') + 11);
        else
            mn = max(mn, (a[i] - '0') + 1);
    }
    for(int i = mn; i <= 36; ++i){
        int ans = 0, pw = 1;
        for(int j = n - 1; j >= 0; --j){
            if(a[j] >= 'A')
                ans += ((a[j] - 'A') + 10) * pw;
            else
                ans += (a[j] - '0') * pw;
            pw *= i;
            ans %= (i - 1), pw %= (i - 1);
        }
        if(!ans)
            return cout << i, 0;
    }
    cout << "No solution.";
    return 0;
}
