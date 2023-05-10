gcc -c tree.c
gcc -c traversal.c
gcc -c ThiCK.c
gcc -o main ThiCK.o tree.o traversal.o
./main