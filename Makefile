.SILENT:

CC      ?= gcc
CFLAGS  ?= -Wall -Wextra -O2
BIN      = bradarwatisdis

$(BIN): bradarwatisdis.c bradarwatisdisFUNC.c bradarwatisdisFUNC.h bradarwatisdisKIND.c bradarwatisdisKIND.h bradarwatisdisXTRA.c bradarwatisdisXTRA.h
	$(CC) $(CFLAGS) bradarwatisdis.c bradarwatisdisFUNC.c bradarwatisdisKIND.c bradarwatisdisXTRA.c -o $@

install: $(BIN)
	install -m 755 $(BIN) /usr/local/bin/

clean:
	rm -f $(BIN)

.PHONY: install clean
