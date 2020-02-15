#include <stdio.h>
#include <time.h>
#include "tower.h"

/*converte o clok em minutos segundos e millisegundos*/
void convertTime(double pulse, int *minutes, int *seconds, double *milliseconds){

	while(1){
		if(pulse >= 60000){
			pulse -= 60000;
			*minutes += 1;
		}else if(pulse >+ 1000){
			pulse -= 1000;
			*seconds += 1;
		}else{
			*milliseconds = pulse;
			return;
		}
	}
}

int main(int argc, char **argv){

	/*inicia as variaveis*/
	int disks, minutes = 0, seconds = 0;
	double pulse, milliseconds = 0.0;
	time_t startTime, finalTime;
	
	/*minimo de argumentos nescessario > 1*/
	if(argc > 1){
		
		/*transforma em inteiro o primeiro argumento que eh a quantidade de discos*/
		sscanf(argv[1], "%d", &disks);

		/*se tiver mais argumentos entra nessa condissao*/
		if(argc > 2){
			hanoi(disks, argv[2]);

		}else{
			
			printf("Number of disks\t\tReal time\n%d", disks);

			startTime = clock();
			/*funcao que resolve o problema torre de hanoi*/
			hanoi(disks, NULL);
			/*termina a contagem de tempo*/
			finalTime = clock();
			/*pre calculo antes de converter clock em tempo*/
			pulse = (finalTime - startTime)/1000;
			/*converte o clok em minutos segundos e millisegundos*/
			convertTime(pulse, &minutes, &seconds, &milliseconds);
				
			printf("\t\t\t%dm %d.%03.0fs\n", minutes, seconds, milliseconds);
				
			}
	}else{
		/*retorna 1 se a quantidade de argumentos for 0*/
		return 1;
	}
	/*retorna 0 se tudo ocorrer corretamente*/
	return 0;
}