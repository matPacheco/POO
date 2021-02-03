#include <iostream>

class Racional
{
	private:
		int numerador;
		int denominador;
	public:
        Racional();
		Racional(int, int);
		void setNumerador(int);
		void setDenominador(int);
		int getNumerador();
		int getDenominador();
		Racional operator - (Racional);
		Racional operator + (Racional);
		Racional operator * (Racional);
		Racional operator / (Racional);
		void simplifica();
};

int calculaGcd(int, int);

int main()
{
	
	int n1, n2, d1, d2;
	char op;

	while(std::cin >> n1 >> d1 >> op >> n2 >> d2)
	{
		Racional q1(n1, d1), q2(n2, d2), r;

		if(op == '+')
        {
            r = q1 + q2;
        }
        else if(op == '-')
        {
            r = q1 - q2;
        }
        else if(op == '*')
        {
            r = q1 * q2;
        }
        else if(op == '/')
        {
            r = q1 / q2;
        }
        
        r.simplifica();
        
        std::cout << r.getNumerador() << " " << r.getDenominador() << std::endl;
	}
}

Racional::Racional(int numerador, int denominador)
{
	this->setNumerador(numerador);
	this->setDenominador(denominador);
}

Racional::Racional()
{    
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

Racional Racional::operator - (Racional q2)
{
 	Racional r;
    int numerador1, numerador2, denominador1, denominador2;

    numerador1 = this->getNumerador();
    denominador1 = this->getDenominador();
    numerador2 = q2.getNumerador();
    denominador2 = q2.getDenominador();

    if (denominador1 == denominador2)
    {
        r.setNumerador(numerador1 - numerador2);
        r.setDenominador(denominador1);
    }

    else
    {
        int gcd = calculaGcd(denominador1, denominador2);
        r.setDenominador((denominador1 * denominador2) / gcd);
        r.setNumerador(((r.getDenominador()/denominador1) * numerador1) - ((r.getDenominador()/denominador2) * numerador2));
        
    }
    return r;
}

Racional Racional::operator + (Racional q2)
{
  Racional r;
	int numerador1, numerador2, denominador1, denominador2;

	numerador1 = this->getNumerador();
	denominador1 = this->getDenominador();
	numerador2 = q2.getNumerador();
	denominador2 = q2.getDenominador();

	if (denominador1 == denominador2)
    {
        r.setNumerador(numerador1 + numerador2);
        r.setDenominador(denominador1);
    }

    else
    {
        int gcd = calculaGcd(denominador1, denominador2);
        r.setDenominador((denominador1 * denominador2) / gcd);
        r.setNumerador(((r.getDenominador()/denominador1) * numerador1) + ((r.getDenominador()/denominador2) * numerador2));
        
    }
    return r;
}

Racional Racional::operator * (Racional q2)
{
    Racional r;
	r.setNumerador(this->getNumerador() * q2.getNumerador());
    r.setDenominador(this->getDenominador() * q2.getDenominador());
    return r;
}

Racional Racional::operator / (Racional q2)
{
    Racional r;
	r.setNumerador(this->getNumerador() * q2.getDenominador());
    r.setDenominador(this->getDenominador() * q2.getNumerador());
    return r;
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