#include<set>
#include<map>
#include<list>
#include<iomanip>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<complex>
#include<sstream>
#include<iostream>
#include<fstream>
#include<algorithm>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <unordered_map>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define ll long long

const double EPS = (1e-7);
int dcmp(double x, double y) {
	return fabs(x - y) <= EPS ? 0 : x < y ? -1 : 1;
}
using namespace std;


bool is_win(string config, char player) {

	bool rows =
		(config[0] == player && config[0] == config[1] && config[1] == config[2]) ||
		(config[3] == player && config[3] == config[4] && config[4] == config[5]) ||
		(config[6] == player && config[6] == config[7] && config[7] == config[8]);

	bool columns =
		(config[0] == player && config[0] == config[3] && config[3] == config[6]) ||
		(config[1] == player && config[1] == config[4] && config[4] == config[7]) ||
		(config[2] == player && config[2] == config[5] && config[5] == config[8]);

	bool diagonals =
		(config[0] == player && config[0] == config[4] && config[4] == config[8]) ||
		(config[2] == player && config[2] == config[4] && config[4] == config[6]);

	return rows || columns || diagonals;
}

int main() {
	string input,str;
	bool xWin, oWin;
	int xNum, oNum,dotNum;
	int t;
	cin >> t;
	while(t--) {
		input = "";
		for (int i = 0; i < 3; ++i) {
			cin >> str;
			input += str;
		}
		xWin = false, oWin = false, xNum = 0, oNum = 0,dotNum = 0;
		for (int i = 0; i < 9; ++i) {
			if(input[i] == 'X') ++xNum;
			else if ((input[i] == 'O')) ++oNum;
			else ++dotNum;
		}
		if (xNum != oNum && xNum != oNum+1) {
			cout << "no\n";
			continue;
		}
		xWin = is_win(input, 'X'), oWin = is_win(input, 'O');
		if ( (xWin && oWin) || (oWin && oNum != xNum) || (xWin && xNum != oNum + 1) ) {
			cout << "no\n";
			continue;
		}
		cout << "yes\n";
	}
	return 0;
}

