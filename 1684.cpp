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

# define pii pair<int, int>

# define pb push_back
# define eb emplace_back
# define mp make_pair

# define f first
# define s second

typedef long long ll;
typedef long double ld;

const ll inf = (ll)1e9 + 7;
const ll linf = (ll)1e16 + 7;
const ll maxn = (ll)4e5 + 7;

const ld eps = ld(1e-11);


char a[maxn], b[maxn];
char t[maxn];
int sz, z[maxn], d[maxn], ind[maxn];
vector < int > ans;

int t2[maxn];

int Max(int a, int b){
    return (d[a] >= d[b] ? a : b);
}

void update(int v, int tl, int tr, int pos){
    int tm = tl + (tr - tl) / 2;
    if(tl == tr){
        t2[v] = tl;
        return;
    }
    if(pos <= tm)
        update(v * 2, tl, tm, pos);
    else
        update(v * 2 + 1, tm + 1, tr, pos);
    t2[v] = Max(t2[v * 2], t2[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r){
    int tm = tl + (tr - tl) / 2;
    if(l > r) return maxn - 1;
    if(l == tl && r == tr) return t2[v];
    return Max(get(v * 2, tl, tm, l, min(r, tm)), get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
}

int main(){
    scanf("%s %s", a, b);
    int n = strlen(a);
    int m = strlen(b);
    for(int i = 0; i < n; ++i)
        t[sz++] = a[i];
    t[sz++] = '#';
    for(int i = 0; i < m; ++i)
        t[sz++] = b[i];
    for(int i = 1, l = 0, r = 0; i < sz; ++i){
        if(i <= r)
            z[i] = min(z[i - l], r - i + 1);
        while(i + z[i] < sz && t[z[i]] == t[i + z[i]])
	    ++z[i];
        if(i + z[i] - 1 > r)
	    l = i, r = i + z[i] - 1;
    }
    d[sz] = 1;
    update(1, 0, sz * 2, sz);
    for(int i = sz - 1; i > n; --i){
        ind[i] = get(1, 0, sz * 2, i, i + z[i]);
        d[i] = d[ind[i]];
        update(1, 0, sz * 2, i);
    }
    if(!d[n + 1]){
        printf("Yes\n");
        return 0;
    }
    printf("No\n");
    int now = n + 1;
    while(now < sz){
        if(now != n + 1) ans.pb(now);
        now = ind[now];
    }
    for(int &i : ans)
        i -= (n + 1);
    int nw = 0;
    for(int i : ans){
        for(int j = nw; j < i; ++j)
            printf("%c", b[j]);
        nw = i;
        printf(" ");
    }
    for(int i = nw; i < m; ++i)
        printf("%c", b[i]);
    printf("\n");
    return 0;
}
