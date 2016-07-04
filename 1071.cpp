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

const int mod = (int)1e9;

const ld eps = ld(1e-11);

ll a, b;

main(){
    scanf("%lld %lld", &a, &b);
    for(ll i = 2; i <= a + 1; ++i){
        ll tmpa = a, tmpb = b;
        vector < ll > q, w;
        while(a){
            q.pb(a % i);
            a /= i;
        }
        while(b){
            w.pb(b % i);
            b /= i;
        }
        ll now = 0;
        for(int i = 0; i < (int)q.size(); ++i){
            if(now < (int)w.size() && w[now] == q[i])
                ++now;
        }
        if(now == (int)w.size()){
            printf("%lld", i);
            return 0;
        }
        a = tmpa, b = tmpb;
    }
    printf("No solution");
    return 0;
}
