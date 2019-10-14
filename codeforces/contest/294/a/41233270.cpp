#include <iostream>
using namespace std;
int birds[100];
int main() {
	int numWires = 0, deadBirds = 0, curWire = 0, curBird = 0, leftBirds = 0, rightBirds = 0;
	cin >> numWires;
	for (int i = 0; i < numWires; ++i) {
		cin >> birds[i];
	}
	cin >> deadBirds;
	for (int j = 0; j < deadBirds; ++j) {
		cin >> curWire >> curBird;
		--curWire;
		rightBirds = birds[curWire] - curBird;
		leftBirds = birds[curWire] - (rightBirds + 1);
		if ( (curWire - 1) >= 0 )
			birds[curWire-1] += leftBirds;
		if ( (curWire + 1) < numWires )
			birds[curWire+1] += rightBirds;
		birds[curWire] = 0;
	}
	for (int k = 0; k < numWires; ++k)
		cout << birds[k] << "\n";
}