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
#include <complex>

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

#define pii pair<ll, ll>

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define fi first
#define se second

typedef long long ll;
typedef long double ld;

const int inf = (int)1e9 + 7;
const int maxn = (int)2e5 + 7;
const int lmaxn = (int)1e6 + 7;
const ll linf = (ll)1e16 + 7;

const ld eps = ld(1e-11);

ll n, k, p[maxn], ans = linf, num;
char a[maxn];

int main(){
    scanf("%lld %lld", &n, &k);
    getchar();
    for(int i = 0; i < n; i++){
        p[i] = getchar() - '0';
        if(p[i] == '*' - '0')
            p[i] = inf;
        if((i + 1) % 80 == 0)
            getchar();
    }
    for(int i = 0; i < n; ++i)
        p[i] += p[i - 1];
    for(int i = 0; i + k - 1 < n; ++i){
        ll sum = (p[i + k - 1] - (!i ? 0 : p[i - 1]));
        if(ans > sum){
            ans = sum;
            num = i + 1;
        }
    }
    if(ans > (ll)1e6)
        printf("0");
    else
        printf("%lld", num);
    return 0;
}
