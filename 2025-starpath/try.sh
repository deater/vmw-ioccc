#!/usr/bin/env bash
#
# try.sh - demonstrate IOCCC submission YYYY/foo
#

# make sure CC is set so that when we do make CC="$CC" it isn't empty. Doing it
# this way allows us to have the user specify a different compiler in an easy
# way.
[[ -z "$CC" ]] && CC="cc"

make CC="$CC" all >/dev/null || exit 1

# clear screen after compilation so that only the submission is shown
clear

read -r -n 1 -p "Press any key to run: ./prog in an xterm configured for sixel mode: "
echo 1>&2

xterm -ti vt340 -e ./prog
