CC=gcc
GTK_CFLAGS = $(shell pkg-config --cflags gtk4)
GTK_LIBS = $(shell pkg-config --libs gtk4)

all: dice-roller-gtk

dice-roller-gtk: main.c
	$(CC) $(GTK_CFLAGS) -o dice-roller-gtk main.c $(GTK_LIBS) 

clean:
	rm dice-roller-gtk