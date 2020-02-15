#include <stdio.h>
#include <stdlib.h>

/*strutura de no guarda dados indefinidos*/
struct nodo{

	void *data;
	struct nodo *next;
};

/*estrutura da pilha com tamanho, nome e ponteiro para o topo da pilha*/
struct stack{
	int size;
	char name;
	struct nodo *top;
};

typedef struct nodo NODO;
typedef struct stack STK;


void incrementStack(STK *stack);
void decrementStack(STK *stack);
void setNext(NODO *previous, NODO *next);
NODO *getNext(NODO *current);
void *getData(NODO *nodo);
void setData(NODO *nodo, void *data);
void setSize(STK *stack);
void setTop(STK *stack, NODO *nodo);
void setName(STK *stack, char name);
NODO *getTop(STK *stack);
NODO *createNodo(void *data);
int lenStack(STK *stack);
void freeNodo(NODO *nodo);

/*cria a pilha vazia, ou retorna nulo na falta de memoria*/
STK *createStack(char name){

	STK *stack = (STK*)malloc(sizeof(STK));

	if(!stack) return NULL;

	setSize(stack);
	setTop(stack, NULL);
	setName(stack, name);

	return stack;

}

/*funcao que insere um elemento no topo da pilha*/
void push(STK *stack, void *data){

	if(!data) return;

	NODO *new = createNodo(data);

	if(!new) return;

	setNext(new, getTop(stack));
	setTop(stack, new);
	incrementStack(stack);

}

/*funcao que retira um elemento no topo da pilha*/
void *pop(STK *stack){


	if(lenStack(stack)){
		
		void *data;
		NODO *top = getTop(stack);
		setTop(stack, getNext(top));
		data = getData(top);
		decrementStack(stack);
		freeNodo(top);
		return data;
	}
	return NULL;
}


/*funcao que inspeciona um elemento no topo da pilha, recebe um ponteiro para funcao que entenda o dado da pilha*/
void *peek(STK *stack, void *(*peekInfo)(void*)){

	if(lenStack(stack)){
		void *data = peekInfo(getData(getTop(stack)));
		return data;
	}
	return NULL;
}

/*funcao que imprime todos os elementos da pilha, recebe ponteiro para funcao que interprete o elemento*/
void print(STK *stack, void (*printInfo)(void*)){

	if(stack){

		NODO *temporary;

		for(temporary = getTop(stack); temporary != NULL; temporary = getNext(temporary)){
			printInfo(getData(temporary));
		}
	}
}

/*funcao que retorna o tamanho da pilha*/
int lenStack(STK *stack){

	return stack->size;
}

/*funcao que incrementa o tamanho da pilha*/
void incrementStack(STK *stack){

	if(stack){
		stack->size++;
	}
}

/*funcao que decrementa o tamanho da pilha*/
void decrementStack(STK *stack){

	if(stack){
		stack->size--;
	}
}

/*funcao que aponta o no atual para o proximo*/
void setNext(NODO *previous, NODO *next){

	previous->next = next;
}

/*retorna o proximo no*/
NODO *getNext(NODO *current){

	return current->next;
}

/*retorna um ponteiro para um dado indefinido*/
void *getData(NODO *nodo){

	if(nodo){
		return nodo->data;
	}
	return nodo;
}

/*no aponta para um dado indefinido*/
void setData(NODO *nodo, void *data){
	if(nodo){
		nodo->data = data;
	}
}

/*seta o tamanho da pilha para zero*/
void setSize(STK *stack){
	if(stack){
		stack->size = 0;
	}
}

/*seta o topo da pilha*/
void setTop(STK *stack, NODO *nodo){
	if(stack){
		stack->top = nodo;
	}
}

/*seta um nome para pilha, de um caracter*/
void setName(STK *stack, char name){
	if(stack){
		stack->name = name;
	}
}

/*retorna o nome da pilha*/
char getName(STK *stack){

	return stack->name;
}
/*retorna o topo da pilha, funcao interna*/
NODO *getTop(STK *stack){
	if(stack){
		return stack->top;
	}
	return NULL;
}

/*recebe um ponteiro para um dado, cria um no, e o no aponta para esse dado*/
NODO *createNodo(void *data){

	NODO *new = (NODO*)malloc(sizeof(NODO));

	if(!new) return NULL;

	setData(new, data);
	setNext(new, NULL);

	return new;
}

/*libera as memorias alocadas*/
void freeStack(STK *stack, void (*freeInfo)(void*)){

	NODO *temporary = getTop(stack);
	NODO *previous = NULL;

	while(temporary){
		previous = temporary;
		temporary = getNext(temporary);
		freeInfo(getData(previous));
		free(previous);
	}
	free(stack);
}

/*funcao que libera a memoria alocada para o nodo*/
void freeNodo(NODO *nodo){
	free(nodo);
}