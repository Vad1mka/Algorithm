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
	do {

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
	} while (i <= j);
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
	srand(time(NULL));
	int n, k1, z;
	cout << "Enter the number of items : ";
	cin >> n;
	int *a = new int[n];
	int *b = new int[n];
	{
		cout << "Array 1 : " << endl << endl;
		for (int i = 0; i < n; i++)
		{
			a[i] = rand() % 10;
			cout << a[i] << " ";
		}
		cout << endl << endl;
		cout << "Array 2 : " << endl << endl;
		for (int i = 0; i < n; i++)
		{
			b[i] = rand() % 10;
			cout << b[i] << " ";
		}
		cout << endl << endl;
	}
	Hoar_Sort(n, a);
	Hoar_Sort(n, b);
	ofstream file("D:\\Task2.txt", ios_base::trunc);
	file << "Array 1 : ";
	for (int i = 0; i < n; i++)
	{
		file << a[i] << " ";
	}
	file << endl;
	file << "Array 2 : ";
	for (int i = 0; i < n; i++)
	{
		file << b[i] << " ";
	}
	file << endl;
	cout << "Choose a solution :" << endl << "1) C = A _ B  " << endl << "2) C = A U B" << endl << "3) C = A / B  " << endl << "4) C = (A/B) U (B/A)" << endl << endl;
	int k2;
	cin >> k2;


	switch (k2)
	{
		case 1:
		{
			file << "C = A _ B : " << endl;
			cout << endl;
			for (int i = 0; i<n; i++) 
			{
				for (int i2 = 0; i2<n; i2++) 
				{
					if (a[i] == b[i2])
					{
						cout << a[i] << " ";
						file << a[i];
					}
				}
			}
		}
		cout << endl;
		break;
		case 2:
		{
			file << endl << "C= A U B : " << endl;
			cout << endl;
			for (int i = 0; i<n; i++)
			{
				cout << a[i] << " ";
				file << a[i];
			}
			file << " ";
			for (int j = 0; j<n; j++)
			{
				cout << b[j] << " ";
				file << b[j];
			}
		}
		file << endl;
		cout << endl << endl;
		break;
		case 3:
		{
			file << endl << "C = A / B : ";
			cout << endl;
			for (int i = 0; i < n; i++)
			{
				for (int i2 = 0; i2 < n; i2++)
				{
					if (a[i] != b[i2])
					{
						cout << a[i] << " ";
						file << a[i];
					}
				}
				file << endl;
				cout << endl << endl;
				break;
			}
		}
		case 4:
		{
			file << endl << "C = (A/B) U (B/A) : ";
			cout << endl;
			for (int i = 0; i<n; i++) 
			{
				for(int i2 = 0; i2<n; i2++) 
				{	
					if (a[i] != b[i2] && b[i2] != a[i])
					{
						cout << a[i] << " ";
						file << a[i];
					}
				}
				file << endl;
				cout << endl << endl;
				break;
			}
		}
	}
	file.close();
	system("pause");
}
