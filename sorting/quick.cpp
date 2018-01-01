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

void merger(int arr[],int temp[], int l,int m,int r)
{	
	// for (int i=l;i<=r;i++)
	// 	cout<<l<<"*"<<m<<"*"<<r<<"   ";
	// cout<<e,,"ndl;
	int first=l;
	int second=m+1;
	// cout<<arr[first]<<"\t"<<arr[second]<<"\t"<<endl;
	for (int i=l;i<=r;i++)
	{
		if (arr[first]<=arr[second] && first<=m && second<=r )
		{
			temp[i]=arr[first];
			first++;					
		}

		else if (arr[first]>arr[second] && first<=m && second<=r)
		{
			temp[i]=arr[second];
			second++;		
			cout<<temp[0];
		}
		
		else if (first>m)
		{
			temp[i]=arr[second];
		}

		else if (second>r)
		{
			temp[i]=arr[first];
		}
	}

	for (int i=l;i<=r;i++)
	{
		arr[i]=temp[i];
		cout<<temp[i];
	}
	cout<<"\nmerged\n";
	

}

void mergesort(int a[],int temp[],int left,int right)
{
	if (left>=right)
		return;
	int mid=left+(right-left)/2;
	mergesort(a,temp,left,mid);
	// cout<<right<<endl;
	mergesort(a,temp,mid+1,right);
	// cout<<2<<endl;
	merger(a,temp,left,mid,right);
}


void quicksort(int a[])
{

}

int main()
{
	int arr[10]={100,2,4,7,8,3,9,3,2,6};
	int temp[10]={100,2,4,7,8,3,9,3,2,6};
	arrprint(arr);
	// quicksort(arr);
	mergesort(arr,temp,0,9);
	cout<<"sorted array: ";
	arrprint(arr);
	return 0;
}