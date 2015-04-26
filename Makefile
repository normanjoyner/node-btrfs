CC = g++
CFLAGS = -Wall -O3 -g3 -I.
LIBS = -lbtrfs -lv8

BIN = btrfs_test

OBJ = btrfs_utils.o \
	#node-btrfs.o

#%.o: %.c %.cc
%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS) $(LIBS)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

clean:
	rm -f $(OBJ) $(BIN)

