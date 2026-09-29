
CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -O2
BIN      = bradarwatisdis

$(BIN): bradarwatisdis.c bradarwatisdisKIND.c bradarwatisdisKIND.h
	$(CC) $(CFLAGS) bradarwatisdis.c bradarwatisdisKIND.c -o $@

install: $(BIN)
	sudo install -m 755 $(BIN) /usr/local/bin/

clean:
	rm -f $(BIN)

.PHONY: install clean
