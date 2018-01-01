#include <iostream>

using namespace std;

int main()
{
	int num[10]={0,0,0,1,1,1,0,0,1,0},head=0,tail=0;
	for (int i=0;i<10;i++)
	{
		if (num[i]==1)
			head++;
		else 
			tail++;
	}

	if (head>tail)
		cout<<tail;
	else
		cout<<head;

	return 0;
}