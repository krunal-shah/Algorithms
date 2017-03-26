#include <iostream>
#include <string.h>
using namespace std;

void compute(string str, int n, int z[], int l)
{
	if(l<=n)
	{
		cout << "l put on as "<< l << endl;
		int r, j;
		for(r=l, j=0; r<n && j<n; r++, j++)
		{
			if(str[r] == str[j])
			{

			}
			else
			{
				break;
			}
		}
		cout << "r is " << r << endl;
		z[l] = r-l;
		for(int i=l+1; i<=r; i++)
		{
			if(z[i-l] <= r-i)
			{
				z[i] = z[i-l];
			}
			else
			{
				compute(str, n, z, i);
			}
		}
		compute(str, n, z, r+1);
		
	}
	else
	{

	}
}


int main(int argv, char* args[])
{
	cout << "Enter the string:";
	string str;
	getline(cin, str);
	int n = str.length();
	int z[n];
	z[0] = n;
	compute(str, n, z, 1);
	cout << "z is"<<endl;
	for(int i=0; i<n; i++)
	{
		cout << z[i] << endl;
	}
}
