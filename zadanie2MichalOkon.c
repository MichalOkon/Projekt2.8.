#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_LICZBA 100
#define MAKS_ROZMIAR 20





typedef struct dozw_typy{
    char nazwa [MAKS_ROZMIAR];

}dozw_typy  ;



typedef struct produkty{
    long nr;
    double cena;
    char producent[ MAKS_ROZMIAR];
    dozw_typy  typ;
    char nazwa[ MAKS_ROZMIAR];
}produkty;


void czyszczenie();

void zamiana_w_liter(char wyraz[]);

void wprowadzanie(char znaki[]);

int wybor (produkty produkt[], int * liczba_produktow, dozw_typy typ[], int * liczba_typow);

void dodawanie(dozw_typy typ[], int  * liczba_typow, produkty produkt[], int * liczba_produktow);

void dodawanie_prod(dozw_typy typ_produktu, produkty *produkt, int *liczba_produktow);

void usuwanie(produkty produkt[], int *liczba_produktow);

void wyswietlanie_prod(produkty *w_produkt, int ilosc);

void wyswietlanie_typ(dozw_typy *typ, int liczba_typow);

void sortowanie_nazwy(produkty produkt[], int liczba_produktow);

void sortowanie_ceny(produkty produkt[], int liczba_produktow);

void sortowanie_typu(produkty produkt[], int liczba_produktow);

void sortowanie_produc(produkty *produkt, int liczba_produktow);

void grupowanie_typu(dozw_typy typ[], int liczba_typow, produkty produkt[], int liczba_produktow);

void wyszukiwanie_nazwy(produkty produkt[], int liczba_prod);

void wyszukiwanie_ceny(produkty produkt[], int liczba_prod);

void wyszukiwanie_typu(produkty produkt[], int liczba_prod);

void wyszukiwanie_produc(produkty *produkt, int liczba_prod);



int main() {

    int liczba_typ = 5;
    int liczba_prod = 0;
    int koniec = 0;

    dozw_typy typp[MAKS_LICZBA] = {
            {"spozywcze"}, {"alkoholowe"}, {"chemia"}, {"kosmetyki"}, {"elektronika"}
    };

    //utworzone w celach testowych
    produkty prod[MAKS_LICZBA]; /*{ {54355, 43215.43, "rolnik", {"spozywcze"} ,"ziemniak" },
                                       {3456, 655.43, "nivea", {"kosmetyki"},"krem" },
                                       {532, 43545.43, "apple", {"elektronika"} ,"komputer" },
                                       {54655, 44525.43, "dove", {"kosmetyki"},"mydlo" },
                                       {1234, 43515.43, "frukto", {"kosmetyki"} ,"szampon" }}; */




    printf("Witamy w bazie produktow sklepu.\n");

    while(koniec == 0){ //petla bedzie wykonywana dopoki uzytkownik nie wyjdzie z programu
    koniec = wybor(prod, &liczba_prod, typp, &liczba_typ);
    }
    return 0;
}







void czyszczenie(){ //czyszczenie bufora
    while (getchar() != '\n'){

    }
}

void zamiana_w_liter(char wyraz[]){ //funkcja zamienia wpisane wielkie litery na male
    int i = 0;
    for (i = 0; i < MAKS_ROZMIAR; i++){
        if ((wyraz[i] > 60) && (wyraz[i] < 91)){
            wyraz[i] = wyraz[i] + 32; //zmniejsza wartosc charow o 32
        }
    }
}

void wprowadzanie(char znaki[]){ //funkcja kontroluje czy wprowadzony ciag znakow jest poprawny
    int flaga = 0;
    while(flaga == 0){
        fgets(znaki, MAKS_ROZMIAR, stdin);


        if (strlen(znaki) == 1){
            printf("Nie wprowadzono ciagu znakow!\n");
        }

        else if(znaki[strlen(znaki) - 1] != '\n'){ //funkcja fgets zostawia znak nowej linii przed znakiem \0
            printf("Wprowadzono za dlugi ciag znakow!\n");
            czyszczenie();
        }

        else{
            znaki[strlen(znaki) - 1] = '\0'; //jezeli wszystko jest ok to usuwa spacje z przedostatniego znaku
            zamiana_w_liter(znaki);
            flaga = 1;
        }
    }
}

