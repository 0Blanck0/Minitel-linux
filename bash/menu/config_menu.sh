#!/bin/bash
BASH_SOURCE=""
declare -r menuScript=$(readlink -f ${BASH_SOURCE[0]})
menuRoot=$(dirname "$menuScript")

. "$menuRoot/menu.sh"
. "$menuRoot/sed.sh"

ac_inf() {
    ac=ac_inf
    replace "$ac"
}
deac_inf() {
    ac=deac_inf
    replace "$ac"
}
ac_res() {
    echo "Nothing to happen"

    echo -n "Press enter to continue ... "
    read response

    return 1
}
ac_proc() {
    echo "Nothing to happen"

    echo -n "Press enter to continue ... "
    read response

    return 1
}

actionX() {
    return 0
}
#AC_START
menuItems=(
    "A.   Activate Informations"
#    "A.   Deactivate Informations" 
    "A.   Activate Réseaux"
#    "A.   Deactivate Réseaux"
    "A.   Activate Processus"
#    "A.   Deactivate Processus"
    "Q.   Exit  "
)

menuActions=(
   ac_inf 
#    deac_inf
    ac_res
#    deac_res
    ac_proc
#    deac_proc
    actionX
)
#AC_END


menuTitle="   Configuration"
menuFooter=" Enter=Select, Up/Down=Prev/Next Option"


#!/bin/bash
################################
## Run Menu
################################
menuInit
menuLoop


exit 0