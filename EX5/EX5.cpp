#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {
	enum sensors {
		OUTTEMP,
		INTEMP,
		TIME,
		MOTION
	};
	enum automate {
		POWER = 1,
		SOCKETS,
		INLIGHT,
		OUTLIGHT,
		INHEATING,
		WPHEATING,
		CONDITIONER
	};

	int state = 0;
	int day = 1;
	int time = 0;

	stringstream values;
	string motion, power, sockets, inLight;

	float outTemp, inTemp;

	vector<int> lightTemp{ 5000, 4400, 3800, 3200, 2700 };

	do {
		cout << "Time: " << time << ".00, " << "Enter values(outdoor temperature, internal temperature, motion, power, sockets, internal light)" << endl;
		
		cin >> outTemp;
		cin >> inTemp;
		cin >> motion;
		cin >> power;
		cin >> sockets;
		cin >> inLight;

		values << "Time: " << time << " Outdoor temperature: " << outTemp << " Internal temperature: " << inTemp << " Motion: " << motion << " Power: " << power << " Sockets: " << sockets << " Internal light: " << inLight;

		cout << values.str() << endl;

		cout << "==================================================" << endl;

		motion == "yes" ? state |= MOTION : state |= ~MOTION;

		power == "on" ? state |= POWER : state |= ~POWER;
		
		sockets == "on" ? state |= SOCKETS : state |= ~SOCKETS;
		
		inLight == "on" ? state |= INLIGHT : state |= ~INLIGHT;

		if (state & POWER) {
			if (state & INLIGHT) {
				if (time >= 16 && time <= 20) {
					cout << "Internal ligh temperature: " << lightTemp[time - 16] << "K" << endl;
				}
				else if (time >= 0 && time < 16) {
					cout << "Internal ligh temperature: " << lightTemp[0] << "K" << endl;
				}
				else if (time > 20 && time <= 23) {
					cout << "Internal ligh temperature: " << lightTemp[4] << "K" << endl;
				}
			}
			else {
				cout << "Internal light is Off;" << endl;
			}

			if ((state & MOTION) && (time > 16 || time < 5)) {
				state |= OUTLIGHT;
				cout << "Outdoor light is On" << endl;
			}
			else {
				state |= ~OUTLIGHT;
				cout << "Outdoor light is Off" << endl;
			}

			if (inTemp < 22.0f) {
				state |= INHEATING;
				cout << "Internal heating is On" << endl;
			}
			else if (inTemp >= 25.0f) {
				state |= ~INHEATING;
				cout << "Internal heating is Off" << endl;
			}
			
			if (outTemp < 0.0f) {
				state |= WPHEATING;
				cout << "Water pipes heating is On" << endl;
			}
			else if (outTemp > 5.0f) {
				state |= ~WPHEATING;
				cout << "Water pipes heating is Off" << endl;
			}

			if (state & SOCKETS) {
				if (inTemp >= 30.0f) {
					state |= CONDITIONER;
					cout << "Conditioner is On" << endl;
				}
				else if (inTemp <= 25.0f) {
					state |= ~CONDITIONER;
					cout << "Conditioner is Off" << endl;
				}
			}
			else {
				cout << "Sockets are Off" << endl;
			}
		}
		else {
			cout << "The whole house is de-energized." << endl;
		}

		cout << " =======================================" << endl;
		++time;

		if (time == 24) {
			time = 0;
			++day;
		}
	} while (day != 3);

	return 0;
}

//Датчик т снаружи
//Датчик т внутри
//1 автомат - питание дома
//2 автомат - осн розетки
//3 автомат - свет внутри дома ( если свет вкл - 16.00 5к, 17.00 4400к, 18.00 3800к, 19.00 3200к, 20.00 2700к, 00.00 5к) 
//4 автомат - наружный свет в саду (если время > 16.00 и < 5.00 и есть движение вкл иначе выкл)
//5 автомат - отопление в помещении (если т ниже 22 - вкл, если  >=25 - выкл)
//6 автомат - отопление водопровода (вкл при т ниже 0, откл при т выше 5)
//7 автомат - кондей (если т >= 30 - вкл, если т <= 25 - выкл) зависит от розетки