int wybor (produkty produkt[], int * liczba_produktow, dozw_typy typ[], int * liczba_typow){

    // GLOWNE MENU PROGRAMU
    //pozwala dokonac wyboru czynnosci, jaka chce sie wykonac

    printf("Co chcesz zrobic? Wybierz odpowiednia cyfre:\n");
    printf("1. Wyswietl liste produktow danego typu.\n");
    printf("2. Wyswietl liste produktow posortowana wedlug...\n");
    printf("3. Wyszukaj produkt wedlug...\n");
    printf("4. Dodaj rekord do listy produktow. \n");
    printf("5. Usun rekord z listy produktow. \n");
    printf("6. Wyjdz z programu. \n");


    char decyzja;
    int flaga = 0; //zmienna flaga bedzie przyjmowac wartosc 1 gdy podana zostanie dozwolona liczba
    int koniec = 0; //zmienna koniec bedzy przjmowac wartosc 1 przy wyjsciu z programu



    while (flaga!=1) {
        scanf("%c", &decyzja);

        if (decyzja != '\n') {
            czyszczenie();
        }

        switch (decyzja) {
            case '1':
                grupowanie_typu(typ, *liczba_typow, produkt, *liczba_produktow);
                flaga = 1;
                break;

            case '2':
                printf("Wybierz cyfre:\n Wyswietl liste produktow posortowana wedlug:\n");
                printf("1. Nazwy\n2. Ceny\n3. Typu \n4. Producenta\n");
                flaga = 1;
                break;

            case '3':
                printf("Wybierz cyfre:\nWyszukaj wedlug:\n");
                printf("1. Nazwy\n2. Ceny\n3. Typu \n4. Producenta\n");
                flaga = 1;
                break;

            case '4':
                dodawanie(typ, liczba_typow, produkt, liczba_produktow);
                flaga = 1;
                break;

            case '5':
                usuwanie(produkt, liczba_produktow);
                flaga = 1;
                break;
            case '6':
                koniec = 1;
                flaga = 1;
                break;
            default:
                printf("Wprowadzono bledny znak. Wprowadz odpowiednia cyfre.\n");

                break;
        }

    }

    flaga = 0;

    // SORTOWANIE

    if(decyzja == '2') {

        while (flaga != 1) {

            scanf("%c", &decyzja);
            if (decyzja != '\n') {
                czyszczenie();
            }

            switch (decyzja) {
                case '1':
                    sortowanie_nazwy(produkt, *liczba_produktow); //sortowanie wedlug nazwy
                    flaga = 1;
                    break;

                case '2':
                    sortowanie_ceny(produkt, *liczba_produktow); //sortowanie wedlug ceny
                    flaga = 1;
                    break;

                case '3':
                    sortowanie_typu(produkt, *liczba_produktow); //sortowanie wedlug typu
                    flaga = 1;
                    break;

                case '4':
                    sortowanie_produc(produkt, *liczba_produktow);; //sortowanie wedlug producenta
                    flaga = 1;
                    break;

                default:
                    printf("Wprowadzono bledny znak. Wprowadz odpowiednia cyfre.\n");

                    break;




            }

        }
        wyswietlanie_prod(produkt, *liczba_produktow); //wyswietla posortowana tablice
    }

    // WYSZUKIWANIE

    else if(decyzja == '3'){

        while(flaga != 1) {

            scanf("%c", &decyzja);
            if (decyzja != 1) {
                czyszczenie();
            }

            switch (decyzja) {

                case '1':
                    wyszukiwanie_nazwy(produkt, *liczba_produktow);
                    flaga = 1;
                    break;

                case '2':
                    wyszukiwanie_ceny(produkt, *liczba_produktow);
                    flaga = 1;
                    break;

                case '3':
                    wyszukiwanie_typu(produkt, *liczba_produktow);
                    flaga = 1;
                    break;

                case '4':
                    wyszukiwanie_produc(produkt, *liczba_produktow);
                    flaga = 1;
                    break;

                default:
                    printf("Wprowadzono bledny znak. Wprowadz odpowiednia cyfre.\n");
                    break;

            }
        }
    }

    return koniec;
}

