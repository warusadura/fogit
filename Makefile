# Copyright (C) 2022 Dhanuka Warusadura

CC = gcc
CFLAGS = -Wall -g -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LIBFLAGS = -lglib-2.0 -lreadline -lsqlite3
TARGET = build/fogit
TEST_TARGET = build/fogit_test
OBJECTFILES = src/main.o src/fogit.o
TEST_OBJECTFILES = test/main.o src/fogit.o
CONF_DIR = .conf


main: $(TARGET)

$(TARGET): $(OBJECTFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTFILES) $(LIBFLAGS)

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJECTFILES)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJECTFILES) $(LIBFLAGS)

clean:
	rm -f $(OBJECTFILES) $(TARGET) $(TEST_OBJECTFILES) $(TEST_TARGET) *~
	rm -rf $(CONF_DIR)
