
CC = mipsel-linux-gnu-gcc
CFLAGS = -Wall -O2
TARGET = test_sf3000_gfx
SRCS = test_sf3000_gfx.c sf3000_gfx.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)