void dodawanie(dozw_typy typ[], int * liczba_typow, produkty produkt[], int * liczba_produktow){ //dodawanie produktow

    printf("Dodawanie produktu. Oto lista typow:\n");

    char nowa_nazwa[MAKS_ROZMIAR];
    int flaga = 0; //zmienna flaga przyjmuje wartosc 1 gdy wprowadzony typ produktu juz istnieje lub 2 gdy ma byc dodany
    int i = 0;

    while (flaga == 0) { //petla jest powtarzana dopoki uzytkownik nie wprowadzi typu produktu

        wyswietlanie_typ(typ, *liczba_typow);
        printf("\nWpisz nazwe typu produktu, jaki chcesz dodac.\n");

        wprowadzanie(nowa_nazwa);

        for ( i = 0; flaga == 0; ++i) { //sprawdzanie czy istnieje wprowadzony typ produktu
            if (strcmp(nowa_nazwa, typ[i].nazwa) == 0) {
                flaga = 1;
                dodawanie_prod(typ[i], produkt, liczba_produktow);
            } else if (i == *liczba_typow - 1) {
                printf("Nie znaleziono podanego typu produktu. Czy chcesz go dodac?\n");
                printf("1. Tak.\n");
                printf("2. Nie, chce wprowadzic typ produktu jeszcze raz.\n");

                char decyzja;
                scanf("%c", &decyzja);
                czyszczenie();

                while (decyzja  != '1' && decyzja != '2') {
                    //znaki sa pobierane dopoki nie wprowadzona zostanie prawidlowa cyfra
                    printf ("Wprowadz prawidlowa cyfre!\n");
                    scanf("%c", &decyzja);
                    czyszczenie();
                }


                if (decyzja == '1') { //dodawanie nowego typu produktu a nastepnie produktu tego typu
                    ++(*liczba_typow);
                    strcpy(typ[i + 1].nazwa, nowa_nazwa);
                    dodawanie_prod(typ[i + 1], produkt, liczba_produktow);
                    flaga = 2;
                    break;
                }

                else if (decyzja == '2') { //ponowne wpisanie typu produktu

                    break;
                }


            }


        }
    }


}


void dodawanie_prod(dozw_typy typ_produktu, produkty *produkt, int *liczba_produktow){
    //dodawanie nowego produkty do bazy
    //nowy produkt bedzie znajdowal sie na ostatnim miejscu tablicy
    produkt[*liczba_produktow].typ = typ_produktu;

    printf("Wprowadz nazwe produktu:\n");
    wprowadzanie(produkt[*liczba_produktow].nazwa);

    printf("Wprowadz nr produktu:\n");
    //petla sprawdza czy podana zostala poprawna liczba
    while(scanf ("%ld", &produkt[*liczba_produktow].nr) != 1 || produkt[*liczba_produktow].nr <= 0){
        czyszczenie();
        printf("Podaj poprawna liczbe!\n");
    }
    czyszczenie();

    printf("Wprowadz producenta:\n");
    wprowadzanie(produkt[*liczba_produktow].producent);

    printf("Wprowadz cene w zlotych:\n");
    while(scanf("%lf", &produkt[*liczba_produktow].cena) != 1 || produkt[*liczba_produktow].cena <= 0.0 ){
        czyszczenie();
        printf("Podaj poprawna liczbe!\n");
    }

    //gdy uzytkownik wpisze przecinek:

    char d;

    if ((d = getchar()) == ','){

        double ulamek = 0;
        scanf("%lf", &ulamek);
        while(ulamek>=1){
            ulamek = ulamek/10;
        }
        produkt[*liczba_produktow].cena = produkt[*liczba_produktow].cena + ulamek;

    }
    if ( d != '\n') {
        czyszczenie();
    }

    (*liczba_produktow)++; //liczba produktow w bazie jest zwiekszana

}


