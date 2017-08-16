
/*
 Definição de funções para listas contendo itens quadruplamente encadeados
 Este tipo de lista será utilizado para implementar uma matriz esparsa.
 Cada item é da forma:

		 ^
	     | 
	->[item]->
		|
	    v
*/

typedef struct _Item Item;
typedef struct _Lista Lista;


struct _Item
{
	long i,j;
	float valor;
	
	Item* prox;
	Item* ant;
	
	Item* acima;
	Item* abaixo;
};


struct _Lista
{
	Item* inicio;
	Item* fim;
	int tamanho;
};

//------------------------------------------------------------------------------
/*
 Aloca memória para uma estrutura representando uma lista e define valores 
 iniciais para os itens da estrutura.
*/
Lista* novaLista();


/*
 Aloca memória para uma estrutura representando um item de lista e define valores iniciais para os itens da estrutura.
*/
Item* novoItem(long i, long j, float value);

void inserirInicioLinha(Lista* l, Item* novo);
void inserirInicioColuna(Lista* l, Item* novo);

// Insere um novo item depois do item atual 
void inserirProximoLinha(Lista* l, Item* atual, Item* novo);
void inserirProximoColuna(Lista* l, Item* atual, Item* novo);

void inserirFimLinha(Lista* l, Item* novo);
void inserirFimColuna(Lista* l, Item* novo);

void freeLista(Lista* l);




