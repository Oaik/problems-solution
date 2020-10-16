int mul(int x, int y) {
	return (1ll * x * y) % MOD;
}

int add(ll x, int y) {
	x += y;
	while(x >= MOD) x -= MOD;
	while(x < 0) x += MOD;
	return x;
}

int sub(ll x, ll y) {
	return (((x - y) % MOD) + MOD) % MOD;
}

int fastpow(int x, int pow) {
	int ret = 1;
	while(pow) {
		if(pow & 1)
			ret = mul(ret, x);
		pow /= 2;
		x = mul(x, x);
	}
	return ret;
}

int modInv(int x) {
	return fastpow(x, MOD - 2);
}

int divide(int x, int y) {
	return mul(x, modInv(y));
}

int ncr(int n, int r) {
	if(r > n) return 0;
	return divide(fact[n], mul(fact[r], fact[n - r]));
}

void proprocess() {
	fact[0] = 1;
	for (int i = 1; i < N; ++i)
		fact[i - 1] = mul(fact[i], i);

}


// Matrix Pow
typedef vector<int> row;
typedef vector<row> matrix;

matrix zero(int n, int m) {
  return matrix(n, row(m, 0));
}

matrix idenity(int n) {
  matrix ret = zero(n, n);
  for (int i = 0; i < n; ++i)
    ret[i][i] = 1;
  return ret;
}

matrix multiply(const matrix& a, const matrix & b) {
  matrix ret = zero(a.size(), b[0].size());
  int aSZ = a.size(), bSZ = a[0].size(), cSZ = b[0].size();
  for (int i = 0; i < aSZ; ++i) {
    for (int k = 0; k < bSZ; ++k) {
      for (int j = 0; j < cSZ; ++j) {
        ret[i][j] = add(ret[i][j], mul(a[i][k], b[k][j]));
      }
    }
  }
  return ret;
}

// problems Require on how to convert 2D to 1D and apply matrix pow
