
# „Hello World!&quot; - Procedury wejścia i wyjścia, proste typy zmiennych.

## Zmienne

Zmienna to związek trzech składowych: nazwy, zbioru wartości oraz wybranego elementu zbioru wartości. W praktyce zmienna to zarezerwowane miejsce w pamięci dla pewnej danej wykorzystywanej w programie. W języku C zbiór wartości zmiennej określamy jako typ. Podstawowymi typami zmiennych są:

- _int –_ zmienna całkowitoliczbowa
- _char –_ zmienna znakowa
- _float –_ zmienna liczbowa zmiennoprzecinkowa
- _double-_ zmienna liczbowa podwójnej precyzji (również zmiennoprzecinkowa)

Aby utworzyć zmienną w C należy podać jej typ oraz nadać jej nazwę: **typ\_zmiennej** nazwa\_zmiennej. Wartość, czyli trzecia składowa zmiennej utworzonej w ten sposób, zostanie wybrana losowo lub wyzerowana (w zależności od miejsca w kodzie, w którym zmienna jest tworzona).

_Przykład (1.0) Tworzenie własnych zmiennych_
```
#include <stdio.h>
#include <stdlib.h>

int main() {	
	int liczba_calkowita;
	char znak;
	float zmiennoprzecinkowa;
	double podwojnej_precyzji;
	
	return 0;
}
```

Program z przykładu (1.0), rezerwuje miejsce dla 4 zmiennych o nazwach _liczba\_calkowita, znak, zmiennoprzecinkowa, podwojnej\_precyzji._

## Funkcja _printf_

Funkcje wejścia i wyjścia to podstawowe elementy, używane w programowaniu do komunikacji programu z użytkownikiem. Pozwalają one wypisywać komunikaty oraz pobierać dane od użytkownika. Podstawową funkcją obsługującą strumień wyjścia jest printf. Pozwala ona wypisać tekst na ekran konsoli. Aby wyświetlić tekst na ekranie konsoli, należy wywołać funkcję poprzez wypisanie jej nazwy wraz z nawiasem tj. printf() oraz wewnątrz nawiasu, podać tekst sterujący (napis). Tekst sterujący to stała łańcuchowa (uproszczając napis zawarty w cudzysłowie) zawierająca znaki zwykłe, sekwencje sterujące i kody formatujące kolejnych argumentów.

_Przykład (1.1) Wyświetlanie tekstu za pomocą printf_
```
#include <stdio.h>
#include <stdlib.h>

int main() {
	printf("Hello World!");
	return 0;
}
```

_Wynik działania programu:_

>Hello World!

Za pomocą funkcji _printf_ można również wyświetlić wartość zmiennej. Aby tego dokonać za pierwszy parametr funkcji podaje się tekst sterujący zawierający odpowiednie kody formatujące, a za drugi zmienną, którą chcemy wyświetlić. Funkcja ta spowoduje zamianę kodu formatującego zawartego w tekście sterującym na wartość zmiennej, podanej w argumencie. Kody formatujące charakteryzują się, wystąpieniem następujących po sobie znaku _%_  oraz znaków alfanumerycznych. Podstawowe kody formatujące zgodne z typem wyświetlania:

- %d - zmienna całkowitoliczbowa (int),
- %c – zmienna znakowa (char),
- %f – zmienna liczbowa zmiennoprzecinkowa (float),
- %lf – zmienna liczbowa podwójnej precyzji (double).

Kod formatujący powinien odpowiadać typowi wyświetlanej zmiennej – nie jest to regułą, jednak dla ułatwienia na początku najlepiej używać kodów formatujących zgodnie z typem zmiennej, którą chcemy wyświetlić.

_Przykład (1.2) Wyświetlanie zmiennej za pomocą printf_
```
#include <stdio.h>
#include <stdlib.h>

int main() {	
	int liczba_calkowita = 0;
	printf("Liczba calkowita: %d", liczba_calkowita);

	return 0;
}
```

_Wynik działania programu:_

>Liczba calkowita: 0

Za pomocą funkcji _printf_ można w sposób analogiczny wyświetlić wiele zmiennych, dodając do ciągu znaków więcej kodów formatujących oraz odpowiednią ilość zmiennych, rozdzielonych przecinkami.

