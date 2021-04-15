/*
** ETNA PROJECT, 24/02/2021
** myMinitel
** File description:
**      [...]
*/

#include "../include/my.h"

void display_dpkg();

void clearScreen()
{
  system("clear");
}

void sub_menu_dpkg()
{
    int choice;

    printf("\n\nNavigation :\n1. Back\n2. Reload\n3. Back menu\n\nMinitel> ");
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

void display_dpkg()
{
    clearScreen();
    char *dpkg = my_system("dpkg-query -l | awk 'NR>3'", "r");
    my_putstr(dpkg);
    sub_menu_dpkg();
}

void sub_menu_ginfo()
{
    int choice;

    printf("\n\nNavigation :\n1. package installed\n2. Back\n\nMinitel> ");
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

void display_ginfo()
{
    clearScreen();

    char *separator = "=============================================\n";

    printf("Minitel - General information of your system\n\n");
    printf(separator);

    char *os_v = my_system("lsb_release -d", "r");
    my_putstr(" ");
    my_putstr(os_v);
    char *uptime = my_system("uptime -s", "r");
    my_putstr(" Up time    :   ");
    my_putstr(uptime);
    char *open_limit = my_system("ulimit -n", "r");
    my_putstr(" File limit :   ");
    my_putstr(open_limit);

    printf(separator);
    sub_menu_ginfo();
}

void display_ninfo()
{
    clearScreen();

    char *separator = "=============================================\n";

    printf("Minitel - Reseau information of your system\n\n");
    printf(separator);

    char *l_ip = my_system("ip a | grep 'inet '", "r");
    my_putstr(" IP list :\n");
    my_putstr(l_ip);
    my_putchar('\n');
    char *interfaces = my_system("ls -1 /sys/class/net", "r");
    my_putstr(" Interface list :\n   ");
    my_putstr(interfaces);
    my_putchar('\n');
    char *r_ip = my_system("ip route", "r");
    my_putstr(" IP route :\n   ");
    my_putstr(r_ip);

    printf(separator);
    sub_menu_ginfo();
}

void sub_menu_pinfo()
{
    int choice;
    int temp = 0;
    printf("\n\nNavigation :\n1. PID\n2. Parent PID\n3. Kill a process\n4.Back\nMinitel> ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            //            char *l_pid = my_system("ps -u", "r");
            //my_putstr(l_pid);
            my_putchar('\n');
            break;
        case 2:
            printf("Please list the Process ID that you want to check\nMinitel> ");
            scanf("%d", &choice);
            char *parpid = my_system("ps -Flww -p PID", "r");
            my_putstr(parpid);
            my_putchar('\n');
           
            break;
        case 3:
            while (temp == 0) {
                 printf("Would you like to kill or terminate a process?\n1.Kill\n2.Terminal\n3.Back\nMinitel> ");
                 scanf("%d", &choice);

                switch (choice) {
                    case 1 :
                        printf("Please list the Process ID that you want to kill\nMinitel> ");
                        scanf("%d", &choice);
                        temp = 1;
                        char *killpid = my_system("kill SIGKILL PID", "r");
                        my_putstr(killpid);
                        my_putchar('\n');
                        break;
                    case 2 :
                        printf("Please list the Process ID that you want to terminate\nMinitel> ");
                        scanf("%d", &choice);
                        temp = 1;
                        char *termpid = my_system("kill SIGTERM PID", "r");
                        my_putstr(termpid);
                        my_putchar('\n');
                    case 3 :
                        temp = 1;
                        break;
                    default:
                        my_putstr("Please choose a whole number between 1 and 3");
                        sleep(2);
                        break;
                }
            }
        case 4 :
            menu();
            break;
        default:
            my_putstr("Please choose a whole number between 1 and 4");
            sleep(3);
            sub_menu_pinfo();
            break;
    }
}

void display_pinfo()
{
    clearScreen();

    char *separator = "=============================================\n";
    my_putstr("potato");



    printf(separator);
    sub_menu_pinfo();

}

