

ll n;
vector < pll > v;

bool Comp(pll a, pll b){
    return (a.first > b.first);
}

main(){
    scanf("%lld", &n);
    for(ll i = 1; i <= n; ++i){
        ll x, y;
        scanf("%lld %lld", &x, &y);
        v.push_back({y, x});
    }
    stable_sort(v.begin(), v.end(), &Comp);
    for(auto i : v)
        printf("%lld %lld\n", i.second, i.first);
    return 0;
}
