void multiply(ll a[][2], ll b[][2]) {
    ll x = (a[0][0] * b[0][0] + a[0][1] * b[1][0])%MOD;
    ll y = (a[0][0] * b[0][1] + a[0][1] * b[1][1])%MOD;
    ll z = (a[1][0] * b[0][0] + a[1][1] * b[1][0])%MOD;
    ll p = (a[1][0] * b[0][1] + a[1][1] * b[1][1])%MOD;
    a[0][0] = x;
    a[0][1] = y;
    a[1][0] = z;
    a[1][1] = p;
}

ll fibonacci(ll n) { //call fibonacci(n-2)
    if(n <= 0) return 1;
    ll a[2][2] = {{0,1}, {1,1}};
    ll exp = n;
    ll ans[2][2] = {{1,1}, {1,1}};
    while(exp) {
        if(exp&1) multiply(ans, a);
        exp>>=1;
        multiply(a,a);
    }
    // print_matrix(ans);
    return ans[1][1];
}