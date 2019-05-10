#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<string> split_string(string);

double const EPS = 1e-6, PI = acos(-1);
const int N = 1e3 + 9, OO = 1e9;

char arr[109][109];

double areaOfTri(double x1, double y1, double x2, double y2, double x3, double y3) {
  return fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2;
}

int main()
{
    string wh_temp;
    getline(cin, wh_temp);

    vector<string> wh = split_string(wh_temp);

    ll h = stoi(wh[0]);

    ll w = stoi(wh[1]);

    string circleXCircleY_temp;
    getline(cin, circleXCircleY_temp);

    vector<string> circleXCircleY = split_string(circleXCircleY_temp);

    ll xC = stoi(circleXCircleY[0]);

    ll yC = stoi(circleXCircleY[1]);

    ll rC = stoi(circleXCircleY[2]);

    string x1Y1X3Y3_temp;
    getline(cin, x1Y1X3Y3_temp);

    vector<string> x1Y1X3Y3 = split_string(x1Y1X3Y3_temp);

    ll x1 = stoi(x1Y1X3Y3[0]);

    ll y1 = stoi(x1Y1X3Y3[1]);

    ll x2 = stoi(x1Y1X3Y3[2]);

    ll y2 = stoi(x1Y1X3Y3[3]);

    // Write Your Code Here
    for (int i = 0; i < 103; ++i) {
        for (int j = 0; j < 103; ++j) {
        arr[i][j] = '.';
        }
    }
    ll dist;
    rC *= rC;
    for (int i = 0; i < h; ++i) {
    for (int j = 0; j < w; ++j) {
      dist = (i - xC) * (i - xC) + (j - yC) * (j - yC);
      if (dist <= rC)
        arr[j][i] = '#';
    }
  }
    double x3 = x1 + x2 + y1 - y2, y3 = x2 - x1 + y1 + y2, x4 = x1 + x2 + y2 - y1, y4 = x1 - x2 + y1 + y2;
    x3 /= 2, y3 /= 2, x4 /= 2, y4 /= 2;
    double areaRect = areaOfTri(x1, y1, x3, y3, x2, y2) + areaOfTri(x1, y1, x4, y4, x2, y2);
        //  areaRect /= 2;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
        double totalArea = areaOfTri(x1, y1, i, j, x4, y4) + areaOfTri(x4, y4, i, j, x2, y2)
            + areaOfTri(x2, y2, i, j, x3, y3) + areaOfTri(i, j, x3, y3, x1, y1);
        if(fabs(totalArea - areaRect) <= EPS)
            arr[j][i] = '#';
        }
    }
    for (int i = 0; i < w; ++i) {
        for (int j = 0; j < h; ++j) {
        cout << arr[i][j];
        }
        cout << '\n';
    }
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

