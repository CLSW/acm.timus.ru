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
const int maxn = (int)2e5 + 7;
const int lmaxn = (int)1e6 + 7;
const ll linf = (ll)5e18 + 7;

const ld eps = ld(1e-11);

struct node{
    map < char, int > nxt;
    int link, len;
};

node st[maxn];
int sz, last;

void init(){
    st[0].link = -1;
    st[0].len = 0;
}

void add_letter(char c){
    int cur = ++sz;
    st[cur].len = st[last].len + 1;
    int p = last;
    for(; p != -1 && !st[p].nxt.count(c); p = st[p].link)
        st[p].nxt[c] = cur;
    if(p == -1){
        st[p].link = 0;
    }
    else{
        int q = st[p].nxt[c];
        if(st[p].len + 1 == st[q].len){
            st[cur].link = q;
        }
        else{
            int clone = ++sz;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            st[clone].nxt = st[q].nxt;
            for(; p != -1 && st[p].nxt[c] == q; p = st[p].link)
                st[p].nxt[c] = clone;
            st[q].link = st[cur].link = clone;
        }
    }
    last = cur;
}

int n;
char a[maxn], b[maxn];

main(){
    scanf("%lld", &n);
    for(int i = 0; i < n; ++i)
        scanf(" %c", &a[i]);
    for(int i = 0; i < n; ++i)
        scanf(" %c", &b[i]);
    init();
    for(int i = 0; i < n; ++i)
        add_letter(a[i]);
    int v = 0, llen = 0, best = 0, pos = 0;
    for(int i = 0; i < n; ++i){
        while(v && !st[v].nxt.count(b[i])){
            v = st[v].link;
            llen = st[v].len;
        }
        if(st[v].nxt.count(b[i])){
            v = st[v].nxt[b[i]];
            ++llen;
        }
        if(llen > best)
            pos = i, best = llen;
    }
    for(int i = pos - best + 1; i <= pos; ++i)
        printf("%c", b[i]);
    return 0;
}
