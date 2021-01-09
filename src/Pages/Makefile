CC=gcc

GTKFLAGS=`pkg-config --libs --cflags gtk+-3.0`
BDFLAGS=`pkg-config --libs --cflags mariadb`
XMLFLAGS=`pkg-config --libs --cflags  libxml-2.0`
JSONFLAGS=`pkg-config --libs --cflags  json-glib-1.0`
CURLFLAGS=`pkg-config --libs --cflags  libcurl`
CCFLAGS=-Wall -Wredundant-decls -Wuninitialized -g -Wreturn-type  -Wpedantic -O0  -fprofile-generate -Wno-write-strings #-Wfatal-errors
ALLFLAGS=$(GTKFLAGS) $(BDFLAGS) $(XMLFLAGS) $(CURLFLAGS) $(JSONFLAGS) $(CCFLAGS)

RESULT_FILE=Pages

OBJS=apresentacao.o bd_config.o conclusao.o

all: $(OBJS)
	

apresentacao.o:
	$(CC) apresentacao.c -c  $(ALLFLAGS)

bd_config.o:
	$(CC) bd_config.c -c  $(ALLFLAGS)

conclusao.o:
	$(CC) conclusao.c -c  $(ALLFLAGS)

clear:
	rm *.o *.gcda $(RESULT_FILE)
