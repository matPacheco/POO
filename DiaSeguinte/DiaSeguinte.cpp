#include <iostream>

class Data
{
    private:
        int dia, mes, ano;
    public:
        Data(int, int, int);
        void setDia(int);
        void setMes(int);
        void setAno(int);
        int getDia();
        int getMes();
        int getAno();
        bool isBissexto();
        bool isValida();
};

int main()
{
    int d, m, a, n, i = 0;

    std::cin >> n;

    while(i < n){
        std::cin >> d >> m >> a;

        Data data(d, m, a);
        
        if (data.isValida())
        {
            std::cout << "DATA VALIDA" << std::endl;
        }
        else
        {
            std::cout << "DATA INVALIDA" << std::endl;    
        }

        i++;
    }
}

Data::Data(int dia, int mes, int ano)
{
    this->setDia(dia);
    this->setMes(mes);
    this->setAno(ano);
}

void Data::setDia(int dia)
{
    this->dia = dia;
}

void Data::setMes(int mes)
{
    this->mes = mes;
}

void Data::setAno(int ano)
{
    this->ano = ano;
}

int Data::getDia()
{
    return this->dia;
}

int Data::getMes()
{
    return this->mes;
}

int Data::getAno()
{
    return this->ano;
}

bool Data::isBissexto()
{
    if (this->getAno() % 400 == 0)
    {
        return true;
    }
    else if (this->getAno() % 100 != 0 && this->getAno() % 4 == 0)
    {
        return true;
    }
    return false;
}

bool Data::isValida()
{
    if (this->getDia() > 31 || this->getMes() > 12)
    {
        return false;
    }
    else
    {
        if (this->getDia() == 31 && (this->getMes() == 2 || this->getMes() == 4 || this->getMes() == 6 || this->getMes() == 9 || this->getMes() == 11))
        {
            return false;
        }
        else if (this->getMes() == 2)
        {
            if (this->getDia() == 30)
            {
                return false;
            }
            else if (this->getDia() == 29)
            {
                if (!this->isBissexto())
                {
                    return false;
                }
            }
        }
    }
    return true;
}