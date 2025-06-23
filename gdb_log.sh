#!/bin/bash
LOGFILE="gdb_rkgame.log"
gdb -q -x gdb_cmds.txt ./rkgame | tee "$LOGFILE"
