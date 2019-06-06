#include <iostream>

class I {
public:
	int i;
	virtual int geti() {
		return i;
	}
};

class C: public I{
public:
	int c1;
	int c2;

public:
	virtual void setc1(int c) {
		c1 = c;
	}
};

class B: public I{
public:
	int b1;
	int b2;

public:
	virtual int getb1() {
		return b1;
	}
};

class A: public B, public C {
public:
	int a2;
	int a1;

public:
	virtual void seta1(int a) {
		a1 = a;
	}
	virtual void seta2(int a) {
		a2 = a;
	}
};

int main() {

	A *a = new A();
	B *b = a;
	C *c = a;

	int A::*ptm = &A::a1;
	int A::*ptm1 = &A::a2;
	int B::*ptm2 = &B::b1;
	int B::*ptm3 = &B::b2;
	int C::*ptm4 = &C::c1;
	int C::*ptm5 = &C::c2;
	int I::*ptm6 = &I::i;

	std::cout << "a:" << std::endl << "*v-table: " << (int)a << std::endl << "fields: " << std::endl << (int)&(a->*ptm) << std::endl << (int)&(a->*ptm1) << std::endl
		<< "b:" << std::endl << "*v-table: " << (int)b << std::endl << "fields: " << std::endl << (int)&(b->*ptm2) << std::endl << (int)&(b->*ptm3) << std::endl
		<< "c:" << std::endl << "*v-table: " << (int)c << std::endl << "fields: " << std::endl << (int)&(c->*ptm4) << std::endl << (int)&(c->*ptm5) << std::endl
		<< "i_b:" << std::endl << "--------" << std::endl << "fields: " << std::endl << (int)&(b->*ptm6) << std::endl
		<< "i_c:" << std::endl << "--------" << std::endl << "fields: " << std::endl << (int)&(c->*ptm6) << std::endl;

	system("pause");

	return 0;
}