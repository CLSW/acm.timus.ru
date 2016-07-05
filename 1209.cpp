
ll t;

ll Get(ll x){
    return (x * (x + 1)) / 2 + 1;
}

main(){
    scanf("%lld", &t);
    while(t--){
        ll n;
        scanf("%lld", &n);
        ll lf = 0, rg = n;
        while(rg - lf > 1){
            ll mid = (lf + rg) >> 1LL;
            if(Get(mid) <= n)
                lf = mid;
            else
                rg = mid;
        }
        ll ans = lf;
        if(Get(rg) <= n) ans = rg;
        printf("%lld\n", 1ll * (Get(ans) == n));
    }
    return 0;
}
