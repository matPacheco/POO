#include <iostream>

struct tComplex
{
	int real, imaginario;
};

struct tComplex complexo(int, int);
struct tComplex soma(struct tComplex, struct tComplex);
struct tComplex sub(struct tComplex, struct tComplex);
struct tComplex mult(struct tComplex, struct tComplex);
struct tComplex div(struct tComplex, struct tComplex);

int main()
{
	int a, b, c, d;
	char lixo, op;
	struct tComplex q1, q2, resultado;

	while(std::cin >> a, b, lixo, op, c, d, lixo)
	{
		q1 = complexo(a, b);
		q2 = complexo(c, d);


	}	
}

struct tComplex complexo(int real, int imaginario)
{
	struct tComplex ptComplex;

	ptComplex.real = real;
	ptComplex.imaginario = imaginario;

	return ptComplex;
}

struct tComplex soma(struct tComplex q1, struct tComplex q2)
{
	struct tComplex ptComplex;

	ptComplex.real = q1.real + q2.real;
	ptComplex.imaginario = q1.imaginario + q2.imaginario;

	return ptComplex;
}

struct tComplex sub(struct tComplex q1, struct tComplex q2)
{
	struct tComplex ptComplex;

	ptComplex.real = q1.real + q2.imaginario;
	ptComplex.imaginario = q1.imaginario + q2.real;

	return ptComplex;
}

struct tComplex mult(struct tComplex q1, struct tComplex q2)
{
	struct tComplex ptComplex;

	ptComplex.real = (q1.real * q1.real) - (q1.imaginario * q2.imaginario);
	ptComplex.imaginario = (q1.real * q2.imaginario) + (q1.imaginario * q2.real);

	return ptComplex;
}

struct tComplex div(struct tComplex q1, struct tComplex q2)
{
	struct tComplex ptComplex;

	
}