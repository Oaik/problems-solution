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

using namespace std;

class WeirdSort {
 public:
  vector<int> sortArray(vector<int> data) {
    sort(data.begin(), data.end());
    vector<int> res;
    do {
      auto child = data.begin();
      for(int it: data) {
        if(data.front() == it && data.back() == it + 1) {
          child++;
          continue;
        }
        if(!res.empty() && (res.back() + 1 == it)) {
          child++;
          continue;
        }
        res.push_back(it);
        data.erase(child);
        break;
      }
    } while(!data.empty());
    return res;
  }
}
;

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector<int> p0, bool hasAnswer, vector<int> p1) {
  cout << "Test " << testNum << ": [" << "{";
  for (int i = 0; int(p0.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << p0[i];
  }
  cout << "}";
  cout << "]" << endl;
  WeirdSort *obj;
  vector<int> answer;
  obj = new WeirdSort();
  clock_t startTime = clock();
  answer = obj->sortArray(p0);
  clock_t endTime = clock();
  delete obj;
  bool res;
  res = true;
  cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
  if (hasAnswer) {
    cout << "Desired answer:" << endl;
    cout << "\t" << "{";
    for (int i = 0; int(p1.size()) > i; ++i) {
      if (i > 0) {
        cout << ",";
      }
      cout << p1[i];
    }
    cout << "}" << endl;
  }
  cout << "Your answer:" << endl;
  cout << "\t" << "{";
  for (int i = 0; int(answer.size()) > i; ++i) {
    if (i > 0) {
      cout << ",";
    }
    cout << answer[i];
  }
  cout << "}" << endl;
  if (hasAnswer) {
    if (answer.size() != p1.size()) {
      res = false;
    } else {
      for (int i = 0; int(answer.size()) > i; ++i) {
        if (answer[i] != p1[i]) {
          res = false;
        }
      }
    }
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

  vector<int> p0;
  vector<int> p1;

  {
    // ----- test 0 -----
    int t0[] = { 1, 2 };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = { 2, 1 };
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 1 -----
    int t0[] = { 1, 2, 3 };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = { 1, 3, 2 };
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 2 -----
    int t0[] = { 1, 1, 1, 1, 2, 2, 2, 2, 2 };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = { 2, 2, 2, 2, 2, 1, 1, 1, 1 };
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 3 -----
    int t0[] = { 1, 2, 3, 4, 5, 6 };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = { 1, 3, 2, 4, 6, 5 };
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 4 -----
    int t0[] = { 1, 1, 2, 2, 3, 3 };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = { 1, 1, 3, 3, 2, 2 };
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 5 -----
    int t0[] = { 4, 2, 4, 2, 3, 2, 0, 1, 2 };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = { 0, 2, 1, 3, 2, 2, 2, 4, 4 };
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
    // ------------------
  }

  {
    // ----- test 6 -----
    int t0[] = { 0, 2, 1, 3, 2, 4, 3, 3 };
    p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
    int t1[] = { 0, 2, 1, 3, 2, 4, 3, 3 };
    p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
    all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
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

