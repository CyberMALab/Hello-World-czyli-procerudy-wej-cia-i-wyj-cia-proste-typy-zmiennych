#include <stdio.h>
#include <stdlib.h>

int main() {	
	int liczba_calkowita=0;
	printf("Liczba calkowita przed scanf: %d \n", liczba_calkowita);
	printf("Podal liczbe calkowita: ");
	scanf(" %d", &liczba_calkowita);
	printf("Liczba calkowita po scanf: %d ", liczba_calkowita);
	return 0;
}