void usuwanie(produkty produkt[], int *liczba_produktow){
    char wprow_nazwa[MAKS_ROZMIAR] = {'\0'};
    int flaga = 0;
    int i = 0;



    if (*liczba_produktow == 0){
        printf("W bazie nie znajduja sie zadne produkty!\n");
    }

    else {
        printf("Wprowadz nazwe produktu do usuniecia: \n");
        while (flaga != 1) {

            wprowadzanie(wprow_nazwa);

            for (i = 0; i < *liczba_produktow && flaga != 1; ++i) {

                //petla if sprawdza czy nazwa ktoregokolwiek z produktow odpowiada wprowadzonej
                if (strcmp(wprow_nazwa, produkt[i].nazwa) == 0) {

                    flaga = 1;
                    //gdy odnaleziony zostanie produkt kolejne produkty "przesuwane" sa o jeden numer w tablciy do przodu
                    //element usuwany przesuwany jest na sam koniec, a liczba produktow zmniejszana jest o 1
                    //w ten sposob program nie widzi ostatniego, usunietego produktu
                    --(*liczba_produktow);

                    while (i < *liczba_produktow) {


                        produkt[i] = produkt[i + 1];
                        ++i;

                    }
                }
            }

            if (flaga == 0) {
                printf("Nie odnaleziono produktu o takiej nazwie\n");
                flaga = 1;
            } else {
                printf("Produkt zostal usuniety\n");
            }

        }
    }
}


void wyswietlanie_prod(produkty *w_produkt, int ilosc){
    //funkcja sluzy wyswietlaniu wyslanej do niej tablicy produktow

    printf("Oto lista produktow:\n");
    printf ("%19s%19s%19s%19s%19s\n","Nazwa", "Cena", "Producent", "Typ", "Numer");

    int i = 0;
    for (i = 0; i < ilosc; ++i) {
        printf ("%19s %15.2f zl %18s ", w_produkt[i].nazwa, w_produkt[i].cena, w_produkt[i].producent);
        printf ("%18s %18ld\n", w_produkt[i].typ.nazwa, w_produkt[i].nr);
    }
    printf("\nWcisnij enter, aby kontynuowac.\n");

    while (getchar() != '\n'){
    }
}


void wyswietlanie_typ(dozw_typy *typ, int liczba_typow){  //wyswietla wszystkie typy produktow

    int licznik = 0;

    printf ("Wprowadzone typy produktow:\n");

    for (licznik = 0; licznik < liczba_typow; ++licznik){
        printf("%d. %s\n", licznik+1, typ[licznik].nazwa);
    }
}


void grupowanie_typu(dozw_typy typ[], int liczba_typow, produkty produkt[], int liczba_produktow){
    //funckja tworzy tablice tymczasowa produktow danego typu ktora potem jest wyswietlana

    produkty tymczasowe[liczba_produktow];
    int liczba_prod_typu = 0;
    char n_typu[MAKS_ROZMIAR] = {'\0'};
    int i = 0;

    sortowanie_nazwy(produkt, liczba_produktow); //produkty beda wyswietlane wedlug nazwy

    printf ("\nJakiego typu produkty chcesz wyswietlic?\nWpisz nazwe typu:\n");
    wyswietlanie_typ(typ, liczba_typow);

    wprowadzanie(n_typu);

    for (i = 0; i < liczba_produktow; i++){ //funkcja porownuje nazwy typow produktow w bazie do wpisanego typu

        if(strcmp(produkt[i].typ.nazwa, n_typu) == 0){
            tymczasowe[liczba_prod_typu] = produkt[i]; //wypelnia tablice tymczasowa, ktoa zostanie pozniej wyswietlona
            liczba_prod_typu++;
        }
    }

    if (liczba_prod_typu == 0){ //jezeli nie odnaleziono zadnego elementu danego typu to funkcja wyswietla komunikat
        printf("Nie znaleziono podanego typu lub produktow danego typu w bazie.\n");
    }

    else{
        wyswietlanie_prod(tymczasowe, liczba_prod_typu);
    }

}


