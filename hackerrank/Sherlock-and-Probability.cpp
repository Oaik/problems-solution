#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
string solve(int n, int k, string s) {
  long long cnt = 0;
  vector<int> vec(n + 1 + k + n, 0);
  for (int i = 0; i < n; ++i) {
    vec[i] = s[i] - '0';
  }
  for (int i = 0; i <= n; ++i) {
    if (!i)
      continue;
    vec[i] += vec[i - 1];
  }
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0')
      continue;
    cnt += ((vec[min(i + k, n)] - vec[i]) * 2) + 1;
  }
  long long num = n;
  num = num * n;
  string str = "0/1";
  if (cnt == 0)
    return str;
  long long g = __gcd(cnt, num);
  str = to_string(cnt / g) + "/" + to_string(num / g);
  return str;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string nk_temp;
        getline(cin, nk_temp);

        vector<string> nk = split_string(nk_temp);

        int n = stoi(nk[0]);

        int k = stoi(nk[1]);

        string s;
        getline(cin, s);

        string result = solve(n, k, s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

