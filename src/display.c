/*
** ETNA PROJECT, 24/02/2021
** myMinitel
** File description:
**      [...]
*/

#include "../include/my.h"

void clearScreen()
{
  system("clear");
}

void display_dpkg()
{
    clearScreen();
    my_putstr("Listing in progress...");
    char *dpkg = my_system("dpkg-query -l | awk 'NR>3'", "r");
    clearScreen();
    my_putstr(dpkg);
    sub_menu_dpkg();
}

void display_hginfo()
{
    char *separator = "=============================================\n";

    my_putstr("\nHardware :\n\n");
    my_putstr(separator);

    char *disk = my_system("df -h", "r");
    my_putstr(" Total Disk                    : \n ");
    my_putstr(disk);
    my_putstr("\n");
    char *t_memory = my_system("grep MemTotal /proc/meminfo", "r");
    my_subremove(t_memory, "MemTotal        : ");
    my_putstr(" Total memory                  : ");
    my_putstr(t_memory);
    char *u_memory = my_system("free -h -t --mega | grep 'Total:'", "r");
    my_subremove(u_memory, "Total:         ");
    my_putstr(" Used memory (total/used/free) : ");
    my_putstr(u_memory);
    

    my_putstr(separator);
}

void display_ginfo()
{
    clearScreen();
    my_putstr("Listing in progress...(10 sec)");
    sleep(10);
    clearScreen();
    char *separator = "=============================================\n";
    
    my_putstr("Minitel - General information of your system\n\n");
    my_putstr("\nSoftware :\n\n");
    my_putstr(separator);

    char *os_v = my_system("lsb_release -d", "r");
    my_subremove(os_v, "Description: ");
    my_putstr(" OS version    :   ");
    my_putstr(os_v);
    char *uptime = my_system("uptime -p", "r");
    my_subremove(uptime, "up ");
    my_putstr(" Up time       :   ");
    my_putstr(uptime);
    char *karnel_v = my_system("uname -r", "r");
    my_putstr(" Kernel ver    :   ");
    my_putstr(karnel_v);
    char *open_limit = my_system("ulimit -n", "r");
    my_putstr(" File limit    :   ");
    my_putstr(open_limit);
    char *proc_limit = my_system("ulimit -d", "r");
    my_putstr(" Process limit :   ");
    my_putstr(proc_limit);

    my_putstr(separator);

    display_hginfo();
    sub_menu_ginfo();
}

char *get_forward(char opt)
{
    char *forward_status;

    if (opt == '4')
        forward_status = my_system("cat /proc/sys/net/ipv4/conf/all/forwarding", "r");
    else
        forward_status = my_system("cat /proc/sys/net/ipv6/conf/all/forwarding", "r");

    if (strncmp(forward_status, "0", 1) == 0)
        return "false\n";
    else if (strncmp(forward_status, "1", 1) == 0)
        return "true\n";
    else
        return "!!error config!!\n";
}

void display_ninfo()
{
    clearScreen();

    char *separator = "=============================================\n";

    my_putstr("Minitel - Network information of your system\n\n");
    my_putstr(separator);

    char *l_ip = my_system("ip a | grep 'inet '", "r");
    my_putstr(" IP list :\n");
    my_putstr(l_ip);
    my_putchar('\n');
    char *interfaces = my_system("ls -1 /sys/class/net", "r");
    my_putstr(" Interface list :\n    ");
    for(int i = 0; interfaces[i]!='\0'; i++){
        if(interfaces[i] != '\0'){
            if(interfaces[i]!='\n'){
                my_putchar(interfaces[i]);
            }else{
                my_putstr("\n    ");
            }
        }
    }
    my_putchar('\n');
    char *r_ip = my_system("ip route", "r");
    my_putstr(" IP route :\n    ");
    for(int i = 0; r_ip[i]!='\0'; i++){
        if(r_ip[i] != '\0'){
            if(r_ip[i]!='\n'){
                my_putchar(r_ip[i]);
            }else{
                my_putstr("\n    ");
            }
        }
    }
    my_putchar('\n');
    char *forward = get_forward('4');
    my_putstr(" Forwarding status :\n    Ipv4 ");
    my_putstr(forward);
    my_putstr("    Ipv6 ");
    char *forward_6 = get_forward('6');
    my_putstr(forward_6);

    my_putstr(separator);
    sub_menu_ginfo();
}

