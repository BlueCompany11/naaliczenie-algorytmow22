#include<iostream>
#include<random>
#include<time.h>
#include"Algorytmy.h"
#include"Timer.h"

using namespace std;
void wypisz(int* t, int n) {
	for (size_t i = 0; i < n; i++)
	{
		cout << t[i]<<" ";
	}
	cout << endl;
}
int main() {
	while (1) {
		int n;
		cin >> n;
		int* tablos = new int[n];
		mt19937 uni;
		uni.seed(unsigned(time(0)));
		uniform_int_distribution<int> rand(0, 11);
		for (size_t i = 0; i < n; i++)
		{
			tablos[i] = rand(uni);
		}
		int* tabros = new int[n];
		int* tabmal = new int[n];
		for (size_t i = 0; i < n; i++)
		{
			tabros[i] = tablos[i];
			tabmal[i] = tablos[n - i - 1];
		}
		sort(tabros, tabros + n);
		sort(tabmal, tabmal + n, [](const int & a, const int & b)->bool { return a > b; });
		//zakonczono uzupelnianie tablic
		Time time;
		double czas;
		time.SetStart();
		MergeSort(tabros, 0, n-1);
		time.SetEnd();
		time.GetDuration(&czas);
		cout << "1. " << czas << endl;
		time.SetStart();
		MergeSort(tablos, 0,n-1);
		time.SetEnd();
		time.GetDuration(&czas);
		cout << "2. " << czas << endl;
		time.SetStart();
		MergeSort(tabmal, 0,n-1);
		time.SetEnd();
		time.GetDuration(&czas);
		cout << "3. " << czas << endl;

		//wybieranie(t, 10);
		//babelkowe(t, 10);
		//szybkie(t, 0,9);
		//MergeSort(t, 0, 9);
	}
	
		system("pause");
}