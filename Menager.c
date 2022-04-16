#define _CRT_SECURE_NO_WARNINGS     //Usuwanie b³êdu C4996 (scanf may by unsafe.  Consider using scanf_s)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


typedef struct node {
    int data;     //zmienna przechowuj¹ca wybór u¿ytkownika
    struct node* next;  //wskaŸnik na nastêpny element listy
}node;

void show(node* head);  //wyswietlanie listy
void push_back(node** head, int option);   //dodawanie do elementów do listy

//wywo³ania funkcji odpowiedzialnych za mechanikê programu
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

    //obs³uga listy
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
        show(head); //wyœwietlanie listy, historia wyborów
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); //kolorowanie tekstu
        printf("\n\n Drogi u¿ytkowniku! Co chcesz zrobiæ?\n\n");
        printf(" 1. Stworzyæ katalog.\n");
        printf(" 2. Usun¹æ katalog.\n");
        printf(" 3. Utworzyæ plik tekstowy.\n");
        printf(" 4. Usun¹æ plik tekstowy.\n");
        printf(" 5. Zmieniæ nazwê pliku.\n");
        printf(" 6. Skopiowaæ plik.\n");
        printf(" 7. Wyœwietliæ informacje o pliku.\n");
        printf(" 8. Szukaæ plików/folderów.\n");
        printf(" 9. Zmieniæ atrybuty\n");
        printf(" 10. Przenieœæ pliki miêdzy katalogami \n");
        printf(" 0. Zakoñczyæ program.\n");

        printf("\n Wybieram: ");
        scanf("%d", &option);

        switch (option) {

        case 0:
            return 0;
            break;

        case 1:
            printf("Podaj œcie¿kê bezwzglêdn¹ do miejsca w którym chcesz utworzyæ katalog: ");
            scanf("%s", &path);

            printf("Podaj nazwê: ");
            scanf("%s", &name);

            push_back(&head, option);   //zapisanie wyboru do listy
            create_directory(path, name);   //wywo³anie funkcji tworz¹cej katalog
            break;

        case 2:
            printf("Podaj œcie¿kê bezwzglêdn¹ do katalogu który chcesz usun¹æ: ");
            scanf("%s", &path);

            printf("Podaj nazwê katalogu: ");
            scanf("%s", &name);

            push_back(&head, option);
            remove_directory(path, name);   //wywo³anie funkcji usuwaj¹cej katalog
            break;

        case 3:
            printf("Podaj œcie¿kê bezwzglêdn¹ do katalogu w którym chcesz utworzyæ plik: ");
            scanf("%s", &path);

            printf("Podaj nazwê pliku: ");
            scanf("%s", &name);

            printf("Podaj treœæ ");
            scanf("%s", &text);

            push_back(&head, option);
            create_text_file(path, name, text); //wywo³anie funkcji tworz¹cej plik tekstowy
            break;

        case 4:
            printf("Podaj œcie¿kê bezwzglêdn¹ do katalogu z którego chcesz usun¹æ plik: ");
            scanf("%s", &path);

            printf("Podaj nazwê pliku: ");
            scanf("%s", &name);

            push_back(&head, option);
            remove_text_file(path, name);   //wywo³anie funkcji usuwaj¹cej plik tekstowy
            break;

        case 5:
            printf("Podaj œcie¿kê bezwzglêdn¹ do katalogu w którym chcesz zmieniæ nazwê: ");
            scanf("%s", &path);

            printf("Podaj star¹ nazwê pliku: ");
            scanf("%s", &old_name);

            printf("Podaj now¹ nazwê pliku: ");
            scanf("%s", &new_name);

            push_back(&head, option);
            rename_file(path, old_name, new_name);  //wywo³anie funkcji zmieniaj¹cej nazwê pliku
            break;

        case 6:
            printf("Podaj œcie¿kê bezwzglêdn¹ pliku który chcesz skopiowaæ: ");
            scanf("%s", &path);

            printf("Podaj œcie¿kê bezwzglêdn¹ do miejsca w którym ma sie znaleŸæ skopiowany plik: ");
            scanf("%s", &destiny);

            push_back(&head, option);
            copy(path, destiny);   //wywo³anie funkcji kopiuj¹cej pliki
            break;

        case 7:
            printf("Podaj œcie¿kê bezwzglêdn¹ pliku o którym chesz siê coœ dowiedzieæ: ");
            scanf("%s", &path);

            push_back(&head, option);
            information(path);   //wyœwietlanie informacji
            break;

            //Prace nad drugim kamieniem milowym
        case 8:
            printf("Podaj na jakim dysku chesz szukaæ: ");
            scanf("%s", &path);

            printf("Podaj nazwê pliku którego szukasz: ");
            scanf("%s", &name);

            push_back(&head, option);
            search(path, name);
            system("Pause");

        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);   //zmiana koloru na czerwony
            printf("Podaj wlasciwa opcje.");
            Sleep(1000);    //uœpienie programu na 1s
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);   //Zmiana koloru na bia³y
            break;
        }
    }

    return 0;
}


//wstawianie danych do listy
void push_back(node** head, int option) {
    //jeœli pierwszy element listy jest pusty, czyli lista nie istnieje  
    if (*head == NULL) {
        *head = (node*)malloc(sizeof(node));    //weŸ pierwsz¹ komórkê listy, zarezerwuj tylko tyle pamiêc ile potrzebujesz dla zmiennych ze struktury.
        (*head)->data = option;     //nastêpnie do zmiennej 'data' przeka¿ wartoœæ zmiennej 'option'.
        (*head)->next = NULL;       //weŸ pierwszy element listy, stwórz kolejny i ustaw jego wartoœæ na NULL.
    }
    //w przeciwnym wypadku 
    else {
        node* current = *head;  //weŸ pierwszy element i przipisz do zmiennej 'currnet'

        while (current->next != NULL)   //dopóki kolejne elementy listy nie s¹ puste iteruj po liœcie
            current = current->next;

        current->next = (node*)malloc(sizeof(node));    //weŸ pusty element na koñcu listy i zarezerwuj miejsce
        current->next->data = option;   //do utworzonego miejsca przypisz zmienn¹
        current->next->next = NULL;     //utwórz kolejny element listy i ustaw jego wartoœæ na NULL
    }
}

//wyœwietlanie listy
void show(node* head) {
    printf("\n");
    if (head == NULL) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
        printf(" Brak historii");
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        node* current = head;   //weŸ pierwszy element i przypisz do zmienej
        do {
            printf(" %d ", current->data);  //wypisz zawartoœæ zmiennej data
            current = current->next;    //przejdŸ do kolejnego elementu listy
        } while (current != NULL); //iteruj do ostatniego elementu, czy do napotkania NULL'a
    }
}

void create_directory(char path[], char name[]) {

    char command[] = "md ";    //zmiennea przechowój¹ca polecenie systemowe 
    char cmd[100] = "";   //zmienna na polecenie

    strcat(cmd, command);   //do³¹czenie do zmiennej 'cmd' zmiennej 'command'
    strcat(cmd, path);      //do³¹czenie zmiennej 'path' pobranej od u¿ytkownika
    strcat(cmd, name);      //do³aczenie zmiennej pobranej od u¿ytkownika

    //na tym etapie funkcji polecenie jest gotowe, "posklejane"

    system(cmd);        //wywo³anie funkcji, która jako parametr przyjmuje polecenie do wykonania
}

//Poni¿sze funkcjie zosta³y zbudowane na zasadzie opisanej w funkcji 'create_directory'

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