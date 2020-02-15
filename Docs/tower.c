#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct disk{
	int size;
};

typedef struct disk DISK;


void printConfig(STK *pinStackA, STK *pinStackB, STK *pinStackC, int flag);
void showDisks(void *sizeDisk);
void solveEven(STK *pinStackA, STK *pinStackB, STK *pinStackC, int flag);
void solveOdd(STK *pinStackA, STK *pinStackB, STK *pinStackC, int flag);
void moveStack(STK *pinStack_1, STK *pinStack_2, int flag);
void *getValue(void *object);
void freeDisk(void *disk);

/*cria um disco e retorna seu ponteiro*/
DISK *ceateDisk(int size){

	DISK *disk = (DISK*)malloc(sizeof(DISK));
	disk->size = size;

	return disk;
}
/*retorna o tamanho do disco*/
int getSizeDisk(DISK *disk){
	return disk->size;
}
/*funcao que eh passada como parametro para a funcao peek da pilha e retorna um ponteiro*/
void *getValue(void *object){
	DISK *temporary = (DISK*)object;	
	return &temporary->size;	
}
/*funcao que printa na tela o movimento feito*/
void printMov(int *disco, char origem, char destino){
	printf("   Move disk %d from %c to %c\n", *disco, origem, destino);
}
/*corpo do problema torre de hanoi*/
void hanoi(int disks, char *args){
	
	/*inicializa as 3 pilha do jogo e nomeia com 'A', 'B', 'C'*/
	STK *pinStackA = createStack('A');
	STK *pinStackB = createStack('B');
	STK *pinStackC = createStack('C');

	/*loop que insere os discos na pila 'A'*/
	for(int i = disks; i>0; i--){
		push(pinStackA, ceateDisk(i));
	}
	/*verifica se foi passado argumenos*/
	if(args){
		/*se o argumento passado for -v, devera ser imprimido os movimentos feitos*/
		if(args[0] == '-' && args[1] == 'v'){
			/*funcao que imprime as configuracoes iniciais e finais a depender da flag*/
			printConfig(pinStackA, pinStackB, pinStackC, 1);

			if(disks %2 == 0){
				/*se o numero de discos for par deve-se seguir a sequencias 'AB', 'AC', 'BC'*/
				solveEven(pinStackA, pinStackB, pinStackC, 1);
			}else{
				/*se o numero de discos for impar deve-se seguir a sequencias 'AC', 'AB', 'BC'*/
				solveOdd(pinStackA, pinStackB, pinStackC, 1);
			}
			/*funcao que imprime as configuracoes iniciais e finais a depender da flag*/
			printConfig(pinStackA, pinStackB, pinStackC, 0);
		}
	/*caso args = NULL*/
	}else{

		if(disks %2 == 0){
			/*se o numero de discos for par deve-se seguir a sequencias 'AB', 'AC', 'BC'*/
			solveEven(pinStackA, pinStackB, pinStackC, 0);
		}else{
			/*se o numero de discos for impar deve-se seguir a sequencias 'AC', 'AB', 'BC'*/
			solveOdd(pinStackA, pinStackB, pinStackC, 0);
		}
	}
	/*exclui as pilhas*/
	freeStack(pinStackA, freeDisk);
	freeStack(pinStackB, freeDisk);
	freeStack(pinStackC, freeDisk);
	
}

