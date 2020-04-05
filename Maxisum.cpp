#include <iostream>
using namespace std;

int count(int* a, int n)
{
	int thissum = 0, maxsum = 0;
	for (int i = 0; i < n; i++) {
		thissum += a[i];
		if (thissum < 0)
			thissum = 0;
		if (thissum > maxsum)
			maxsum = thissum;
	}
	return maxsum;
} 
int main()
{
	int n = 0;
	int array[10000];
	int thissum = 0, maxsum = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> array[i];
	cout << count(array, n) << endl;
	return 0;
}