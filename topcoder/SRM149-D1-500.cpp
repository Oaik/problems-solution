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


class MessageMess {
public:
	string target;
	vector<string> vec, ans;
  int n;
  long long mem[59][59];
	long long solve(int x, string res, int kam = 0) {
	  if(res == target) {
	    return 1;
	  }
	  long long& ret = mem[x][kam];
	  if(~ret)
	    return ret;
	  ret = 0;
	  for (int i = 0; i < n; ++i) {
	    int m = res.size();
	    int k = vec[i].size();
	    int q = target.size();
	    if(m + k > q)
	      continue;
	    string ss = target.substr(m, k);
	    if(ss != vec[i])
	      continue;
	    if(solve(i, res + vec[i], kam + 1))
	      ret += solve(i, res + vec[i], kam + 1), ans.push_back(vec[i]);
    }
	  return ret;
  }

  string restore(vector <string> dictionary, string message) {
		target = message;
		vec = dictionary;
    n = vec.size();
    memset(mem, -1, sizeof mem);
    long long cnt = solve(0, "");
		if(cnt == 0) {
		  return "IMPOSSIBLE!";
		} else if(cnt == 1) {
		  string egaba;
		  reverse(ans.begin(), ans.end());
		  for(string it: ans)
		    egaba += (it + " ");
		  egaba.pop_back();
		  return egaba;
		} else {
		  return "AMBIGUOUS!";
		}
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, string p1, bool hasAnswer, string p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}" << "," << "\"" << p1 << "\"";
	cout << "]" << endl;
	MessageMess *obj;
	string answer;
	obj = new MessageMess();
	clock_t startTime = clock();
	answer = obj->restore(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p2 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
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
	
	vector <string> p0;
	string p1;
	string p2;
	
	{
	// ----- test 0 -----
	string t0[] = {"HI","YOU","SAY"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "HIYOUSAYHI";
	p2 = "HI YOU SAY HI";
	all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	string t0[] = {"ABC","BCD","CD","ABCB"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "ABCBCD";
	p2 = "AMBIGUOUS!";
	all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	string t0[] = {"IMPOSS","SIBLE","S"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "IMPOSSIBLE";
	p2 = "IMPOSSIBLE!";
	all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	string t0[] = {"IMPOSS","SIBLE","S","IMPOSSIBLE"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "IMPOSSIBLE";
	p2 = "IMPOSSIBLE";
	all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	string t0[] = {"A","BA","BAB","AR"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "ABABABABABABABABABABABABABABABABABABABABABABABAR";
	p2 = "AMBIGUOUS!";
	all_right = KawigiEdit_RunTest(4, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	string t0[] = {"A","AA","AAA","AAAA","AAAAA","AAAAAA","AAAAAAA","AAAAAAAA","AAAAAAAAA","AAAAAAAAAA","AAAAAAAAAAA","AAAAAAAAAAAA","AAAAAAAAAAAAA","AAAAAAAAAAAAAA","AAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAA"
			"AAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA","AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	p2 = "AMBIGUOUS!";
	all_right = KawigiEdit_RunTest(5, p0, p1, true, p2) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	string t0[] = {"A","AA"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
	p2 = "AMBIGUOUS!";
	all_right = KawigiEdit_RunTest(6, p0, p1, true, p2) && all_right;
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
