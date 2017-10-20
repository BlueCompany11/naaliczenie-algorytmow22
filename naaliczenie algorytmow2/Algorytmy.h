#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

void wstawianie(int* t,int n);
void wybieranie(int* t, int n);
void babelkowe(int* t, int n);
void sps(int tab[], int pom[], int lewy, int prawy);
void szybkie(int* t,int l, int p);

void wstawianie(int* t, int n) {
	int j, temp;
	for (int i = 1;i < n;i++) { //pozycja 0 juz posortowana
		j = i;
		temp = t[j];
		while ((j > 0) && t[j - 1] > temp) {	//przesuwanie miejsc w tablicy
			t[j] = t[j - 1];
			j--;
		}
		t[j] = temp;
	}
}

void wybieranie(int* t, int n) {
	int k,x;
	for (int i = 0;i < n;++i) {
		k = i;
		for (int j = i + 1;j < n;++j) {
			if (t[j] < t[k]) {
				k = j;
			}
		}
		swap(t[i], t[k]);
	}
}

void babelkowe(int* t, int n) {
	int temp;
	for (int i = 1;i < n;i++) {
		for (int j = n - 1;j >= i;j--) {
			if (t[j] < t[j - 1]) {
				temp = t[j - 1];
				t[j - 1] = t[j];
				t[j] = temp;
			}
		}
	}
}

void szybkie2(int* t, int l, int p) {
	int i, j, x, w;
	i = l;
	j = p;
	x = t[l];	//modyfikacja
	do{
		while (t[i] < x) {
			i = i + 1;
		}
		while (t[j] > x) {
			j = j - 1;
		}
		if (i <= j) {
			w = t[i];
			t[i] = t[j];
			t[j] = w;
			i++;
			j--;
		}
	} while (i > j);
	if (l < j)
		szybkie2(t, l, j);
	if (i < p)
		szybkie2(t, i, p);
}
int compare(const void* a, const void* b) {
	return (*(int*)a - *(int*)b);
}
void szybkie3(int* t, int n) {
	qsort(t, n, sizeof(int), compare);
}

void szybkie(int* t, int l, int p) {
	if (l < p) {
		int m = (int)((l+p)/2);
		for (int i = l+1; i <= p; i++)
		{
			if (t[i] < t[l]) {
				swap(t[++m], t[i]);
			}
		}
		swap(t[l], t[m]);
		szybkie(t, l, m - 1);
		szybkie(t, m + 1, p);
	}
}

int partition(int tablica[], int p, int r) // dzielimy tablice na dwie czesci, w pierwszej wszystkie liczby sa mniejsze badz rowne x, w drugiej wieksze lub rowne od x
{
	int x = tablica[p]; // obieramy x
	//int x = tablica[(p + r) / 2];
	int i = p, j = r, w; // i, j - indeksy w tabeli
	while (true) // petla nieskonczona - wychodzimy z niej tylko przez return j
	{
		while (tablica[j] > x) // dopoki elementy sa wieksze od x
			j--;
		while (tablica[i] < x) // dopoki elementy sa mniejsze od x
			i++;
		if (i < j) // zamieniamy miejscami gdy i < j
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else // gdy i >= j zwracamy j jako punkt podzialu tablicy
			return j;
	}
}

void quicksort(int tablica[], int p, int r) // sortowanie szybkie
{
	int q;
	if (p < r)
	{
		q = partition(tablica, p, r); // dzielimy tablice na dwie czesci; q oznacza punkt podzialu
		quicksort(tablica, p, q); // wywolujemy rekurencyjnie quicksort dla pierwszej czesci tablicy
		quicksort(tablica, q + 1, r); // wywolujemy rekurencyjnie quicksort dla drugiej czesci tablicy
	}
}

void scal(int tab[], int pom[], int lewy, int srodek, int prawy) {
	int i = lewy;
	int j = srodek + 1;
	for (size_t i = lewy; i <= prawy; i++)
	{
		pom[i] = tab[i];
	}
	for (int k = lewy;k <= prawy;k++) {
		if (i <= srodek) {
			if (j <= prawy) {
				if (pom[j] < pom[i]) {
					tab[k] = pom[j++];
				}
				else 
				{
					tab[k] = pom[j++];
				}
			}
			else
			{
				tab[k] = pom[i++];
			}
		}
		else
		{
			tab[k] = pom[j++];
		}
	}
}
void sps(int tab[], int pom[], int lewy, int prawy) {
	if (lewy >= prawy) return;
	int srodek = (lewy + prawy) / 2;
	sps(tab, pom, lewy, srodek);
	sps(tab, pom, srodek + 1, prawy);
	scal(tab, pom, lewy, srodek, prawy);
}
// A function to merge the two half into a sorted data.
void Merge(int *a, int low, int high, int mid)
{
	// We have low to mid and mid+1 to high already sorted.
	int i, j, k;
	int* temp = new int[high - low + 1];
	i = low;
	k = 0;
	j = mid + 1;

	// Merge the two parts into temp[].
	while (i <= mid && j <= high)
	{
		if (a[i] < a[j])
		{
			temp[k] = a[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = a[j];
			k++;
			j++;
		}
	}

	// Insert all the remaining values from i to mid into temp[].
	while (i <= mid)
	{
		temp[k] = a[i];
		k++;
		i++;
	}

	// Insert all the remaining values from j to high into temp[].
	while (j <= high)
	{
		temp[k] = a[j];
		k++;
		j++;
	}


	// Assign sorted data stored in temp[] to a[].
	for (i = low; i <= high; i++)
	{
		a[i] = temp[i - low];
	}
}

// A function to split array into two parts.
void MergeSort(int *a, int low, int high)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		// Split the data into two half.
		MergeSort(a, low, mid);
		MergeSort(a, mid + 1, high);

		// Merge them to get sorted output.
		Merge(a, low, high, mid);
	}
}
