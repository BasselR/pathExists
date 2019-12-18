#include <stdio.h>

int find_path(int n, int m, int A[], int i, int j, int k, int l){    //To access an element at A(i, j): A[(i * m) + j]

    int pathComplete = 0;

    if(i == j && k == l){   //Trivial solution, both inputs coordinates are the same
        return 1;
    }

    int visited[n * m];     //Creating visited "boolean" visited array

    for(int i = 0; i < (n * m); i++){   //Initializing visited boolean array
        visited[i] = 0;
    }

    int searchMatrix(int n, int m, int A[], int i, int j, int k, int l){

        if(i == k && j == l){   //Base case
            pathComplete = 1;
            return 3;
        }

        visited[(i * m) + j] = 1;

        if(i < n - 1){
            if(A[((i + 1) * m) + j] == 0 && visited[((i + 1) * m) + j] == 0){
                searchMatrix(n, m, A, i + 1, j, k, l);
            }
        }

        if(i > 0){
            if(A[((i - 1) * m) + j] == 0 && visited[((i - 1) * m) + j] == 0){
                searchMatrix(n, m, A, i - 1, j, k, l);
            }
        }

        if(j < m - 1){
            if(A[(i * m) + (j + 1)] == 0 && visited[(i * m) + (j + 1)] == 0){
                searchMatrix(n, m, A, i, j + 1, k, l);
            }
        }

        if(j > 0){
            if(A[(i * m) + (j - 1)] == 0 && visited[(i * m) + (j - 1)] == 0){
                searchMatrix(n, m, A, i, j - 1, k, l);
            }
        }
    }

    searchMatrix(n, m, A, i, j, k, l);

    if(pathComplete == 1){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    int A[] = {0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0}; // 12 elements stored row-wise in a 1D array - 3 rows * 4 columns
    printf("%d\n", find_path(3, 4, A, 1, 1, 0, 3));
    return 0;
}