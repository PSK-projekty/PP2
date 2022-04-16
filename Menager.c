#define _CRT_SECURE_NO_WARNINGS     //Usuwanie b��du C4996 (scanf may by unsafe.  Consider using scanf_s)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct node {
    int data;     //zmienna przechowuj�ca wyb�r u�ytkownika
    struct node* next;  //wska�nik na nast�pny element listy
}node;

void show(node* head);  //wyswietlanie listy
void push_back(node** head, int option);   //dodawanie do element�w do listy

//wywo�ania funkcji odpowiedzialnych za mechanik� programu
void create_directory(char path[], char name[]);
void remove_directory(char path[], char name[]);
void create_text_file(char path[], char name[], char text[]);
void remove_text_file(char path[], char name[]);
void rename_file(char path[], char old_name[], char new_name[]);
void copy(char path[], char destiny[]);
void information(char path[]);
void search(char path[], char name[]);

int main() {
    system("chcp 1250");   //polskie znaki

    //obs�uga listy
    node* head;
    head = (node*)malloc(sizeof(node));
    head = NULL;

    //zmienne 
    int option = -1;
    char path[100];
    char name[100];
    char text[1000];
    char old_name[100];
    char new_name[100];
    char destiny[100];

    //menu
    while (option != 0) {

        system("cls");

        printf("\n Historia operacji: ");
        show(head); //wy�wietlanie listy, historia wybor�w
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //kolorowanie tekstu
        printf("\n\n Drogi u�ytkowniku! Co chcesz zrobi�?\n\n");
        printf(" 1. Stworzy� katalog.\n");
        printf(" 2. Usun�� katalog.\n");
        printf(" 3. Utworzy� plik tekstowy.\n");
        printf(" 4. Usun�� plik tekstowy.\n");
        printf(" 5. Zmieni� nazw� pliku.\n");
        printf(" 6. Skopiowa� plik.\n");
        printf(" 7. Wy�wietli� informacje o pliku.\n");
        printf(" 8. Szuka� plik�w/folder�w.\n");
        printf(" 9. Zmieni� atrybuty\n");
        printf(" 10. Przenie�� pliki mi�dzy katalogami \n");
        printf(" 0. Zako�czy� program.\n");

        printf("\n Wybieram: ");
        scanf("%d", &option);

        switch (option) {

        case 0:
            return 0;
            break;

        case 1:
            printf("Podaj �cie�k� bezwzgl�dn� do miejsca w kt�rym chcesz utworzy� katalog: ");
            scanf("%s", &path);

            printf("Podaj nazw�: ");
            scanf("%s", &name);

            push_back(&head, option);   //zapisanie wyboru do listy
            create_directory(path, name);   //wywo�anie funkcji tworz�cej katalog
            break;

        case 2:
            printf("Podaj �cie�k� bezwzgl�dn� do katalogu kt�ry chcesz usun��: ");
            scanf("%s", &path);

            printf("Podaj nazw� katalogu: ");
            scanf("%s", &name);

            push_back(&head, option);
            remove_directory(path, name);   //wywo�anie funkcji usuwaj�cej katalog
            break;

        case 3:
            printf("Podaj �cie�k� bezwzgl�dn� do katalogu w kt�rym chcesz utworzy� plik: ");
            scanf("%s", &path);

            printf("Podaj nazw� pliku: ");
            scanf("%s", &name);

            printf("Podaj tre�� ");
            scanf("%s", &text);

            push_back(&head, option);
            create_text_file(path, name, text); //wywo�anie funkcji tworz�cej plik tekstowy
            break;

        case 4:
            printf("Podaj �cie�k� bezwzgl�dn� do katalogu z kt�rego chcesz usun�� plik: ");
            scanf("%s", &path);

            printf("Podaj nazw� pliku: ");
            scanf("%s", &name);

            push_back(&head, option);
            remove_text_file(path, name);   //wywo�anie funkcji usuwaj�cej plik tekstowy
            break;

        case 5:
            printf("Podaj �cie�k� bezwzgl�dn� do katalogu w kt�rym chcesz zmieni� nazw�: ");
            scanf("%s", &path);

            printf("Podaj star� nazw� pliku: ");
            scanf("%s", &old_name);

            printf("Podaj now� nazw� pliku: ");
            scanf("%s", &new_name);

            push_back(&head, option);
            rename_file(path, old_name, new_name);  //wywo�anie funkcji zmieniaj�cej nazw� pliku
            break;

        case 6:
            printf("Podaj �cie�k� bezwzgl�dn� pliku kt�ry chcesz skopiowa�: ");
            scanf("%s", &path);

            printf("Podaj �cie�k� bezwzgl�dn� do miejsca w kt�rym ma sie znale�� skopiowany plik: ");
            scanf("%s", &destiny);

            push_back(&head, option);
            copy(path, destiny);   //wywo�anie funkcji kopiuj�cej pliki
            break;

        case 7:
            printf("Podaj �cie�k� bezwzgl�dn� pliku o kt�rym chesz si� co� dowiedzie�: ");
            scanf("%s", &path);

            push_back(&head, option);
            information(path);   //wy�wietlanie informacji
            break;

            //Prace nad drugim kamieniem milowym
        case 8:
            printf("Podaj na jakim dysku chesz szuka�: ");
            scanf("%s", &path);

            printf("Podaj nazw� pliku kt�rego szukasz: ");
            scanf("%s", &name);

            push_back(&head, option);
            search(path, name);
            system("Pause");

        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //zmiana koloru na czerwony
            printf("Podaj wlasciwa opcje.");
            Sleep(1000);    //u�pienie programu na 1s
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   //Zmiana koloru na bia�y
            break;
        }
    }

    return 0;
}


