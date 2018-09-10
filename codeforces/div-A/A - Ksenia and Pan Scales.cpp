	#include <iostream>
	#include <sstream>
	#include <iostream>
	#include <vector>
	using namespace std;
	
	
	int main() {
		vector<string> strings;
		vector<vector<char>> chars(2);
		int l = 0, r = 0, out = 0, curr = 0, rn = 0, ln = 0;
		string l1, l2, s;
		cin >> l1 >> l2;
		istringstream f(l1);
		if (l1 != "|") {
			while (getline(f, s, '|'))
			   strings.push_back(s);
	
			l = strings[0].length(), r = strings[1].length(), out = l2.length();
			if (s == ""){
				r = 0;
				strings.push_back("");
			}
		} else {
			l = 0, r = 0, out = l2.length();
		}
		while(out--) {
			if (l >= r) {
				chars[1].push_back(l2[curr++]);
				++r, ++rn;
			} else {
				chars[0].push_back(l2[curr++]);
				++l, ++ln;
			}
		}
		if (l == r) {
			if (l1 != "|")
				cout << strings[0];
			for (int i = 0; i < ln; ++i)
				cout << chars[0][i];
			cout << "|";
			if (l1 != "|")
				cout << strings[1];
			for (int i = 0; i < rn; ++i)
				cout << chars[1][i];
		} else {
			cout << "Impossible";
		}
	
	}

