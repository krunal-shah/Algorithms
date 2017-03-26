#include <iostream>
#include <string.h>
using namespace std;

void mergesort(int a[], int start, int end, int ans[], int n)
{
	if(start + 1 < end)
	{
		int mid = (start + end)/2;
		mergesort(a, start, mid, ans, n);
		mergesort(a, mid+1, end, ans, n);
		int i=start, j=mid+1;
		int k=start;
		while(i<=mid && j<=end)
		{
			if(a[i] > a[j])
			{
				ans[k] = a[j];
				j++;
				k++;
			}
			else
			{
				ans[k] = a[i];
				i++;
				k++;
			}
		}
		if(i > mid && k <= end)
		{
			while(k <= end)
			{
				ans[k] = a[j];
				j++;
				k++;
			}
		}
		else if(j > end && k <= end)
		{
			while(k <= end)
			{
				ans[k] = a[i];
				i++;
				k++;
			}
		}

		for(int i=start; i<=end; i++)
		{
			a[i] = ans[i];
		}
	}
	else if(start + 1 == end)
	{
		if(a[start] > a[end])
		{
			int temp = a[start];
			a[start] = a[end];
			a[end] = temp;
		}
	}
	else
	{
		ans[start] = a[start];
	}
}

int main(int argv, char* args[])
{
	int n;
	cout << "Enter the number of objects:";
	cin >> n;
	cout << "Enter the numbers:";
	int* array = new int[n];
	int* ans = new int[n];
	for(int i=0; i<n; i++)
	{
		cin >> array[i];
		ans[i] = array[i];
	}
	mergesort(array, 0, n-1, ans, n);
	for(int i=0; i<n; i++)
	{
		cout << array[i] << ", ";
	}
	cout << endl;
}
