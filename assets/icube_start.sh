#!/bin/sh
#LOG_SO="/mnt/sdcard/cubegm/logger_preload.so"
LOG_FILE="/mnt/sdcard/runtime.log"
TARGET="/mnt/sdcard/cubegm/icube"
PROBE="/mnt/sdcard/cubegm/sf3000_probe"

killall hcprojector

export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:/mnt/sdcard/cubegm/lib:/mnt/sdcard/cubegm/usr/lib"

echo "[INFO] Attempting to launch probe: $PROBE" > "$LOG_FILE"
if [ -x "$PROBE" ]; then
    "$PROBE" >> "$LOG_FILE" 2>&1
    echo "[INFO] Probe completed." >> "$LOG_FILE"
else
    echo "[WARN] Probe not found or not executable: $PROBE" >> "$LOG_FILE"
fi

echo "[INFO] Launching icube in background..." >> "$LOG_FILE"
chmod +x "$TARGET"
"$TARGET" >> "$LOG_FILE" 2>&1 &
