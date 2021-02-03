#include <iostream>

class Pilha
{
	private:
		int *itens;
		int tamanho;
		int topo;
	public:
		Pilha(int);
		~Pilha();
		void setItens(int, int);
		void setTamanho(int);
		void setTopo(int);
		int getItens(int);
		int getTamanho();
		int getTopo();
		void empilhar(int);
		void desempilhar();
		bool isVazia();
		bool isCheia();
		void printBottomUp();
		void printTopDown();
};

int main()
{
	int n, chave;
	char op;
	Pilha *pilha;

	std::cin >> n;

	pilha = new Pilha(n);

	while(std::cin >> op)
	{
		if(op == 'E')
		{
			std::cin >> chave;
			pilha->empilhar(chave);
		}
		else if(op == 'D')
		{
			pilha->desempilhar();
		}
		else if(op == 'T')
		{
			pilha->printTopDown();
		}
		else if(op == 'B')
		{
			pilha->printBottomUp();
		}
	}
}

Pilha::Pilha(int tamanho)
{
	this->setTamanho(tamanho);
	this->setTopo(-1);
	this->itens = new int[this->getTamanho()];
}

Pilha::~Pilha()
{
	delete this->itens;
}

void Pilha::setItens(int chave, int posicao)
{
	this->itens[posicao] = chave;
}

void Pilha::setTamanho(int tamanho)
{	
	this->tamanho = tamanho;
}

void Pilha::setTopo(int n)
{
	this->topo = n;
}
int Pilha::getItens(int posicao)
{
	return this->itens[posicao];
}

int Pilha::getTamanho()
{
	return this->tamanho;
}

int Pilha::getTopo()
{
	return this->topo;
}

void Pilha::empilhar(int chave)
{
	if(!this->isCheia())
	{
		this->setTopo(this->getTopo() + 1);
		this->setItens(chave, this->getTopo());
	}
}

void Pilha::desempilhar()
{
	if(!this->isVazia())
	{
		this->setTopo(this->getTopo() - 1);
	}
}

bool Pilha::isVazia()
{
	if(this->getTopo() == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Pilha::isCheia()
{
	if(this->getTopo() == this->getTamanho() - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Pilha::printBottomUp()
{
	for(int i = 0; i < this->getTopo() + 1; i++)
	{
		std::cout << this->getItens(i) << std::endl;
	}
}

void Pilha::printTopDown()
{
	for(int i = this->getTopo(); i >= 0; i--)
	{
		std::cout << this->getItens(i) << std::endl;
	}
}