#include <iostream>

class Fila
{
	private:
		int *itens;
		int inicio, final;
		int tamanho;
	public:
		Fila(int);
		~Fila();
		void setInicio(int);
		void setFinal(int);
		void setTamanho(int);
		void setItens(int, int);
		int getInicio();
		int getFinal();
		int getTamanho();
		int getItens(int);
		void enfileirar(int);
		int desenfileirar();
		bool isVazia();
		bool isCheia();
};

int main()
{
	Fila *fila;
	int n, chave;
	char op;

	std::cin >> n;
	fila = new Fila(n);
	while(std::cin >> op)
	{
		if(op == 'E')
		{
			std::cin >> chave;
			fila->enfileirar(chave);
		}
		else
		{
      if(!fila->isVazia())
      {
			  std::cout << fila->desenfileirar() << std::endl;
      }
		}
	}
	delete fila;
}

Fila::Fila(int tamanho)
{
	this->setTamanho(tamanho);
	this->setInicio(-1);
	this->setFinal(-1);
	this->itens = new int[this->getTamanho()];
}

Fila::~Fila()
{
	delete this->itens;
}

void Fila::setInicio(int inicio)
{
	this->inicio = inicio;
}

void Fila::setFinal(int final)
{
	this->final = final;
}

void Fila::setTamanho(int tamanho)
{
	this->tamanho = tamanho;
}

void Fila::setItens(int item, int posicao)
{
	this->itens[posicao] = item;
}

int Fila::getInicio()
{
	return this->inicio;
}

int Fila::getFinal()
{
	return this->final;
}
int Fila::getTamanho()
{
	return this->tamanho;
}

int Fila::getItens(int posicao)
{
	return this->itens[posicao];
}

void Fila::enfileirar(int chave)
{
	if(!this->isCheia())
	{
		if(this->isVazia())
		{
			this->setInicio(0);
		}
		this->setFinal(this->getFinal() + 1);
		this->setItens(chave, this->getFinal());
	}
}

int Fila::desenfileirar()
{
	if(!this->isVazia())
	{
		int excluido = this->getItens(this->getInicio());
    this->setInicio(this->getInicio() + 1);
		if(this->getInicio() == this->getFinal() + 1)
		{
			delete this->itens;
			this->setInicio(-1);
			this->setFinal(-1);
			this->itens = new int[this->getTamanho()];
		}
		return excluido;
	}
  return 0;
}

bool Fila::isVazia()
{
	if(this->getInicio() == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool Fila::isCheia()
{
	if(this->getFinal() == this->getTamanho() - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}