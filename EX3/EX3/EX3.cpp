#include <iostream>
#include <string>

using namespace std;

double calculation(double fn, double sn, char sign) {
	if (sign == '+') {
		return fn + sn;
	}
	else if (sign == '-') {
		return fn - sn;
	}
	else if (sign == '/') {
		return fn / sn;
	}
	else if (sign == '*') {
		return fn * sn;
	}
}

int main() {
	string in;
	string fnumber;
	string snumber;
	char sign;

	cout << "Enter your mathematical expression: ";
	cin >> in;

	for (int i = 0; in[i] != '+' && in[i] != '-' && in[i] != '/' && in[i] != '*'; ++i) {
		fnumber += in[i];
		if (in[i + 1] == '+' || in[i + 1] == '-' || in[i + 1] == '/' || in[i + 1] == '*') {
			sign = in[i + 1];
			for (int j = i+2; j < in.length(); ++j) {
				snumber += in[j];
			}
		}
	}

	double fn = stod(fnumber);
	double sn = stod(snumber);

	cout << calculation(fn, sn, sign);

	return 0;
}