#include <stdio.h>
#include <stdlib.h>
#define itemNum 5
#define capacity 20


int knapSack(int weights[], int values[], int selected_bool[]);
int **fillMatrix(int weights[], int values[]);
int max(int a, int b);



int knapSack(int weights[], int values[], int selected_bool[]) {
  int **matrix = fillMatrix(weights, values);
  int result = matrix[itemNum][capacity];
  int totalWeight = capacity;
  for (int i = itemNum; i > 0 && totalWeight > 0; i--) {
    if (matrix[i][totalWeight] != matrix[i - 1][totalWeight]) {
      selected_bool[i - 1] += 1;
      totalWeight -= weights[i - 1];
    }
  }
  
  free(matrix);
  return result;
}

int **fillMatrix(int weights[], int values[]) {
  int **matrix = malloc((itemNum + 1) * sizeof(int *));
  for (int i = 0; i <= itemNum; i++) {
    matrix[i] = malloc((capacity + 1) * sizeof(int));
    for (int j = 0; j <= capacity; j++) {
      if (i == 0 || j == 0) {
        matrix[i][j] = 0;
      } else if (weights[i - 1] <= j) {
        matrix[i][j] = max(matrix[i - 1][j], matrix[i - 1][j - weights[i - 1]] + values[i - 1]);
      } else {
        matrix[i][j] = matrix[i - 1][j];
      }
    }
  }
  return matrix;
}

int max(int a, int b) {
  return (a > b) ? a : b;
}
int main() {
    char items [itemNum] ;
    int weights[itemNum];
    int values[itemNum];
    int selected_bool[itemNum] = {0};

    for (int i = 0; i < itemNum; ++i) {
        scanf(" %c %d %d", &items[i], &values[i], &weights[i]);
    }

    // Call knapSack after reading all inputs
    int max_value = knapSack(weights, values, selected_bool);

    printf("Maximum profit: %d\n", max_value);
    printf("Selected items:" ");
    for (int i = 0; i < itemNum; i++) {
      if(selected_bool[i])
        printf("%c ", items[i]);
    }
    printf("\n");

    return 0;
}
