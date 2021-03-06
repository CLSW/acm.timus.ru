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

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

const ld eps = ld(1e-11);

int n, x;
vector < int > a;
multiset < int, greater < int > > s;

main(){
    scanf("%d", &n);
    scanf("%d", &x);
    while(x != -1){
        a.pb(x);
        scanf("%d", &x);
    }
    int m = (int)a.size();
    for(int i = 0; i < n; ++i)
        s.insert(a[i]);
    printf("%d\n", *s.begin());
    for(int i = n; ; ++i){
        if(i >= m)
            break;
        s.erase(s.find(a[i - n]));
        s.insert(a[i]);
        printf("%d\n", *s.begin());
    }
    return 0;
}
