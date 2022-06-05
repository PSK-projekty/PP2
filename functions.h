#pragma once

/**
 * \file functions.h
 * \brief
 * Funkcje odpowiedzialne za mechanike program, zbudowane na zasadzie opisanej w funkcji 'create_directory'.
*********************************************************************/

/// <summary>
/// Funkcja odpowiada za tworzene katalogow. W pierwszej kolejnosci tworzone sa dwie zmienne. Pierwsza przechowuje polecenie systemowe. Do drugiej zmiennej beda dolaczane kolejne elementy. Przez metode 'strcat()' najpierw dolaczana jest zmienna 'command' a nastepnie dane pobrane od uzytkownika. Na koncu wywolywana jest funkcja 'system()' ze zmienna 'cmd' jako parametrm.
/// </summary>
void create_directory(char* path[], char* name[]);

///Usuwanie katalogu
void remove_directory(char* path[], char* name[]);
///Tworzenie pliku tekstowego
void create_text_file(char* path[], char* name[], char* text[]);
///Usuwanie pliku tekstowego
void remove_text_file(char* path[], char* name[]);
///Zmiana nazwy pliku/katalogu
void rename_file(char* path[], char* old_name[], char* new_name[]);
///Kopiowanie pliku/katalogu
void copy(char* path[], char* destiny[]);
///Wyswietlanie informacji o pliku
void file_information(char* path[]);
///Wyswietlanie informacji o katalogu
void directory_information(char* path[]);
///Szukanie pliku/katalogu
void search(char* path[], char* name[]);
///Wyswietlanie atrybutow pliku/katalogu
void show_attributes(char* path[]);
///Zmiana atrybutow pliku/katalogu
void change_attributes(char* path[], char* attributes[]);
///Przenoszenie pliku/katalogu
void move(char* path[], char* destiny[]);