_Przykład (1.3) Wyświetlanie wielu zmiennych za pomocą printf_
```
#include <stdio.h>
#include <stdlib.h>

int main() {	
	int liczba_calkowita = 0;
	char znak = 'a';
	float zmiennoprzecinkowa = 0.4;
	printf(" %d %c %f ", liczba_calkowita, znak, zmiennoprzecinkowa);
	return 0;
}
```
_Wynik działania programu:_

>0 a 0.400000

W przykładach 1.2 i 1.3 został jeszcze użyty operator przypisania „_=_&quot;. Jest on intuicyjny w użyciu i już po przejrzeniu poprzednich przykładów jego działanie nie powinno budzić wątpliwości. Wytłumaczenie działania operatorów arytmetycznych znajduje się w rozdziale 2.

### Funkcja _scanf_

Kolejnym bardzo ważnym elementem jest pobieranie danych od użytkownika. W tym celu użyjemy funkcji wejścia _scanf_ . Jej użycie jest bardzo podobne do użycia funkcji _printf_ tylko, że _scanf_ wczytuje zmienne, zamiast je wyświetlać. W celu wywołania funkcji, podajemy jej nazwę oraz dodajemy na końcu nawias _scanf()._ Wewnątrz nawiasu podajemy spodziewany ciąg znaków (najczęściej zbudowany z kodów formatujących) zamknięty cudzysłowem, oraz w kolejnych argumentach podajemy adresy zmiennych, w których chcemy zapisać wartość. Jedyną istotną różnicą w wywołaniu funkcji jest podanie adresu zmiennej w pamięci, który uzyskamy przez podanie operatora _&amp;_ oraz nazwy zmiennej.

_Przykład (1.4) Pobieranie wartości za pomocą scanf_
```
#include <stdio.h>
#include <stdlib.h>

int main() {	
	int liczba_calkowita;
	scanf(" %d", &liczba_calkowita);
	return 0;
}
```

Po skompilowaniu programu, nie wyświetla się nic, ale program się też nie zakańcza. Migający kursor świadczy jednak o tym, że program czeka na podanie zmiennej przez użytkownika. Po wpisaniu liczby całkowitej, program się kończy a podana przez nas liczba zostaje zapisana do zmiennej. Można to sprawdzić wprowadzając drobne zmiany w przykładzie – wyświetlić wartość zmiennej przed wykonaniem pobrania od użytkownika oraz po pobraniu. Dobrą praktyką jest również podawanie komunikatów na temat tego, jakiego typu zmiennej oczekujemy w _scanf_.

_Przykład (1.5) Pobieranie wartości za pomocą scanf - dowód_
```
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
```

_Wynik działania programu:_

>Liczba calkowita przed scanf: 0
>
>Podal liczbe calkowita: 10
>
>Liczba calkowita po scanf: 10

Za pomocą funkcji _scanf_ można pobrać jednocześnie więcej niż jedną wartość zmiennej. Należy to wykonać analogicznie jak w funkcji _printf,_ czyli podać w pierwszym argumencie odpowiednią ilość kodów formatujących, a następnie, taką samą ilość adresów zmiennych w których chcemy zapisać zmienne, oddzielone przecinkami.

_Przykład (1.6) Pobranie wielu wartości za pomocą scanf_

```
#include <stdio.h>
#include <stdlib.h>

int main() {	
	int liczba_calkowita;
	char znak;
	float zmiennoprzecinkowa;
	scanf(" %d %c %f", &liczba_calkowita, &znak, &zmiennoprzecinkowa);
	return 0;
}
```
## Formatowanie wyświetlanego tekstu

Wewnątrz tekstu sterującego przydają się też różnego rodzaju znaki specjalne. Dwa z nich, najbardziej kluczowe to:

- \n – znak nowej linii
- \t – tabulacja pozioma

