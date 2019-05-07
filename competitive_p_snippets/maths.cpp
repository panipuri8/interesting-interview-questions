/* Start of Math Templates */
ll factorial[MAXN];
ll inverse[MAXN];
ll inverseFactorial[MAXN];

ll modInverse(ll a, ll m) { //if a and m are coprime, find a^-1 in mod m
  ll m0 = m;
  ll y = 0, x = 1;
  if (m == 1)
      return 0;
  while (a > 1) {
      ll q = a / m;
      ll t = m;
      m = a % m, a = t;
      t = y;
      y = x - q * y;
      x = t;
  }
  while (x < 0) x += m0;
  return x;
}


ll power(ll base,ll exp) {
	ll ans = 1;
	while(exp) {
		if(exp&1) ans = (ans * base)%MOD;
		base = (base*base)%MOD;
		exp>>=1;
	}
	return ans;
}

ll calculateInverseUsingFermatsLittleTheorem(int i) { //only if MOD is prime
	return power((ll)i , MOD-2);
}

void calculateInverse() {
  inverse[0] = 1;
  inverse[1] = 1;
  for(int i=2;i<MAXN;i++) {
    ll quotient = (ll)(MOD/i);
    ll remainder = (ll)(MOD%i);
    inverse[i] = ((-quotient * inverse[remainder]) + MOD)%MOD;
    // inverse[i] = calculateInverseUsingFermatsLittleTheorem(i);
  }
}

void calculateFactorialAndInverseFactorial() {
  factorial[0] = factorial[1] = 1;
  inverseFactorial[0] = inverseFactorial[1] = 1;
  for(int i=2;i<MAXN;i++) {
    factorial[i] = (factorial[i-1] * i)%MOD;
    inverseFactorial[i] = (inverseFactorial[i-1] * inverse[i])%MOD;
  }
}

/*Combinations in O(1)*/
ll nCr(int n, int r) {
  ll ans = factorial[n];
  ans = (ans * inverseFactorial[n-r])%MOD;
  ans = (ans * inverseFactorial[r])%MOD;
  return ans;
}

/*End of Math Templates */