#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the solve function below.
double solve(vector<int> P) {
    vector<int> vec = P;
    sort(vec.begin(), vec.end());
    if(vec == P)
        return 0;
    double fact = 1;
    for(int i = 2;i <= P.size();++i)
        fact *= i;
    int freq[109] = {};
    memset(freq, 0, sizeof(freq));
    for(int it: P) {
        ++freq[it];
    }
    for(int i = 1;i <= 100;++i){
        double ff = 1;
        for(int j = 2;j <= freq[i];++j)
            ff *= j;
        fact /= ff;
    }
    return fact;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int P_count;
    cin >> P_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string P_temp_temp;
    getline(cin, P_temp_temp);

    vector<string> P_temp = split_string(P_temp_temp);

    vector<int> P(P_count);

    for (int i = 0; i < P_count; i++) {
        int P_item = stoi(P_temp[i]);

        P[i] = P_item;
    }

    double result = solve(P);
    fout << fixed << setprecision(6);

    fout << result << "\n";

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

