#include <iostream>

class F {
public:
	int f1 = 1;

	virtual void setf1(int f) {
		f1 = f;
	}
};

class E {
public:
	int e1 = 1;

	virtual void sete1(int e) {
		e1 = e;
	}
};

class D {
public:
	int d1 = 1;

	virtual void setd1(int d) {
		d1 = d;;
	}
};

class C : public F {
public:
	int c1 = 1;

	virtual void setc1(int c) {
		c1 = c;
	}
};

class B : public D, public E {
public:
	int b1 = 4;

	virtual int getb1() {
		return b1;
	}
};

class A : public B, public C {
public:
	int a1;

	virtual void seta1(int a) {
		a1 = a;
	}
	virtual int geta1() {
		return a1;
	}
};

int main() {

	A *a = new A();
	B* b = a;
	C *c = a;
	D *d = a;
	E *e = a;
	F *f = a;

	int A::*ptm = &A::a1;
	int B::*ptm1 = &B::b1;
	int C::*ptm2 = &C::c1;
	int D::*ptm3 = &D::d1;
	int E::*ptm4 = &E::e1;
	int F::*ptm5 = &F::f1;

	std::cout << "a:" << "*v-table: " << std::endl << (int)a << std::endl << "fields: " << std::endl << (int)&(a->*ptm) << std::endl
		<< "b:" << "*v-table: " << std::endl << (int)b << std::endl << "fields: " << std::endl << (int)&(b->*ptm1) << std::endl
		<< "c:" << "*v-table: " << std::endl << (int)c << std::endl << "fields: " << std::endl << (int)&(c->*ptm2) << std::endl
		<< "d:" << "*v-table: " << std::endl << (int)d << std::endl << "fields: " << std::endl << (int)&(d->*ptm3) << std::endl
		<< "e:" << "*v-table: " << std::endl << (int)e << std::endl << "fields: " << std::endl << (int)&(e->*ptm4) << std::endl
		<< "f:" << "*v-table: " << std::endl << (int)f << std::endl << "fields: " << std::endl << (int)&(f->*ptm5) << std::endl;

	system("pause");

	return 0;
}