//wstawianie danych do listy
void push_back(node** head, int option) {
    //je�li pierwszy element listy jest pusty, czyli lista nie istnieje  
    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node));    //we� pierwsz� kom�rk� listy, zarezerwuj tylko tyle pami�c ile potrzebujesz dla zmiennych ze struktury.
        (*head)->data = option;     //nast�pnie do zmiennej 'data' przeka� warto�� zmiennej 'option'.
        (*head)->next = NULL;       //we� pierwszy element listy, stw�rz kolejny i ustaw jego warto�� na NULL.
    }
    //w przeciwnym wypadku 
    else {
        node* current = *head;  //we� pierwszy element i przipisz do zmiennej 'currnet'

        while (current->next != NULL)   //dop�ki kolejne elementy listy nie s� puste iteruj po li�cie
            current = current->next;

        current->next = (node*)malloc(sizeof(node));    //we� pusty element na ko�cu listy i zarezerwuj miejsce
        current->next->data = option;   //do utworzonego miejsca przypisz zmienn�
        current->next->next = NULL;     //utw�rz kolejny element listy i ustaw jego warto�� na NULL
    }
}

//wy�wietlanie listy
void show(node* head) {
    printf("\n");
    if (head == NULL) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf(" Brak historii");
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        node* current = head;   //we� pierwszy element i przypisz do zmienej
        do {
            printf(" %d ", current->data);  //wypisz zawarto�� zmiennej data
            current = current->next;    //przejd� do kolejnego elementu listy
        } while (current != NULL); //iteruj do ostatniego elementu, czy do napotkania NULL'a
    }
}

void create_directory(char path[], char name[]) {

    char command[] = "md ";    //zmiennea przechow�j�ca polecenie systemowe 
    char cmd[100] = "";   //zmienna na polecenie

    strcat(cmd, command);   //do��czenie do zmiennej 'cmd' zmiennej 'command'
    strcat(cmd, path);      //do��czenie zmiennej 'path' pobranej od u�ytkownika
    strcat(cmd, name);      //do�aczenie zmiennej pobranej od u�ytkownika

    //na tym etapie funkcji polecenie jest gotowe, "posklejane"

    system(cmd);        //wywo�anie funkcji, kt�ra jako parametr przyjmuje polecenie do wykonania
}

//Poni�sze funkcjie zosta�y zbudowane na zasadzie opisanej w funkcji 'create_directory'

void remove_directory(char path[], char name[]) {

    char command[] = "rmdir /s /q ";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, name);

    system(cmd);
}

void create_text_file(char path[], char name[], char text[]) {

    char part_1[] = "echo ";
    char part_2[] = " >";
    char cmd[1000] = "";

    strcat(cmd, part_1);
    strcat(cmd, text);
    strcat(cmd, part_2);
    strcat(cmd, path);
    strcat(cmd, name);

    system(cmd);
}

void remove_text_file(char path[], char name[]) {
    char command[] = "del ";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, name);

    system(cmd);
}

void rename_file(char path[], char old_name[], char new_name[]) {
    char command[] = "ren ";
    char white_char[] = " ";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, old_name);
    strcat(cmd, white_char);
    strcat(cmd, new_name);

    system(cmd);
}

void copy(char path[], char destiny[]) {
    char command[] = "copy ";
    char white_char[] = " ";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, white_char);
    strcat(cmd, destiny);

    system(cmd);
}

void information(char path[]) {
    char command[] = "dir /Q /X ";  // /Q oraz /X - to parametry polecenia 'dir' 
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);

    system(cmd);
}

void search(char path[], char name[]) {
    char command[] = "dir ";
    char parmeters[] = " /s /d";
    char mark[] = ":";
    char mark2[] = "*";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, mark);
    strcat(cmd, name);
    strcat(cmd, mark2);
    strcat(cmd, parmeters);

    system(cmd);
}