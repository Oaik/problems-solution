#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

    string inp1, inp2;
    cin >> inp1 >> inp2;
    if (inp1 == inp2)
    	cout << "-1";
    else
    	cout << max(inp1.length(),inp2.length());

}
