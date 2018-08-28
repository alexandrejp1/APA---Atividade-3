#include <iostream>
//#include <stdlib.h>
using namespace std;

void countingSort(int arr[],int n,int max){
    int count[max]={0}; //inicializando com zeros
    int i;
    int saida[n]; //array pra ordenar a saída


    for(i=0; i<n; i++)
    	++count[arr[i]]; //contando as ocorrencias no array count

    for(i=1; i<max; i++)
    	count[i]+=count[i-1]; //somando o antior mais o primeiro no array count

    for(i=n-1; i>=0; i--){
        saida[count[arr[i]]-1]=arr[i]; //varrendo o array desordenado da direita pra esquerda e conferindo o índice de cada elemento no array count
        --count[arr[i]];
    }

    for(i=0; i<n; i++)
    	arr[i]=saida[i]; //trazendo o array já ordenado pra o vetor original
}

int main() {

	int vetor[] = {1, 4, 1, 2, 7, 12, 2};

	countingSort(vetor, 7, 100);

	cout << "\nArray ordenado: " << endl;
    for(int x = 0; x < 7; x++){
        cout << vetor[x] << endl;
    }
	return 0;
}
