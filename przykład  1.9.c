#include <stdio.h> 

int main() { 
/* deklaracja zmiennych */
   int age; 
   float height; 
   printf("Age and height: "); 
/* pobranie zmiennych od użytkownika */
   scanf("%d %f", &age, &height); 
/* wyświetlenie zmiennych wraz z formatowaniem */
   printf("Your age: %d\nYour height: %.2f", age, height); 
   return 0; 
} 




