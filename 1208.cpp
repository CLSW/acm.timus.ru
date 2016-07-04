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
typedef unsigned long long ull;
typedef long double ld;

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

const ld eps = ld(1e-11);

ll n, ans;
string a[maxn], b[maxn], c[maxn];
ll aa[maxn], bb[maxn], cc[maxn];
map < ll, ll > m;
char tmp[50];

string Get(){
    scanf(" %s", tmp);
    return string(tmp);
}

ll gethash(string x){
    ll ans = 0, pf = 1;
    for(auto i : x)
        ans = ans + (pf * (i - '0')), pf *= 37;
    return ans;
}

main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i)
        aa[i] = gethash(Get()), bb[i] = gethash(Get()), cc[i] = gethash(Get());
    for(int i = 0; i < (1LL << n); ++i){
        m.clear();
        ll cnt = 0;
        for(int j = 0; j < n; ++j){
            if((i >> j) & 1){
                if(!m[aa[j]] && !m[bb[j]] && !m[cc[j]]){
                    m[aa[j]] = 1, m[bb[j]] = 1, m[cc[j]] = 1;
                    ++cnt;
                }
            }
        }
        ans = max(ans, cnt);
    }
    printf("%lld", (ll)ans);
    return 0;
}
