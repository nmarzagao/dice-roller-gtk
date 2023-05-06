#!/bin/bash

gcc $(pkg-config --cflags gtk4) -o dice-roller-gtk main.c $(pkg-config --libs gtk4)