Użycie któregoś ze znaków specjalnych wewnątrz ciągu do wyświetlenia, spowoduje „wykonanie&quot; tego znaku, czyli przejście do linii lub zrobienie tabulacji. Zauważamy, że jest problem, kiedy chcemy wyświetlić znak ukośnika &#39;\ &#39; , aby tego dokonać należy użyć podwójnego ukośnika &#39; \\\ &#39;. To samo tyczy się znaku &#39;%&#39; który przeznaczony jest dla kodów formatujących. Aby wypisać znak &#39;%&#39; używamy zapisu podwójnego znaku &#39;%%&#39;.

Dla lepszego wyglądu wyświetlenia lub poprawienia czytelności wyników, wyświetlanie zmiennych można sformatować. Aby to zrobić należy zmodyfikować kody formatujące poprzez dodanie odpowiedniego zapisu między znakiem &#39;%&#39; a oznaczeniem (literą) formatu. W przypadku formatowania liczb całkowitych (int) pomiędzy znak &#39;%&#39; a literę &#39;d&#39; można wstawić liczbę. Taki zapis spowoduje, że każdorazowe wyświetlenie liczby zarezerwuje miejsce przynajmniej dla 3 cyfr.

_Przykład (1.7) Formatowanie wyświetlania liczb całkowitych_

Bez formatowania 

```
#include <stdio.h>
#include <stdlib.h>

int main() {	
	int a=101;
	int b=13;
	int c=4;
	printf("%d \n%d \n%d \n",a,b,c);
	return 0;
}
```

Z formatowaniem
```
#include <stdio.h>
#include <stdlib.h>

int main() {	
	int a=101;
	int b=13;
	int c=4;
	printf("%3d \n%3d \n%3d \n",a,b,c);
	return 0;
}
```

W celu sformatowania wyświetlania liczb zmiennoprzecinkowych (float lub double), pomiędzy znak &#39;%&#39; a znaki &#39;f&#39; lub &#39;lf&#39; można wstawić liczbę całkowitą, działającą w ten sam sposób co dla liczb całkowitych jednak w tym przypadku można dodać jeszcze część niecałkowitą (po przecinku), gdzie liczba znajdująca się po operatorze kropki (w języku C używa się kropki zamiast przecinka), oznacza liczbę miejsc po przecinku, które mają zostać wyświetlone.

_Przykład (1.8) Formatowanie wyświetlania liczb zmiennoprzecinkowych_

Bez formatowania 

```
#include <stdio.h>
#include <stdlib.h>

int main() {	
	float a=4.440441444;
	printf("%f",a);
	return 0;
}
```

Z formatowaniem
```
#include <stdio.h>
#include <stdlib.h>

int main() {	
	float a=4.440441444;
	printf("%4.2f",a);
	return 0;
}
```

### Przykłady do analizy:

_Przykład (1.9) wczytanie zmiennych typu int i float_
```
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
```
_Przykład (1.10) Formatowanie wyświetlania zmiennych typu float_
```
#include <stdio.h> 

int main() { 
   flaot PI=3.14159265359;
/* te liczby zarezerwują 7 miejsc na wyświetlenie w konsoli */ 
   printf(".2f = %7.2f\n", PI); /* po przecinku wyświetli 2 miejsca*/
   printf(".3f = %7.3f\n", PI); /* po przecinku wyświetli 3 miejsca*/
   printf(".5f = %7.5f\n", PI); /* po przecinku wyświetli 5 miejsc*/


} 
```

### Zadania do samodzielnego wykonania:

1. Napisz program, który przywita się z użytkownikiem, zapyta, ile ma lat (zmienna całkowitoliczbowa) i wyświetli komunikat jaki wiek podał użytkownik.

1. Napisz program, który wyczyta jedną liczbę zmiennoprzecinkową, i wyświetl ją z dokładnością do 1,3,5 miejsc po przecinku. Wczytywanie poprzedź odpowiednim komunikatem.

***
[Poprzednia część](https://github.com/CyberMALab/Wprowadzenie-do-programowania-w-j-zyku-ANSI-C.git) | [Spis treści](https://github.com/CyberMALab/Wprowadzenie-do-programowania-w-j-zyku-ANSI-C.git) | [Następna część](https://github.com/CyberMALab/Operatory-arytmetyczne.git)
***
&copy; Cyberspace Modelling and Analysis Laboratory
