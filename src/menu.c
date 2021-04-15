/*
** ETNA PROJECT, 24/02/2021
** myMinitel
** File description:
**      [...]
*/

#include "../include/my.h"

int title() 
{
    clearScreen();

    for (int i = 0; i < 25; i++)
        printf("\n");
    system("toilet -f mono12 -F metal MINITEL");
/*    puts(
" __   __  ___   __    _  ___  _______  _______  ___     \n"
"|  |_|  ||   | |  |  | ||   ||       ||       ||   |    \n"
"|       ||   | |   |_| ||   ||_     _||    ___||   |    \n"
"|       ||   | |       ||   |  |   |  |   |___ |   |    \n"
"|       ||   | |  _    ||   |  |   |  |    ___||   |___ \n"
"| ||_|| ||   | | | |   ||   |  |   |  |   |___ |       |\n"
"|_|   |_||___| |_|  |__||___|  |___|  |_______||_______|\n");
*/
    sleep(1);
    
    for (int i = 0; i < 65; i++) {
        printf("\n");
        msleep(60);
    }

    return(0);
}

int msleep(unsigned int tms) 
{
  return usleep(tms * 1000);
}

void menu() 
{
    int choice;

    clearScreen();
    printf("Choose which menu you would like to open:\n 1. General Information\n 2. Network Information\n 3. Process Information\n 4. Quit\n\nMinitel> ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            display_ginfo();
            break;
        case 2:
            display_ninfo();
            break;
        case 3:
            display_pinfo();
            break;
        case 4:
            system("exit");
            break;
        default:
            my_putstr("Please choose a whole number between 1 and 4");
            sleep(3);
            menu();
            break;
    }    
}

void sub_menu_dpkg()
{
    int choice;

    my_putstr("\n\nNavigation :\n 1. Back\n 2. Reload\n 3. Back menu\n\nMinitel> ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            display_ginfo();
            break;
        case 2:
            display_dpkg();
            break;
        case 3:
            menu();
            break;
        default:
            my_putstr("Please choose a whole number between 1 and 3");
            sleep(3);
            display_dpkg();
            break;
    }    
}

void sub_menu_ginfo()
{
    int choice;

    my_putstr("\n\nNavigation :\n 1. Package installed\n 2. Back\n\nMinitel> ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            display_dpkg();
            break;
        case 2:
            menu();
            break;
        default:
            my_putstr("Please choose a whole number between 1 and 2");
            sleep(3);
            display_ginfo();
            break;
    }    
}

void sub_menu_ninfo()
{
    int choice;

    my_putstr("\n\nNavigation :\n 1. Back\n\nMinitel> ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            menu();
            break;
        default:
            my_putstr("Please choose a whole number between 1 and 1");
            sleep(3);
            display_ninfo();
            break;
    }    
}

void sub_menu_pinfo()
{
    int choice;

    my_putstr("\n\nNavigation :\n 1. Run process\n 2. Kill  process\n 3. Search by name\n 4. Search by parent PID\n 5. Reload\n 6. Back\n\nMinitel> ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            run_process();
            display_pinfo();
            break;
        case 2:
            kill_process();
            display_pinfo();
            break;
        case 3:
            search();
            break;
        case 4:
            parent_process();
            display_pinfo();
            break;
        case 5:
            display_pinfo();
            break;
        case 6:
            menu();
            break;
        default:
            my_putstr("Please choose a whole number between 1 and 6");
            sleep(3);
            display_pinfo();
            break;
    }
}
