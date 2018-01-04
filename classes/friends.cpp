#include <iostream>
class A
{
private:
	int a;
public:
	A(){a=0;}
	friend class B;
};

class B
{
	int b;
public:
	void showA(A &x)
	{
		std::cout<<"A::a="<<x.a<<std::endl;
	}
};

int main(int argc, char const *argv[])
{
	
	A a;
	B b;
	b.showA(a);
	return 0;
}