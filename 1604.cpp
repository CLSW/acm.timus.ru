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

int n, p;
int a[maxn];
set < pii , greater < pii > > s;
vector < int > ans;

main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d", &a[i]);
        s.insert({a[i], i});
    }
    while(!s.empty()){
        if(p != s.begin() -> se){
            p = s.begin() -> se;
            pii val = *s.begin();
            s.erase(s.begin());
            val.fi--;
            if(val.fi)
                s.insert(val);
            ans.pb(val.se);
        }
        else{
            if(s.size() == 1){
                pii val = *s.begin();
                val.fi--;
                s.erase(s.begin());
                if(val.fi)
                    s.insert(val);
                ans.pb(val.se);
                p = val.se;
            }
            else{
                pii val = *s.rbegin();
                val.fi--;
                s.erase(--s.end());
                if(val.fi)
                    s.insert(val);
                ans.pb(val.se);
                p = val.se;
            }
        }
    }
    for(int i : ans)
        printf("%d ", i);
    return 0;
}
