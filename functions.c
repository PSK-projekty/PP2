#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

void create_directory(char path[], char name[]) {

    char command[] = "md "; 
    char mark[] = "\\";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, mark);
    strcat(cmd, name);

    system(cmd);
}

void remove_directory(char path[], char name[]) {

    char command[] = "rmdir /s /q ";
    char mark[] = "\\";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, mark);
    strcat(cmd, name);

    system(cmd);
}

void create_text_file(char path[], char name[], char text[]) {

    char part_1[] = "echo ";
    char part_2[] = " >";
    char mark[] = "\\";
    char mark2[] = ".txt";
    char cmd[1000] = "";

    strcat(cmd, part_1);
    strcat(cmd, text);
    strcat(cmd, part_2);
    strcat(cmd, path);
    strcat(cmd, mark);
    strcat(cmd, name);
    strcat(cmd, mark2);

    system(cmd);
}

void remove_text_file(char path[], char name[]) {
    char command[] = "del ";
    char mark[] = "\\";
    char mark2[] = ".txt";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, mark);
    strcat(cmd, name);
    strcat(cmd, mark2);

    system(cmd);
}

void rename_file(char path[], char old_name[], char new_name[]) {
    char command[] = "ren ";
    char white_char[] = " ";
    char mark[] = "\\";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, mark);
    strcat(cmd, old_name);
    strcat(cmd, white_char);
    strcat(cmd, new_name);

    system(cmd);
}

void copy(char path[], char destiny[]) {
    char command[] = "copy ";
    char white_char[] = " ";
    char mark[] = "\\";
    char cmd[100] = "";

    strcat(cmd, command);
    strcat(cmd, path);
    strcat(cmd, white_char);
    strcat(cmd, destiny);
    strcat(cmd, mark);

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