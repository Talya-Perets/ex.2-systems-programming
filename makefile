CC = gcc
AR = ar
CFLAGS = -Wall -g
AFLAGS = rcs

.PHONY: all clean

# Corrected the target my_Knapsack.o inclusion in the all rule
all: connections my_Knapsack.o

connections: my_graph.o libmymath.a
	$(CC) $(CFLAGS) my_graph.o -L. -lmymath -o connections

libmymath.a: my_mat.o
	$(AR) $(AFLAGS) libmymath.a my_mat.o

my_graph.o: my_graph.c my_mat.h
	$(CC) $(CFLAGS) -c my_graph.c

my_Knapsack.o: my_Knapsack.c
	$(CC) $(CFLAGS) -c my_Knapsack.c

my_mat.o: my_mat.c my_mat.h
	$(CC) $(CFLAGS) -c my_mat.c

clean:
	rm -f *.o *.a connections
