#include <iostream>

using namespace std;

class box
{
	private:
		

	public:
		int l,b,h;
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

		box* next;

};


int main()
{
	cout<<"pointers to classes**********\n";
	box b1(1,2,3);
	box b2(3,4,5);

	box* head=&b1;
	box* first;
	first=b1->next;
	
	// box* second;
	// box* third;

	// first->l=2;
	// first->b=4;
	// first->h=3;

	// second->l=3;
	// second->b=4;
	// second->h=5;

	// third->l=6;
	// third->b=7;
	// third->h=8;

	// head->next=first;
	// first->next=second;
	// second->next=third;
	// third->next=NULL;
	// cout<<head->volume();

	



	return 0;
}

