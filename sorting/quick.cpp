#include <iostream>
using namespace std;

/*Things to explore:
1. C++ vectors
2. 
*/

void arrprint(int a[])
{
	for(int i=0;i<10;i++)
		cout<<a[i]<<" ";

	cout<<endl;
}

void swap(int a[],)

void partition(arr,low,high)
{
	int pivot=arr[high];
	int i=low-1;

}


void quicksort(int a[],int left, int right)
{
	pi = partition(arr, low, high);
	quicksort(arr, left, pi-1);
	quicksort(arr, pi+1,right);

}

int main()
{
	int arr[10]={100,2,4,7,8,3,9,3,2,6};
	int temp[10]={100,2,4,7,8,3,9,3,2,6};
	arrprint(arr);
	// quicksort(arr);
	quicksort(arr,temp,0,9);
	cout<<"sorted array: ";
	arrprint(arr);
	return 0;
}