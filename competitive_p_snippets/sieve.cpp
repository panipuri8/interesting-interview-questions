bool prime[MAXN];
vector<int> p;

void sieve() {
	mem(prime,true);
	prime[0] = prime[1] = false;
	for(int i=2;i*i<MAXN;i++) {
		if(prime[i]) {
			for(int j=i*i;j<MAXN;j+=i) {
				prime[j] = false;
			}
		}
	}
	for(int i=0;i<100;i++) if(prime[i]) p.pb(i);
}