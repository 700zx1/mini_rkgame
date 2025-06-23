#!/bin/sh

LOG_SO="/mnt/sdcard/logger_preload.so"
LOG_FILE="/mnt/sdcard/runtime.log"
TARGET="/usr/bin/rkgame"

echo "[INFO] Launching with LD_PRELOAD=$LOG_SO" > "$LOG_FILE"
chmod +x "$TARGET"
LD_PRELOAD="$LOG_SO" "$TARGET"
