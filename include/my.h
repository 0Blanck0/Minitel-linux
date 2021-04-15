/*
** ETNA PROJECT, 26/02/2021
** my.h
** File description:
**      headers for myMiniTel
*/

#ifndef MY_H_
#define MY_H_
#define _DEFAULT_SOURCE 1

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>
#include <errno.h>

//Lib functions
void my_putchar(char c);
void my_putstr(const char *str);
int my_strlen(const char *str);
int my_getnbr(const char *str);
void my_putnbr(int nb);
void my_isneg(int nb);
void my_swap(int *a, int *b);
char *my_strcpy(char *dest, const char *src);
char *my_strncpy(char *dest, const char *src, int n);
int my_strcmp(const char *s1, const char *s2);
int my_strncmp(const char *s1, const char *s2, int n);
char *my_strcat(char *dest, const char *src);
char *my_strncat(char *dest, const char *src, int nb);
char *my_strstr(char *str, const char *to_find);
char *my_strdup(const char *src);
char **my_str_to_word_array(const char *str);
char *my_strchr(const char *s, int c);
char *my_readline(void);
void my_subremove(char *str, const char *toRemove);

//Menu function
void menu();
int title();
int msleep(unsigned int tms);
void sub_menu_dpkg();
void sub_menu_ginfo();
void sub_menu_ninfo();
void sub_menu_pinfo();

//Display info
void clearScreen();
void display_ginfo();
void display_ninfo();
void display_pinfo();
void display_dpkg();
void display_hginfo();

//Active function
char *get_forward(char opt);
void kill_process();
void run_process();
void parent_process();
void search();

//Bash function
int my_sys_len(FILE *file);
char *my_system(char *str, char *opt);

#endif
