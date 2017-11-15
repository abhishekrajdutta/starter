#include <iostream>

using namespace std;

class student
{
	private:
		int num;

	public:
		student(int x)
		{
			num=x;
		}

		void print()
		{
			cout<<num<<"\n";
		}
};


int main()
{
	cout<<"hello world\n";
	student s1(2);
	s1.print();

	return 0;
}

