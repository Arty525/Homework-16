#include <iostream>
#include <string>

using namespace std;

int main() {
	double number;
	string n;

	cout << "Enter whole part: ";
	cin >> n;
	number = stod(n + ".0");
	cout << "Enter fraction: ";
	cin >> n;
	number += stod("0." + n);
	
	cout << number;	
}