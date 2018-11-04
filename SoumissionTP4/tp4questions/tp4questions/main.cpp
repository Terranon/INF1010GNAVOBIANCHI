#include <string>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
class A {
public:
	void f() const { cout << 1; }
};
class B : public A {
public:
	void f() const { cout << 2; }
};
class C : public B {
public:
	void f() const { B::f(); }
};
int main()
{
	vector<B*> v;
	C b;
	v.push_back(&b);
	v[0]->f();
		return 0;
}