void sortowanie_nazwy(produkty produkt[], int liczba_produktow) {
    produkty tymczasowe;
    int i = 0;
    int flaga = 0;

    do { //petla bedzie trwac dopoki wszystkie elementy tablicy nie zostana posortowane
        //wtedy zmienna flaga utrzyma wartosc 0 przez caly okres trwania petli for i petla sie zakonczy

        flaga = 0;
        for (i = 0; i < liczba_produktow - 1; ++i) { //sortowanie typu bubble sort

            if (strcmp(produkt[i].nazwa, produkt[i + 1].nazwa) >= 0) {
                tymczasowe = produkt[i+1];
                produkt[i + 1] = produkt[i];
                produkt[i] = tymczasowe;
                flaga = 1;
            }
        }

    } while (flaga != 0);
}


void sortowanie_ceny(produkty produkt[], int liczba_produktow){
    produkty tymczasowe;
    int i = 0;
    int flaga = 0;

    do { //petla bedzie trwac dopoki wszystkie elementy tablicy nie zostana posortowane
        //wtedy zmienna flaga utrzyma wartosc 0 przez caly okres trwania petli for

        flaga = 0;
        for (i = 0; i < liczba_produktow - 1; ++i) { //sortowanie typu bubble sort

            if (produkt[i].cena > produkt[i + 1].cena) {
                tymczasowe = produkt[i+1];
                produkt[i + 1] = produkt[i];
                produkt[i] = tymczasowe;
                flaga = 1;
            }
        }

    } while (flaga != 0);
}

void sortowanie_typu(produkty produkt[], int liczba_produktow){
    produkty tymczasowe;
    int i = 0;
    int flaga = 0;

    do { //petla bedzie trwac dopoki wszystkie elementy tablicy nie zostana posortowane
        //wtedy zmienna flaga utrzyma wartosc 0 przez caly okres trwania petli for

        flaga = 0;
        for (i = 0; i < liczba_produktow - 1; ++i) { //sortowanie typu bubble sort

            if (strcmp(produkt[i].typ.nazwa, produkt[i + 1].typ.nazwa) > 0) {
                tymczasowe = produkt[i+1];
                produkt[i + 1] = produkt[i];
                produkt[i] = tymczasowe;
                flaga = 1;

            }
        }

    } while (flaga != 0);
}

void sortowanie_produc(produkty *produkt, int liczba_produktow) {
    produkty tymczasowe;
    int i = 0;
    int flaga = 0;

    do { //petla bedzie trwac dopoki wszystkie elementy tablicy nie zostana posortowane
        //wtedy zmienna flaga utrzyma wartosc 0 przez caly okres trwania petli for

        flaga = 0;
        for (i = 0; i < liczba_produktow - 1; ++i) { //sortowanie typu bubble sort

            if (strcmp(produkt[i].producent, produkt[i + 1].producent) >= 0) {
                tymczasowe = produkt[i + 1];
                produkt[i + 1] = produkt[i];
                produkt[i] = tymczasowe;
                flaga = 1;
            }

        }
    } while (flaga != 0);

}