/*numero de discos par deve-se seguir a sequencias 'AB', 'AC', 'BC'*/
void solveEven(STK *pinStackA, STK *pinStackB, STK *pinStackC, int flag){

	int disk = lenStack(pinStackA);
	/*loop enquanto o pino C for diferente do total de discos*/
	while(lenStack(pinStackC) != disk){

			/*tenta os movimentos AB, AC, BC, e apos cada movimento verifica se o pino C esta com todos os discos*/
			moveStack(pinStackA, pinStackB, flag);
			
			if(lenStack(pinStackC) == disk) break;
			
			moveStack(pinStackA, pinStackC, flag);
			
			if(lenStack(pinStackC) == disk) break;
			
			moveStack(pinStackB, pinStackC, flag);
		}
}
void solveOdd(STK *pinStackA, STK *pinStackB, STK *pinStackC, int flag){

	int disk = lenStack(pinStackA);
	/*loop enquanto o pino C for diferente do total de discos*/
	while(lenStack(pinStackC) != disk){

			/*tenta os movimentos AC, AB, BC, e apos cada movimento verifica se o pino C esta com todos os discos*/
			moveStack(pinStackA, pinStackC, flag);
			
			if(lenStack(pinStackC) == disk) break;
			
			moveStack(pinStackA, pinStackB, flag);
			
			if(lenStack(pinStackC) == disk) break;
			
			moveStack(pinStackB, pinStackC, flag);
		}
}

/*funcao que imprime as configuracoes iniciais e finais a depender da flag*/
void printConfig(STK *pinStackA, STK *pinStackB, STK *pinStackC, int flag){

	if(flag){
		printf("=> Initial configuration:\n");
		printf("   %c:", getName(pinStackA));
		print(pinStackA, showDisks);
		printf("\n   %c:", getName(pinStackB));
		print(pinStackB, showDisks);
		printf("\n   %c:", getName(pinStackC));
		print(pinStackC, showDisks);
		printf("\n");
	}else{
		printf("=> Final configuration:\n");
		printf("   %c:", getName(pinStackA));
		print(pinStackA, showDisks);
		printf("\n   %c:", getName(pinStackB));
		print(pinStackB, showDisks);
		printf("\n   %c:", getName(pinStackC));
		print(pinStackC, showDisks);
		printf("\n");
	}
}
/*funcao que mostra o tamanho do disco*/
void showDisks(void *sizeDisk){
	DISK *temporary = (DISK*)sizeDisk;
	printf(" %d", getSizeDisk(temporary));
}
/*funcao responsavel por fazer o movimento certo*/
void moveStack(STK *pinStack_1, STK *pinStack_2, int flag){

	int *peekStack1, *peekStack2;

	peekStack1 = peek(pinStack_1, getValue);
	peekStack2 = peek(pinStack_2, getValue);
	
	/*se o pino 1 estiver vazio, move do pino1 para o pino2*/
	if(lenStack(pinStack_1) == 0){
		push(pinStack_1, pop(pinStack_2));
		/*imprime o movimento se a flag for igual a 1*/
		if(flag){
			printMov(peekStack2, getName(pinStack_2), getName(pinStack_1));
		}
	/*se o pino 2 estiver vazio, move do pino2 para o pino1*/
	}else if(lenStack(pinStack_2) == 0){
		push(pinStack_2, pop(pinStack_1));
		/*imprime o movimento se a flag for igual a 1*/
		if(flag){
			printMov(peekStack1, getName(pinStack_1), getName(pinStack_2));
		}
	/*se o ultimo disco do pino1 for menos que o ultimo disco do pino2 e feito o movimento pino1 para pino2*/
	}else if(*peekStack1 < *peekStack2){
		push(pinStack_2, pop(pinStack_1));
		/*imprime o movimento se a flag for igual a 1*/
		if(flag){
			printMov(peekStack1, getName(pinStack_1), getName(pinStack_2));
		}
	/*se o ultimo disco do pino1 for maior que o ultimo disco do pino2 e feito o movimento pino2 para pino1*/
	}else if(*peekStack1 > *peekStack2){
		push(pinStack_1, pop(pinStack_2));
		/*imprime o movimento se a flag for igual a 1*/
		if(flag){
			printMov(peekStack2, getName(pinStack_2), getName(pinStack_2));
		}
	}
}
/*funcao que libera o disco*/
void freeDisk(void *disk){

	DISK *temporary = (DISK*)disk;
	free(temporary);
}