# Dice Roller GTK
![](Example.png) <br>
A dice roller implemented with C and GTK-4.

### Build and Run
Must have [GTK-4](https://www.gtk.org/) installed on your system.

You can use the bash script:
```bash
bash build.sh
./dice-roller-gtk
```

or

You can use GCC or any other C compiler:
```bash
gcc $(pkg-config --cflags gtk4) -o dice-roller-gtk main.c $(pkg-config --libs gtk4)
```
