#include <iostream>

using namespace std;

class box
{
	private:
		

	public:
		int l,b,h;
		box(int l1=1,int b1=1,int h1=1)
		{
			l=l1;
			b=b1;
			h=h1;
		}

		int volume()
		{
			return l*b*h;
		}
		box *next;
};

void printlist(box* head)
	{
		while(head!=NULL)
		{
			cout<<"volume of box is "<<head->volume()<<endl;	
			head=head->next;
		}
	}

int main()
{
	cout<<"linked lists**********\n";
	box b1(1,2,3);
	box b2(3,4,5);
	b1.next=&b2;
	box* head= new box(1,2,3);
	box* second= new box(4,5,6);
	box* third= new box(7,8,9);
	
	head->next=second;
	second->next=third;
	third->next=NULL;

	printlist(head);
	

	

	
	// cout<<"volume of second box is "<<head->volume()<<endl;

	
	// cout<<"volume of third box is "<<head->volume()<<endl;

	

	return 0;
}

