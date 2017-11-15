#include <iostream>

using namespace std;

class box
{
	private:
		int l,b,h;

	public:
		box(int l1,int b1,int h1)
		{
			l=l1;
			b=b1;
			h=h1;
		}

		int volume()
		{
			return l*b*h;
		}
};


int main()
{
	cout<<"pointers to classes**********\n";
	box b1(1,2,3);
	box b2(3,4,5);
	box *boxptr;

	boxptr=&b1;
	cout<<"volume of first box is "<<boxptr->volume()<<endl;

	boxptr=&b2;
	cout<<"volume of second box is "<<boxptr->volume()<<endl;

	return 0;
}

