#include<iostream>
#include<ctime>
#include<cstdio>

using namespace std;

void insertion_sort(int v[], int n)
{
	int value;
	int i, j;
	for (i = 1; i < n; i++)
	{
		value = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > value)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = value;
	}
	return;
}

void merge(int v[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int i, j, k;
	int* left = new int[n1 + 1];
	int* right = new int[n2 + 1];
	
	for (i = 0; i < n1; i++)
		left[i] = v[p + i];
	for (j = 0; j < n2; j++)
		right[j] = v[q + 1 + j];
	left[n1] = INT_MAX;
	right[n2] = INT_MAX;
	i = 0;
	j = 0;
	for (k = p; k <= r; k++)
	{
		if (left[i] <= right[j])
		{
			v[k] = left[i];
			i++;
		}
		else
		{
			v[k] = right[j];
			j++;
		}
		//k++;
	}
	delete[] left;
	delete[] right;
}

void merge_sort(int v[], int p, int r)
{
	int q;
	if (p < r)
	{
		int q = (p + r) / 2;
		merge_sort(v, p, q);
		merge_sort(v, q + 1, r);
		merge(v, p, q, r);
		
	}
}

void print_vector(int v[], int n)
{
	int i;
	std::cout << "Vector:";
	for (i = 0; i < n; i++)
		std::cout << " " << v[i];
	std::cout << std::endl;
}

int main()
{
	clock_t startTime, endTime;
	//int intn;
	int n;

	/*cout << "The length of array: " << endl;
	cin >> intn;
	n = intn;*/
	for (int z = 1; z < 10000; z++)
	{
		n = z;
        cout << "n= " << n << endl;

        int* a = new int[n];
		for (int i = 0; i < z; i++)
		{
			a[i] = n;
			n = n - 1;
		}
		n = z;
		//print_vector(a, n);
		startTime = clock();
		insertion_sort(a, n);
		endTime = clock();
		//print_vector(a, n);
		double duration1 = (double)(endTime - startTime)/CLOCKS_PER_SEC;
		cout << "Insertion sort's elapsed time: " << duration1 << " seconds" << endl;
		cout << "Insertion sort start time: " << startTime << endl;
		cout << "Insertion sort end time: " << endTime << endl;
		int* v = new int[n];
		for (int i = 0; i < z; i++)
		{
			v[i] = n;
			n = n - 1;
		}
		n = z;
		//print_vector(v, n);
		startTime = clock();
		merge_sort(v, 0, n - 1);
		endTime = clock();
		//print_vector(v, n);
		double duration2 = (double)(endTime - startTime)/CLOCKS_PER_SEC;
		cout << "Merge sort's elapsed time: " << duration2 << " seconds" << endl;
		cout << "Merge sort start time: " << startTime << endl;
		cout << "Merge sort end time: " << endTime << endl;

		if (duration2 < duration1 && duration1 !=0 && duration2 !=0)
		{
			cout << "The beat n size is: " << n << endl;
            cout << "Insertion sort's elapsed time: " << duration1 << " seconds" << endl;
            cout << "Merge sort's elapsed time: " << duration2 << " seconds" << endl;
			break;
		}	
	}
	return 0;
}