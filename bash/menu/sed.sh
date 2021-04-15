#!/bin/bash
BASH_SOURCE=""

# Get script root (as we are sourced from another script, $0 will not be us)
declare -r menuScript=$(readlink -f ${BASH_SOURCE[0]})
menuRoot=$(dirname "$menuScript")

replace() {
    case $ac in

      ac_inf)
        find . -exec sed -e '/#AC_START/,/#AC_END/s/    "A.   Activate Informations"/#    "A.   Activate Informations"/g' $menuRoot/config_menu.sh  \;
        find . -exec sed -e '/#AC_START/,/#AC_END/s/    ac_inf/#    ac_inf/g' $menuRoot/config_menu.sh  \;
        find . -exec sed -e '/#AC_START/,/#AC_END/s/#    "A.   Deactivate Informations"/    "A.   Deactivate Informations"/g' $menuRoot/config_menu.sh  \;
        find . -exec sed -e '/#AC_START/,/#AC_END/s/#    deac_inf/    deac_inf/g' $menuRoot/config_menu.sh  \;

        find . -exec sed -e '/#AC_START/,/#AC_END/s/#    "I.   Informations"/    "I.   Informations"/g' myMinitel  \;
        find . -exec sed -e '/#AC_START/,/#AC_END/s/#    ac_inf/    ac_inf/g' myMinitel  \;
        ;;

      deac_inf)
        find . -exec sed -e '/#AC_START/,/#AC_END/s/#    "A.   Activate Informations"/    "A.   Activate Informations"/g' $menuRoot/config_menu.sh  \;
        find . -exec sed -e '/#AC_START/,/#AC_END/s/#    ac_inf/    ac_inf/g' $menuRoot/config_menu.sh  \;
        find . -exec sed -e '/#AC_START/,/#AC_END/s/    "A.   Deactivate Informations"/#    "A.   Deactivate Informations"/g' $menuRoot/config_menu.sh  \;
        find . -exec sed -e '/#AC_START/,/#AC_END/s/    deac_inf/#    deac_inf/g' $menuRoot/config_menu.sh  \;

        find . -exec sed -e '/#AC_START/,/#AC_END/s/    "I.   Informations"/#    "I.   Informations"/g' myMinitel  \;
        find . -exec sed -e '/#AC_START/,/#AC_END/s/    ac_inf/#    ac_inf/g' myMinitel  \;
        ;;

      *)
        echo "Nothing to happen"

        echo -n "Press enter to continue ... "
        read response

        return 1
        ;;
    esac
    . "config_menu.sh"
}