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
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class EllysCheckers {
public:
  int mem[(1 << 21)][2], n;
  int solve(int x, int player) {
    if(x == 0)
      return !player;
    int& ret = mem[x][player];
    if(~ret)
      return ret;
    ret = !player;
    for (int i = 0; i < n; ++i) {
      if(x & (1 << i)) {
        if( i + 1 < n && !(x & (1 << (i + 1))) ) {
          int nwMask = x;
          nwMask &= ~(1 << i);
          if(i + 2 != n)
            nwMask |= (1 << (i + 1));
          if(solve(nwMask, !player) == player)
            return ret = player;
        }
        if( i + 3 < n && !(x & (1 << (i + 3))) && (x & (1 << (i + 2))) && (x & (1 << (i + 1))) ) {
          int nwMask = x;
          nwMask &= ~(1 << i);
          if(i + 4 != n)
            nwMask |= (1 << (i + 3));
          if(solve(nwMask, !player) == player)
            return ret = player;
        }
      }
    }
    return ret;
  }
	string getWinner(string board) {
		int num = 0;
		n = board.size();
		for (int i = 0; i < (int)board.size() - 1; ++i) {
      if(board[i] == 'o')
        num |= (1 << i);
    }
		memset(mem, -1, sizeof mem);
		if(solve(num, 1) == 1)
		  return "YES";
		else
		  return "NO";
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, string p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	EllysCheckers *obj;
	string answer;
	obj = new EllysCheckers();
	clock_t startTime = clock();
	answer = obj->getWinner(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	string p0;
	string p1;
	
	{
	// ----- test 0 -----
	p0 = ".o...";
	p1 = "YES";
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "..o..o";
	p1 = "YES";
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = ".o...ooo..oo..";
	p1 = "NO";
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "......o.ooo.o......";
	p1 = "YES";
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = ".o..o...o....o.....o";
	p1 = "NO";
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "ooo";
	p1 = "YES";
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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

