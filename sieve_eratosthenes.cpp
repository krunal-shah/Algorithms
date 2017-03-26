#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

void find_primes(bool arr[], int n)
{
	for(int i=0; i<=n; i++)
	{
		arr[i] = false;
	}	
	for(int i=2; i<=sqrt(n); i++)
	{
		if(arr[i] == false)
		{	
			int multiple = 2*i;
			for(; multiple <= n; multiple += i)
			{
				arr[multiple] = true;
			}
		}
	}
}


int main(int argv, char* args[])
{
	int n;
	cin >> n;
	bool arr[n];
	find_primes(arr, n);
	
}
