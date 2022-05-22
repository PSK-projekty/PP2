#define _CRT_SECURE_NO_WARNINGS     //Usuwanie błędu C4996 (scanf may by unsafe.  Consider using scanf_s)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct node {
    int data;     //zmienna przechowująca wybór użytkownika
    struct node* next;  //wskaźnik na następny element listy
}node;

void show(node* head);  //wyswietlanie listy
void push_back(node** head, int option);   //dodawanie do elementów do listy

//wywołania funkcji odpowiedzialnych za mechanikę programu
void create_directory(char path[], char name[]);
void remove_directory(char path[], char name[]);
void create_text_file(char path[], char name[], char text[]);
void remove_text_file(char path[], char name[]);
void rename_file(char path[], char old_name[], char new_name[]);
void copy(char path[], char destiny[]);
void file_information(char path[]);
void directory_information(char path[]);
void search(char path[], char name[]);
void show_attributes(char path[]);
void change_attributes(char path[], char attributes[]);
void move(char path[], char destiny[]);

int main() {
    system("chcp 1250");   //polskie znaki

    //obsługa listy
    node* head;
    head = (node*)malloc(sizeof(node));
    head = NULL;

    //zmienne 
    int option = -1;
    char temp;
    char path[100];
    char name[100];
    char text[1000];
    char old_name[100];
    char new_name[100];
    char destiny[100];
    char attributes[20];

    //menu
    for (;;) {
        while (option != 0) {

            system("cls");

            printf("\n Historia operacji: ");
            show(head); //wyświetlanie listy, historia wyborów
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //kolorowanie tekstu
            printf("\n\n Drogi użytkowniku! Co chcesz zrobić?\n\n");
            printf(" 1. Stworzyć katalog.\n");
            printf(" 2. Usunąć katalog.\n");
            printf(" 3. Utworzyć plik tekstowy.\n");
            printf(" 4. Usunąć plik tekstowy.\n");
            printf(" 5. Zmienić nazwę pliku/katalogu.\n");
            printf(" 6. Skopiować plik/katalog.\n");
            printf(" 7. Wyświetlić informacje o pliku.\n");
            printf(" 8. Wyświetlić informacje o katalogu.\n");
            printf(" 9. Szukać plików/katalogów.\n");
            printf(" 10. Zmienić atrybuty\n");
            printf(" 11. Przenieść plik/folder między katalogami \n");
            printf(" 0. Zakończyć program.\n");

            printf("\n Wybieram: ");
            scanf("%d", &option);
            printf("\n");

            switch (option) {

            case 0:
                return 0;
                break;

            case 1:
                system("cls");

                printf("Podaj ścieżkę bezwzględną do miejsca w którym chcesz utworzyć katalog: ");
                scanf("%s", &path);

                printf("Podaj nazwę: ");
                scanf("%s", &name);

                push_back(&head, option);   //zapisanie wyboru do listy
                create_directory(path, name);   //wywołanie funkcji tworzącej katalog
                break;

            case 2:
                system("cls");

                printf("Podaj ścieżkę bezwzględną do katalogu który chcesz usunąć: ");
                scanf("%s", &path);

                printf("Podaj nazwę katalogu: ");
                scanf("%s", &name);

                push_back(&head, option);
                remove_directory(path, name);   //wywołanie funkcji usuwającej katalog
                break;

            case 3:
                system("cls");

                printf("Podaj ścieżkę bezwzględną do katalogu w którym chcesz utworzyć plik: ");
                scanf("%s", &path);

                printf("Podaj nazwę pliku: ");
                scanf("%s", &name);

                printf("Podaj treść ");
                scanf("%s", &text);

                push_back(&head, option);
                create_text_file(path, name, text); //wywołanie funkcji tworzącej plik tekstowy
                break;

            case 4:
                system("cls");

                printf("Podaj ścieżkę bezwzględną do katalogu z którego chcesz usunąć plik: ");
                scanf("%s", &path);

                printf("Podaj nazwę pliku: ");
                scanf("%s", &name);

                push_back(&head, option);
                remove_text_file(path, name);   //wywołanie funkcji usuwającej plik tekstowy
                break;

            case 5:
                system("cls");

                printf("Podaj ścieżkę bezwzględną do katalogu w którym chcesz zmienić nazwę: ");
                scanf("%s", &path);

                printf("Podaj starą nazwę pliku: ");
                scanf("%s", &old_name);

                printf("Podaj nową nazwę pliku: ");
                scanf("%s", &new_name);

                push_back(&head, option);
                rename_file(path, old_name, new_name);  //wywołanie funkcji zmieniającej nazwę pliku
                break;

            case 6:
                system("cls");

                printf("Podaj ścieżkę bezwzględną pliku który chcesz skopiować: ");
                scanf("%s", &path);

                printf("Podaj ścieżkę bezwzględną do miejsca w którym ma sie znaleźć skopiowany plik: ");
                scanf("%s", &destiny);

                push_back(&head, option);
                copy(path, destiny);   //wywołanie funkcji kopiującej pliki
                break;

            case 7:
                system("cls");

                printf("W tej funkcji wymagane jest używanie ścieżki z podwójnym znakiem backslash'a np. C:\\\\User\\\\... \n");
                printf("Podaj ścieżkę bezwzględną pliku o którym chesz się coś dowiedzieć: ");
                scanf("%s", &path);

                push_back(&head, option);
                file_information(path);   //wyświetlanie informacji o plikach
                break;

            case 8:
                system("cls");

                printf("W tej funkcji wymagane jest używanie ścieżki z podwójnym znakiem backslash'a np. C:\\\\User\\\\... \n");
                printf("Podaj ścieżkę bezwzględną katalogu o którym chesz się coś dowiedzieć: ");
                scanf("%s", &path);

                push_back(&head, option);
                directory_information(path);   //wyświetlanie informacji o katalogach
                break;

            case 9:
                system("cls");

                printf("Podaj na jakim dysku chesz szukać: ");
                scanf("%s", &path);

                printf("Podaj nazwę pliku którego szukasz: ");
                scanf("%s", &name);

                push_back(&head, option);
                search(path, name);   //szukanie plików
                system("Pause");
                break;

            case 10:
                system("cls");

                printf("Podaj ścieżkę bezwzględną pliku którego atrybuty chcesz zmienić: ");
                scanf("%s", &path);
                show_attributes(path);   //wyświetlanie aktualnych atrybutów

                printf("\n\nDostępne atrybuty: \n");
                printf("R - To polecenie przypisze atrybut 'Tylko do odczytu' do wybranego pliku \n");
                printf("H - To polecenie przypisze atrybut 'Ukryty' do wybranego pliku \n");
                printf("A - To polecenie przygotuje wybrany plik do 'Archiwizacji' \n");
                printf("S - To polecenie zmieni wybrany plik, przypisując atrybut 'System' \n");
                printf("\n Aby dodać atrybut wpisz + oraz jego skrót np. +A. \n Aby usunąć atrybut wpisz - oraz jego skrót np. -R \n");
                printf("\nPodaj atrybuty: ");
                scanf("%c", &temp);
                scanf("%[^\n]", &attributes);
                change_attributes(path, attributes);   //zmiana atrybutów

                show_attributes(path);  //wyświetlanie aktualnych atrybutów

                push_back(&head, option);
                system("Pause");
                break;

            case 11:
                system("cls");

                printf("Podaj ścieżkę bezwzględną pliku który chcesz przenieść: ");
                scanf("%s", &path);

                printf("Podaj ścieżkę bezwzględną do miejsca w którym ma sie znaleźć : ");
                scanf("%s", &destiny);

                push_back(&head, option);
                move(path, name);
                system("Pause");
                break;

            default:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //zmiana koloru na czerwony
                printf("Podaj wlasciwa opcje.");
                Sleep(1000);    //uśpienie programu na 1s
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   //Zmiana koloru na biały
                break;
            }
        }
    }
    return 0;
}


