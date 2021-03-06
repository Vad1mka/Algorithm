#include <stdio.h>
#include <iostream>
#include <time.h>
#include <fstream>

using namespace std;

void Exchange(int i, int j, int *x) 
{
	int tmp;
	tmp = x[i];
	x[i] = x[j];
	x[j] = tmp;
}

void Quick_Sort(int left, int right, int *x) 
{
	int i, j, m, h;
	i = left;
	j = right;
	m = x[(i + j + 1) / 2];
	do 
	{
		while (x[i] < m) i++;
		{
			while (x[j] > m) j--;
			{
				if (i <= j)
				{
					Exchange(i, j, x);
					i++;
					j--;
				}
			}
		}
	} 
	while (i <= j);
	{
		if (left < j)
		{
			Quick_Sort(left, j, x);
		}
		if (i < right)
		{
			Quick_Sort(i, right, x);
		}
	}
}

void Hoar_Sort(int k, int *x) 
{
	Quick_Sort(0, k - 1, x);
}

int main() 
{
	int n, k1, z;
	cout << "Amount of elements : ";
	cin >> n;
	int *a = new int[n];
	srand(time(0));
	ofstream file("D:\\Task4.txt", ios_base::trunc);
	file << "Initial Array" << endl;
	cout << "Initial Array" << endl;
	for (int i = 0; i<n; i++) 
	{
		a[i] = rand() % n;
		cout << a[i] << " ";
		file << a[i] << " ";
	}
	Hoar_Sort(n, a);
	cout << endl;
	file << "No repetition" << endl;
	cout << "No repetition" << endl;
	for (int i = 0; i<n; i++) 
	{
		bool flag = true;
		for (int j = 0; j < n; j++)
		{
			if (i - j != 0 && a[i] == a[j])

			{

				flag = false;

			}

			if (flag) {
				cout << a[i] << " ";

				file << a[i] << " ";

			}
		}
	}
	cout << endl;
	file << endl;
	file.close();
	system("pause");
}
