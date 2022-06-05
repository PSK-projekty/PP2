#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#include "functions.h"

/**
 * \file main.c
 * \brief
 * Glowny plik programu, menu i lista
*********************************************************************/

/// <summary>
/// Zdefiniowanie struktury i stworzenie glowy. Każdy element listy przedstawiony będzie za pomocą typu strukturowego z dwoma polami. Pierwszym przechowującym daną i drugim wskazującym na kolejny element listy.
/// </summary>

typedef struct node {
    int data;     
    struct node* next; 
}node;

void show(node* head);

void push_back(node** head, int option); 

/// <summary>
/// Glowna funkcja programu. Zawiera instrukcje obslugujace liste, zmienne oraz menu.
/// Menu działa w nieskonczonej petli for, w niej zas znajduje sie petla while ktora dziala tak dlugo, az uzytkownik nie poda '0' jako wybor. W petli while dziala instrukcja switch odpowiedzialna za pobieranie niezbednych informacji od uzytkowinika oraz wywolywanie odpowiednich funkcji.  
/// </summary>


int main() {
    system("chcp 1250>NUL"); 

    node* head;
    head = (node*)malloc(sizeof(node));
    head = NULL;

    int option = -1;
    char temp;
    char path[100];
    char name[100];
    char text[1000];
    char old_name[100];
    char new_name[100];
    char destiny[100];
    char attributes[20];

    for (;;) {
        while (option != 0) {

            system("cls");

            printf("\n\tHistoria operacji: ");
            show(head);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            printf("\n\n\tDrogi uzytkowniku! Co chcesz zrobic?\n\n");
            printf(" \t1. Stworzyc katalog.\n");
            printf(" \t2. Usunac katalog.\n");
            printf(" \t3. Utworzyc plik tekstowy.\n");
            printf(" \t4. Usunac plik tekstowy.\n");
            printf(" \t5. Zmienic nazwe pliku/katalogu.\n");
            printf(" \t6. Skopiowac plik/katalog.\n");
            printf(" \t7. Wyswietlic informacje o pliku.\n");
            printf(" \t8. Wyswietlic informacje o katalogu.\n");
            printf(" \t9. Szukac plikow/katalogow.\n");
            printf(" \t10. Zmienic atrybuty\n");
            printf(" \t11. Przeniesc plik/folder miedzy katalogami \n");
            printf(" \t0. Zakonczyc program.\n");

            printf("\n\t Wybieram: ");
            scanf("%d", &option);
            printf("\n");

            switch (option) {

            case 0:
                return 0;
                break;

            case 1:
                system("cls");

                printf("\n\tPodaj sciezke bezwzgledna do miejsca w ktorym chcesz utworzyc katalog: ");
                scanf("%s", &path);

                printf("\n\tPodaj nazwe: ");
                scanf("%s", &name);

                push_back(&head, option);   
                create_directory(path, name);
                break;

            case 2:
                system("cls");

                printf("\n\tPodaj sciezke bezwzgledna do katalogu nadrzednego z ktorego chcesz usuwac: ");
                scanf("%s", &path);

                printf("\n\tPodaj nazwe katalogu: ");
                scanf("%s", &name);

                push_back(&head, option);
                remove_directory(path, name);
                break;

            case 3:

                system("cls");

                printf("\n\tPodaj sciezke bezwzgledna do katalogu w ktorym chcesz utworzyc plik: ");
                scanf("%s", &path);

                printf("\nPodaj nazwe pliku: ");
                scanf("%s", &name);

                printf("\n\tPodaj tresc: ");
                scanf("%c", &temp);
                scanf("%[^\n]", text);;

                push_back(&head, option);
                create_text_file(path, name, text);
                break;

            case 4:
                system("cls");

                printf("\n\tPodaj sciezke bezwzgledna do katalogu z ktorego chcesz usunac plik: ");
                scanf("%s", &path);

                printf("\n\tPodaj nazwe pliku: ");
                scanf("%s", &name);

                push_back(&head, option);
                remove_text_file(path, name);
                break;

            case 5:
                system("cls");

                printf("\n\tPodaj sciezke bezwzgledna do miejsca w ktorym znajduje sie plik/katalog ktorego nazwe chcesz zmienic : ");
                scanf("%s", &path);

                printf("\n\tPodaj stara nazwe pliku: ");
                scanf("%s", &old_name);

                printf("\n\tPodaj nowa nazwe pliku: ");
                scanf("%s", &new_name);

                push_back(&head, option);
                rename_file(path, old_name, new_name);
                break;

            case 6:
                system("cls");

                printf("\n\tPodaj sciezke bezwzgledna pliku ktory chcesz skopiowac: ");
                scanf("%s", &path);

                printf("\n\tPodaj sciezke bezwzgledna do miejsca w ktorym ma sie znalezc skopiowany plik: ");
                scanf("%s", &destiny);

                push_back(&head, option);
                copy(path, destiny);
                break;

            case 7:
                system("cls");

                printf("\n\tW tej funkcji wymagane jest uzywanie sciezki z podwojnym znakiem backslash'a np. C:\\\\User\\\\... \n");
                printf("\n\tPodaj sciezke bezwzgledna pliku o ktorym chesz sie cos dowiedziec: ");
                scanf("%s", &path);

                push_back(&head, option);
                file_information(path);
                break;

            case 8:
                system("cls");

                printf("\n\tW tej funkcji wymagane jest uzywanie sciezki z podwojnym znakiem backslash'a np. C:\\\\User\\\\... \n");
                printf("\n\tPodaj sciezke bezwzgledna katalogu o ktorym chesz sie cos dowiedziec: ");
                scanf("%s", &path);

                push_back(&head, option);
                directory_information(path);
                break;

            case 9:
                system("cls");

                printf("\n\tPodaj na jakim dysku chesz szukac: ");
                scanf("%s", &path);

                printf("\n\tPodaj nazwe pliku ktorego szukasz: ");
                scanf("%s", &name);

                push_back(&head, option);
                search(path, name);
                system("Pause");
                break;

            case 10:
                system("cls");

                printf("\n\tPodaj sciezke bezwzgledna pliku ktorego atrybuty chcesz zmienic: ");
                scanf("%s", &path);
                show_attributes(path);

                printf("\n\n\tDostepne atrybuty: \n");
                printf("\tR - To polecenie przypisze atrybut 'Tylko do odczytu' do wybranego pliku \n");
                printf("\tH - To polecenie przypisze atrybut 'Ukryty' do wybranego pliku \n");
                printf("\tA - To polecenie przygotuje wybrany plik do 'Archiwizacji' \n");
                printf("\tS - To polecenie zmieni wybrany plik, przypisujac atrybut 'System' \n");
                printf("\n\t Aby dodac atrybut wpisz + oraz jego skrot np. +A. \n\t Aby usunac atrybut wpisz - oraz jego skrot np. -R \n");
                printf("\n\tPodaj atrybuty: ");
                scanf("%c", &temp);
                scanf("%[^\n]", &attributes);
                change_attributes(path, attributes);

                show_attributes(path);

                push_back(&head, option);
                system("Pause");
                break;

            case 11:
                system("cls");

                printf("\n\tPodaj sciezke bezwzgledna pliku ktory chcesz przeniesc: ");
                scanf("%s", &path);

                printf("\n\tPodaj sciezke bezwzgledna do miejsca w ktorym ma sie znalezc : ");
                scanf("%s", &destiny);

                push_back(&head, option);
                move(path, destiny);
                system("Pause");
                break;

            default:
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("Podaj wlasciwa opcje.");
                Sleep(1000);
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                break;
            }
        }
    }
    return 0;
}


