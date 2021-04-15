/*
** ETNA PROJECT, 24/02/2021
** myMinitel
** File description:
**      [...]
*/

void speedtest_installer()
{
    system("sudo apt-get update && && sudo apt-get upgrade && sudo apt-get full-upgrade && sudo apt dist-upgrade && apt clean");
    system("sudo apt-get install gnupg1 apt-transport-https dirmngr");
    system("export INSTALL_KEY=379CE192D401AB61");
    system("sudo apt-key adv --keyserver keyserver.ubuntu.com --recv-keys $INSTALL_KEY");
    system("echo 'deb https://ookla.bintray.com/debian generic main' | sudo tee  /etc/apt/sources.list.d/speedtest.list");
    system("sudo apt-get update && sudo apt-get full-upgrade");
    system("sudo apt-get install speedtest");
    system("sudo apt upgrade && sudo apt install net-tools sysstat");
}
