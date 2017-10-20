#pragma once
#include<iostream>
#include<ctime>
#include<chrono>
#include<iomanip>
#include<ratio>
using namespace std;

class Time {
private:
	chrono::high_resolution_clock::time_point _start;
	chrono::high_resolution_clock::time_point _end;

public:
	void SetStart() {
		_start = chrono::high_resolution_clock::now();
	}

	void SetEnd() {
		_end = chrono::high_resolution_clock::now();
	}

	void GetDuration(double *durationValue = nullptr) {
		if (_start == _end) {
			cout << "Przedzial czasowy, albo jest zerowy, albo zmienne _poczatek i _koniec nie zostaly zadeklarowane" << endl;
			return;
		}
		chrono::duration<double> timeDuration = chrono::duration_cast<chrono::duration<double>>(_end - _start);
		cout << "Czas to: " << timeDuration.count() << " sek." << endl;
		if (durationValue != nullptr)
			*durationValue = timeDuration.count();
	}
	static void Example() {
		Time timer;
		int x;
		double amountOfTime;
		timer.SetStart();
		cout << "Podaj liczbe ";
		cin >> x;
		timer.SetEnd();
		timer.GetDuration(&amountOfTime);
		cout << amountOfTime << endl;
	}
};