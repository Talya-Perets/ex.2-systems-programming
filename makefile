# Flags and commands
CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = -rcs

.PHONY: all clean

all: my_graph my_Knapsack

my_graph: my_graph.o libmymath.a
	$(CC) $(CFLAGS) my_graph.o  ./libmymath.a -o my_graph

my_Knapsack: my_Knapsack.o
	$(CC) $(CFLAGS) my_Knapsack.o -o my_Knapsack

libmymath.a: my_mat.o
	$(AR) $(AFLAGS) libmymath.a my_mat.o

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c  my_graph.c 

 my_Knapsack.o:  my_Knapsack.c 
	$(CC) $(CFLAGS) -c  my_Knapsack.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c 

clean:
	rm -f *.o *.a my_graph my_Knapsack
