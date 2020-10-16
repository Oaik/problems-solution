
/*

int mul(int x, int y) {
	return (1ll * x * y) % MOD;
}

int add(ll x, int y) {
	x += y;
	while(x >= MOD) x -= MOD;
	while(x < 0) x += MOD;
	return x;
}

int sub(int x, int y) {
	return (x - y + MOD) % MOD;
}

struct Hashs
{
	vector<int> hashs;
	vector<int> pows;
	int P;
	int MOD;

	Hashs() {}

	Hashs(string &s, int P, int MOD) : P(P), MOD(MOD)
	{
		int n = s.size();
		pows.resize(n+1, 0);
		hashs.resize(n+1, 0);
		pows[0] = 1;
		for(int i=n-1;i>=0;i--)
		{
			hashs[i] = add(mul(hashs[i+1], P), s[i] - 'a' + 1);
			pows[n-i] = mul(pows[n-i-1], P);
		}
		pows[n] = mul(pows[n-1], P);
	}
	int get_hash(int l, int r)
	{
		int ans= sub(hashs[l], mul(hashs[r+1],pows[r-l+1]));
		return ans;
	}
};

*/

const int BASE = 31, mod1 = 1e9 + 7, mod2 = 901840363;
const int MAX = 1e5 + 10 ;

long long base1[MAX] , base2[MAX] ;
long long modinv1[MAX] , modinv2[MAX] ;

int hashh(string str) {
	int val = 0, curB = 1;
	for (int i = 0; i < SZ(str); ++i) {
		val = add(val, mul(curB, str[i] - 'a' + 1));
		curB = mul(curB, BASE);
		hashVal[i] = val; // make 2D vector for double hashing
	}
	return val;
}

int hashrange(int l, int r) {
	int val = hashVal[r];
	if(l != 0)
		val = sub(val, hashVal[l - 1]);
	return mul(val, modInverse[l]);
}
 
 
void preprocess()
{
	base1[0] = base2[0] = 1ll ;
	modinv1[0] = modinv(1ll , mod1) ;
	modinv2[0] = modinv(1ll , mod2) ;
	for(int i = 1 ; i < MAX ; ++i)
	{
		base1[i] = (1ll * base1[i-1] * BASE) % mod1 ;
		base2[i] = (1ll * base2[i-1] * BASE) % mod2 ;
		modinv1[i] = modinv(base1[i] , mod1) ;
		modinv2[i] = modinv(base2[i] , mod2) ;
	}
}