void kill_process()
{
    clearScreen();
    int option;
    char choice[100];
    char *command = "kill ";
    char *full_command;
    size_t full_size;
    my_putstr("1. Kill a Process(Make sure you have its ID)\n2. Back\nMinitel> ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            clearScreen();
            my_putstr("ID that you want kill\nMinitel> ");
            scanf("%s", choice);
            full_size = strlen(command) + strlen(choice);
            full_command = (char *) malloc(full_size);
            strcpy(full_command, command);
            strcat(full_command, choice);
            
            char *killp = my_system(full_command, "r");
            
            my_putstr(killp);
            my_putchar('\n');
            free(full_command);
            sleep(3);
            break;
        case 2:
            display_pinfo();
            break;
        default:
            my_putstr("Please choose a number between 1 and 2\nMinitel> ");
            sleep(3);
            kill_process();
            break;
    }
}

void run_process()
{
    clearScreen();
    int option;
    char choice[100];
    char *command = "sudo systemctl start ";
    char *full_command;
    size_t full_size;
    my_putstr("1. Run a Process(Make sure you have its name)\n2. Back\nMinitel> ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            clearScreen();
            my_putstr("Name of the process you want to run\nMinitel> ");
            scanf("%s", choice);
            full_size = strlen(command) + strlen(choice);
            full_command = (char *) malloc(full_size);
            strcpy(full_command, command);
            strcat(full_command, choice);

            char *runp = my_system(full_command, "r");

            my_putstr(runp);
            my_putchar('\n');
            free(full_command);
            sleep(3);
            break;
        case 2:
            display_pinfo();
            break;
        default:
            my_putstr("Please choose a number between 1 and 2\nMinitel> ");
            sleep(3);
            run_process();
            break;
    }
}

void parent_process()
{
    clearScreen();
    int option;
    char choice[100];
    char *command = "ps -Flww -p ";
    char *full_command;
    size_t full_size;
    my_putstr("1. Parent PID\n2. Back\nMinitel> ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            clearScreen();
            my_putstr("Please list the PID that you want to check\nMinitel> ");
            scanf("%s", choice);
            full_size = strlen(command) + strlen(choice);
            full_command = (char *) malloc(full_size);
            strcpy(full_command, command);
            strcat(full_command, choice);

            char *parentpid = my_system(full_command, "r");

            my_putstr(parentpid);
            my_putchar('\n');
            free(full_command);
            sleep(10);
            break;
        case 2:
            display_pinfo();
            break;
        default:
            my_putstr("Please choose a number between 1 and 2\nMinitel> ");
            sleep(3);
            parent_process();
            break;
    }
}

void search()
{
    clearScreen();
    int option;
    char choice[100];
    char *command = "sudo ps aux | grep -i ";
    char *full_command;
    size_t full_size;
    my_putstr("1. Search a Program by name\n2. Back\nMinitel> ");
    scanf("%d", &option);
    switch (option) {
        case 1:
            clearScreen();
            my_putstr("Name of the program that you want search\nMinitel> ");
            scanf("%s", choice);
            full_size = strlen(command) + strlen(choice);
            full_command = (char *) malloc(full_size);
            strcpy(full_command, command);
            strcat(full_command, choice);

            char *searchn = my_system(full_command, "r");

            my_putstr(searchn);
            my_putchar('\n');
            free(full_command);
            sleep(3);
            break;
        case 2:
            display_pinfo();
            break;
        default:
            my_putstr("Please choose a number between 1 and 2\nMinitel> ");
            sleep(3);
            search();
            break;
    }
}



void display_pinfo()
{
    clearScreen();

    char *l_pid = my_system("ps -aux", "r");
    char *separator = "=============================================\n";
    my_putstr(separator);

    my_putstr(l_pid);
    my_putchar('\n');
    
    my_putstr(separator);
    sub_menu_pinfo();
}