void wyszukiwanie_nazwy(produkty produkt[], int liczba_prod){ // wyszukiwanie produktu wedlug nazwy
    char wprow_nazwa[MAKS_ROZMIAR] = {'\0'};
    int flaga = 0;
    int i = 0;

    printf("Wprowadz nazwe produktu: \n");

    while(flaga != 1) {

        wprowadzanie(wprow_nazwa);


        for (i = 0; i < liczba_prod &&
                    flaga != 1; ++i) { //petla if sprawdza czy nazwa ktoregokolwiek z produktow odpowiada wprowadzonej
            if (strcmp(wprow_nazwa, produkt[i].nazwa) == 0) {
                printf("Odnaleziony produkt:\n");
                printf("Nazwa: %s \nCena: %.2lf \nProducent: %s \n", produkt[i].nazwa, produkt[i].cena,
                       produkt[i].producent);
                printf("Typ: %s\nNumer: %ld\n", produkt[i].typ.nazwa, produkt[i].nr);
                flaga = 1; //petla jest przerywana jezeli zostanie odnaleziony produkt o takiej nazwie

                printf("\nWcisnij enter, aby kontynuowac.\n");

                while (getchar() != '\n'){

                }

            }
        }

        if (flaga == 0){
            printf("Nie odnaleziono produktu o takiej nazwie\n");
        }

    }

}

void wyszukiwanie_ceny(produkty produkt[], int liczba_prod) {
    double wprow_cena = 0;
    int flaga = 0;
    produkty tymczasowe[liczba_prod]; //tablica bedzie przechowywala odnalezione struktury
    int liczba_odnalezionych = 0; //liczba odnalezionych produktow

    printf("Wprowadz cene produktu:\n");

    scanf("%lf", &wprow_cena);
    czyszczenie();

    int i = 0;
    for (i = 0; i < liczba_prod && flaga != 1; ++i) {

        if ( wprow_cena == produkt[i].cena) {
            tymczasowe[liczba_odnalezionych] = produkt[i];
            ++liczba_odnalezionych;
        }
    }

    if(liczba_odnalezionych == 0){
        printf("Nie odnaleziono produktu o podanej cenie.\n");
    }

    else {
        wyswietlanie_prod(tymczasowe, liczba_odnalezionych); //wyswietlanie odnalezionych elementow
    }

}

void wyszukiwanie_typu(produkty produkt[], int liczba_prod) {
    char wprow_typ[MAKS_ROZMIAR] = {'\0'};
    int flaga = 0;
    produkty tymczasowe[liczba_prod];
    int liczba_odnalezionych = 0;

    printf("Wprowadz typ produktu:\n");

    wprowadzanie(wprow_typ);

    int i = 0;
    for (i = 0; i < liczba_prod && flaga != 1; ++i) {

        if (strcmp(wprow_typ, produkt[i].typ.nazwa) == 0) {
            tymczasowe[liczba_odnalezionych] = produkt[i];
            ++liczba_odnalezionych;
        }
    }

    if (liczba_odnalezionych == 0) {
        printf("Nie odnaleziono produktu o podanym typie.\n");
    }

    else {
        wyswietlanie_prod(tymczasowe, liczba_odnalezionych);
    }
}

void wyszukiwanie_produc(produkty *produkt, int liczba_prod){
    char wprow_producent[MAKS_ROZMIAR] = {'\0'};
    int flaga = 0;
    produkty tymczasowe[liczba_prod];
    int liczba_odnalezionych = 0;

    printf("Wprowadz producenta:\n");

    wprowadzanie(wprow_producent);

    int i = 0;
    for (i = 0; i < liczba_prod && flaga != 1; ++i) {

        if (strcmp(wprow_producent, produkt[i].producent) == 0) {
            tymczasowe[liczba_odnalezionych] = produkt[i];
            ++liczba_odnalezionych;
        }
    }

    if (liczba_odnalezionych == 0) {
        printf("Nie odnaleziono produktu podanego producenta.\n");
    }

    else {
        wyswietlanie_prod(tymczasowe, liczba_odnalezionych); //wyswietlanie odnalezionych elementow
    }
}