/// <summary>
/// Funkcja odpowiada za dodawanie elementow na koncu listy.
/// Trzeba rozważyć dwa przypadki.
///     1. Gdy head jest NULLem
///     2. Gdy head nie jest NULLem
/// Jesli pierwszy element listy jest pusty, czyli lista nie istnieje. Wez pierwsza komorke listy, zarezerwuj tylko tyle pamieci ile potrzebujesz dla zmiennych ze struktury. Nastepnie do zmiennej 'data' przekaz wartosc zmiennej 'option'.Wez pierwszy element listy, stworz kolejny i ustaw jego wartosc na NULL.
/// W przeciwnym wypadku wez pierwszy element i przypisz do zmiennej 'currnet'. Dopoki kolejne elementy listy nie sa puste iteruj po liscie. Wez pusty element na koncu listy i zarezerwuj miejsce. Do utworzonego miejsca przypisz zmienna. Na koncu utworz kolejny element listy i ustaw jego wartosc na NULL.
/// </summary>
/// <param name="head">Wskazuje na pierwszy element listy, głowe</param>
/// <param name="option">Zmienna przechowujaca wybor uzytkownika</param>
void push_back(node** head, int option) {

    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node)); 
        (*head)->data = option;
        (*head)->next = NULL;
    }
 
    else {
        node* current = *head;

        while (current->next != NULL)
            current = current->next;

        current->next = (node*)malloc(sizeof(node));
        current->next->data = option;
        current->next->next = NULL;
    }
}

/// <summary>
/// Funkcja odpowiada za wyswietlanie listy.
///  Trzeba rozważyć dwa przypadki.
///     1. Gdy head jest NULLem
///     2. Gdy head nie jest NULLem
/// Jezeli head jest pusty, lista jest pusta. Wyswietli sie komunikat "Brak historii".
/// W innym przypadku wez pierwszy element i przypisz do zmienej 'current'. Nastepnie wypisz zawartosc zmiennej data. Przejdz do kolejnego elementu listy. Iteruj po liscie az do napotkania NULLa
/// </summary>
/// <param name="head">Wskazuje na pierwszy element listy, głowe</param>
void show(node* head) {
    printf("\n");
    if (head == NULL) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf("\t Brak historii");
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        node* current = head;
        do {
            printf(" %d ", current->data);
            current = current->next;
        } while (current != NULL);
    }
}