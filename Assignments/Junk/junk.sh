#!/bin/bash
#    I pledge my honor that I've abided by the Stevens Honor System
#    Pramukh Nadig
#    From the bulletin: 
#    Multiple same valid options: “-hhh” <-> “-h”;
#    Valid + Unknown: “-hz” or “-zh” or “zzh”, print “unknown”;
#    Multiple different valid options: “-hlp” or “-hlp text.txt”, print “too many options”.
#    Priority of errors: 
#    Print “unknown” > print “too many”.

readonly script_name=$(basename $(pwd))


readonly JUNK=$HOME/.junk
function hlperMessage() {
    cat << EOF
Usage: $script_name.sh [-hlp] [list of files]
   -h: Display help.
   -l: List junked files.
   -p: Purge all files.
   [list of files] with no other arguments to junk those files.
EOF
}

if [ ! -d "$JUNK" ]; then
	mkdir -p "$JUNK";
fi

num=0
l=0
p=0
h=0

while getopts ":hlp" opt; do
    case "${opt}" in
        h) 
            ((++num))
            h=1
            ;;
        l)
            ((++num))
            l=1
            ;;
        p)
            ((++num))
            p=1
            ;;
        
        ?)
            echo Error: Unknown option \'-$OPTARG\'.
            hlperMessage
            exit
            ;;
        esac
    done

if [[ num -gt 1 ]]; then
    echo Error: Invalid number of options selected.
    hlperMessage
    exit 
fi
if [[ $num -eq 1 && $# -gt 1 ]]; then
    echo Error: Too many options enabled.
    hlperMessage
    exit
fi

if [[ l -eq 1 ]]; then
    ls -lAF $JUNK
elif [[ h -eq 1 ]]; then
    hlperMessage
    exit 
elif [[ p -eq 1 ]]; then
    rm -rf $JUNK
elif [[ num -eq 0 ]]; then
    for elem in "$@"; do
            if [[ -d $elem ]]; then
                mv $(pwd)/$elem/ $JUNK
            elif [[ -e $elem ]]; then
                mv $(pwd)/$elem $JUNK
            elif [[ ! -e $elem ]]; then
                echo Warning: \'$elem\' not found.
            fi
        done
    fi
exit
