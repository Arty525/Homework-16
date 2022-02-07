#include <iostream>
#include <string>

using namespace std;

string convertation(int combination, string melody) {
	string m = to_string(combination);
	for (int i = 0; i < m.length(); ++i) {
		if (m[i] == '1') {
			melody += "DO ";
		}
		else if (m[i] == '2') {
			melody += "RE ";
		}
		else if (m[i] == '3') {
			melody += "MI ";
		}
		else if (m[i] == '4') {
			melody += "FA ";
		}
		else if (m[i] == '5') {
			melody += "SOL ";
		}
		else if (m[i] == '6') {
			melody += "LA ";
		}
		else if (m[i] == '7') {
			melody += "SI ";
		}
	}
	return melody;
}

int main() {

	enum notes {
		DO = 1,
		RE,
		MI,
		FA,
		SOL,
		LA,
		SI
	};

	int combination;
	string melody;

	for (int i = 0; i < 3; ++i) {
		cout << "Enter your notes combination (from 1 to 7): ";
		cin >> combination;
		melody = convertation(combination, melody);
	}

	cout << melody;
}