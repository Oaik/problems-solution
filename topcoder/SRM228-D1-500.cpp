#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <string.h>
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

using namespace std;


class BagsOfGold {
public:
  vector<int> bag;
  int mem[59][59][2];
  int solve(int i, int j, int player) {
    if(i > j)
      return 0;
    int& ret = mem[i][j][player];
    if(~ret)
      return ret;
    ret = (player) ? -1e8 : 1e8;
    if(player) {
      int c1 = solve(i+1, j, !player) + bag[i];
      int c2 = solve(i, j-1, !player) + bag[j];
      ret = max(c1, c2);
    } else {
      int c1 = solve(i+1, j, !player) - bag[i];
      int c2 = solve(i, j-1, !player) - bag[j];
      ret = min(c1, c2);
    }
    return ret;
  }
	int netGain(vector <int> bags) {
			int n = bags.size();
			bag =bags;
			memset(mem, -1, sizeof mem);
			return solve(0, n-1, 1);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <int> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	BagsOfGold *obj;
	int answer;
	obj = new BagsOfGold();
	clock_t startTime = clock();
	answer = obj->netGain(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
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
	
	vector <int> p0;
	int p1;
	
	{
	// ----- test 0 -----
	int t0[] = {7,2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 5;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {2,7,3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -2;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {1000,1000,1000,1000,1000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1000;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {823,912,345,100000,867,222,991,3,40000};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = -58111;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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

