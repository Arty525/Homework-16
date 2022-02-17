#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

bool compare(float speed, float current, float different, float epsilon) {
	return (speed + epsilon >= speed) && (speed - epsilon <= speed);
}

int main() {
	char spd[100];
	float different = 0.f;
	float current = 0.f;
	float epsilon = 0.01f;
	float speed = 0.f;
	do {
		sprintf(spd, "Current speed: %.1f km/h", current);
		cout << spd << endl;
		cout << "Input different: ";
		cin >> different;
		if (compare(speed = current + different, current, different, epsilon)) {
			speed = current + different;
			if (speed >= 150.f) {
				speed = 150.f;
				cout << "You have reached the maximum speed." << endl;
			}
			current = speed;
			sprintf(spd, "New speed: %.1f km/h", speed);
			cout << spd << endl << endl;
		}
		else {
			cout << "Value out of range." << endl;
		}
	} while (speed > 0);
}