//wstawianie danych do listy
void push_back(node** head, int option) {
    //jeśli pierwszy element listy jest pusty, czyli lista nie istnieje  
    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node));    //weź pierwszą komórkę listy, zarezerwuj tylko tyle pamięci ile potrzebujesz dla zmiennych ze struktury.
        (*head)->data = option;     //następnie do zmiennej 'data' przekaż wartość zmiennej 'option'.
        (*head)->next = NULL;       //weź pierwszy element listy, stwórz kolejny i ustaw jego wartość na NULL.
    }
    //w przeciwnym wypadku 
    else {
        node* current = *head;  //weź pierwszy element i przipisz do zmiennej 'currnet'

        while (current->next != NULL)   //dopóki kolejne elementy listy nie są puste iteruj po liście
            current = current->next;

        current->next = (node*)malloc(sizeof(node));    //weź pusty element na końcu listy i zarezerwuj miejsce
        current->next->data = option;   //do utworzonego miejsca przypisz zmienną
        current->next->next = NULL;     //utwórz kolejny element listy i ustaw jego wartość na NULL
    }
}

//wyświetlanie listy
void show(node* head) {
    printf("\n");
    if (head == NULL) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf(" Brak historii");
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        node* current = head;   //weź pierwszy element i przypisz do zmienej
        do {
            printf(" %d ", current->data);  //wypisz zawartość zmiennej data
            current = current->next;    //przejdź do kolejnego elementu listy
        } while (current != NULL); //iteruj do ostatniego elementu, czy do napotkania NULL'a
    }
}

void create_directory(char path[], char name[]) {

    char command[] = "md ";    //zmiennea przechowójąca polecenie systemowe 
    char cmd[100] = "";   //zmienna na polecenie

    strcat(cmd, command);   //dołączenie do zmiennej 'cmd' zmiennej 'command'
    strcat(cmd, path);      //dołączenie zmiennej 'path' pobranej od użytkownika
    strcat(cmd, name);      //dołaczenie zmiennej pobranej od użytkownika

    //na tym etapie funkcji polecenie jest gotowe, "posklejane"

    system(cmd);        //wywołanie funkcji, która jako parametr przyjmuje polecenie do wykonania
}

//Poniższe funkcje zostały zbudowane na zasadzie opisanej w funkcji 'create_directory'

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

void file_information(char path[]) {
    char command[] = "wmic datafile where Name='";
    char mark[] = "'";
    char cmd[200] = "";
    char list[] = " list full";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, mark);
    strcat(cmd, list);

    system("cls");
    system(cmd);
    system("Pause");
}

void directory_information(char path[]) {
    char command[] = "wmic fsdir where Name='";
    char mark[] = "'";
    char cmd[200] = "";
    char list[] = " list full";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, mark);
    strcat(cmd, list);

    system("cls");
    system(cmd);
    system("Pause");
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

void show_attributes(char path[]) {
    char command[] = "attrib ";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    system(cmd);
}

void change_attributes(char path[], char attributes[]) {
    char command[] = "attrib ";
    char white_char[] = " ";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, attributes);
    strcat(cmd, white_char);
    strcat(cmd, path);
    system(cmd);
}

void move(char path[], char destiny[]) {
    char command[] = "move ";
    char white_char[] = " ";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, white_char);
    strcat(cmd, destiny);

    system(cmd);
}