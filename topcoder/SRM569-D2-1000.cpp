#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string.h>

using namespace std;


class MegaFactorialDiv2 {
public:

  vector<int> prime;
  long long MOD = 1000000009;
  void sieve() {
    int mx = 1010;
    int primes[mx];
    memset(primes, 0, sizeof primes);
    primes[0] = primes[1] = 1;
    for (int i = 2; i * i < mx; ++i) {
      if(primes[i]) continue;
      for (int j = i * i; j < mx; j += i)
        primes[j] = 1;
    }
    for (int i = 2; i < mx; ++i)
      if(!primes[i] && i < 1000)
        prime.push_back(i);
  }
  long long mem[1003][103];
  long long rect(int N, int K, int idx) {
    if(N == 0)
      return 0;
    long long& ret = mem[N][K];
    if(~ret)
      return ret;
    ret = 0;
    if(K == 0) {
      int val = prime[idx];
      while(N % val == 0) {
        N /= val;
        ++ret;
      }
      return ret;
    }
    return ret = (rect(N, K-1, idx) + (rect(N-1, K, idx))) % MOD;
  }

	int countDivisors(int N, int K) {
    sieve();
    long long res = 1;
    for (int i = 0; i < (int)prime.size(); ++i) {
      memset(mem, -1, sizeof mem);
      res *= (rect(N, K, i) + 1);
      res %= MOD;
    }
    return res;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1;
	cout << "]" << endl;
	MegaFactorialDiv2 *obj;
	int answer;
	obj = new MegaFactorialDiv2();
	clock_t startTime = clock();
	answer = obj->countDivisors(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 1;
	p2 = 4;
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = 6;
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 2;
	p2 = 18;
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 6;
	p1 = 3;
	p2 = 1392;
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 100;
	p1 = 2;
	p2 = 321266186;
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 1000;
	p1 = 1;
	p2 = 791569763;
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!

