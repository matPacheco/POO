#include <iostream>

class Racional
{
	private:
		int numerador;
		int denominador;
	public:
		Racional(int, int);
		void setNumerador(int);
		void setDenominador(int);
		int getNumerador();
		int getDenominador();
		void negativo();
		void soma(Racional);
		void produto(Racional);
		void quociente(Racional);
		void simplifica();
};

int calculaGcd(int, int);

int main()
{
	
	int n1, n2, d1, d2;
	char op;

	while(std::cin >> n1 >> d1 >> op >> n2 >> d2)
	{
		Racional q1(n1, d1), q2(n2, d2);

		if(op == '+')
        {
            q1.soma(q2);
        }
        else if(op == '-')
        {
            q2.negativo();
            q1.soma(q2);
        }
        else if(op == '*')
        {
            q1.produto(q2);
        }
        else if(op == '/')
        {
            q1.quociente(q2);
        }
        
        q1.simplifica();
        
        std::cout << q1.getNumerador() << " " << q1.getDenominador() << std::endl;
	}
}

Racional::Racional(int numerador, int denominador)
{
	this->setNumerador(numerador);
	this->setDenominador(denominador);
}

void Racional::setNumerador(int n)
{
	this->numerador = n;
}

void Racional::setDenominador(int n)
{
	this->denominador = n;
}

int Racional::getNumerador()
{
	return this->numerador;
}

int Racional::getDenominador()
{
	return this->denominador;
}

void Racional::negativo()
{
	this->setNumerador(-this->getNumerador());
}

void Racional::soma(Racional q2)
{
	int numerador1, numerador2, denominador1, denominador2;

	numerador1 = this->getNumerador();
	denominador1 = this->getDenominador();
	numerador2 = q2.getNumerador();
	denominador2 = q2.getDenominador();

	if (denominador1 == denominador2)
    {
        this->setNumerador(numerador1 + numerador2);
        this->setDenominador(denominador1);
    }
    else
    {
        int gcd = calculaGcd(denominador1, denominador2);
        this->setDenominador((denominador1 * denominador2) / gcd);
        this->setNumerador(((this->getDenominador()/denominador1) * numerador1) + ((this->getDenominador()/denominador2) * numerador2));
        
    }
}

void Racional::produto(Racional q2)
{
	this->setNumerador(this->getNumerador() * q2.getNumerador());
    this->setDenominador(this->getDenominador() * q2.getDenominador());
}

void Racional::quociente(Racional q2)
{
	this->setNumerador(this->getNumerador() * q2.getDenominador());
    this->setDenominador(this->getDenominador() * q2.getNumerador());
}

void Racional::simplifica()
{
	int gcd = calculaGcd(this->getNumerador(), this->getDenominador());
    
    this->setNumerador(this->getNumerador() / gcd);
    this->setDenominador(this->getDenominador() / gcd);
}

int calculaGcd(int a, int b)
{
    if (a < 0)
    {
        a = -a;
    }
    if (b < 0)
    {
        b = -b;
    }
    
    int aux;
    while(b != 0)
    {
        aux = b;
        b = a % b;
        a = aux;
    }
   
    return a;
}