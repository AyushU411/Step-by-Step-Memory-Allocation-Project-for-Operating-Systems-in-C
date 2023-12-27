#include <stdio.h>
#include <stdlib.h>

void displayAllocationState(int b[], int p[], int m, int n) {
    printf("Free blocks: ");
    for (int i = 0; i < m; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
    printf("Blocks allocated: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", p[i]);
    }
    printf("\n\n");
}

void firstFit(int block[], int m, int proc[], int n) {
    int balloc[n], pnotalloc[n], palloc[n], b1[m];
    for (int i = 0; i < m; i++) {
        b1[i] = block[i];
    }
    int fit = 0;
    for (int i = 0; i < n; i++) {
        balloc[i] = 0;
        pnotalloc[i] = 0;
        palloc[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        fit = 0;
        for (int j = 0; j < m; j++) {
            if (b1[j] >= proc[i]) {
                balloc[i] = b1[j];
                b1[j] -= proc[i];
                fit = 1;
                // Display the current state after each allocation
                printf("Step %d:\n", i + 1);
                displayAllocationState(b1, balloc, m, n);
                break;
            }
        }
        if (fit == 0) {
            pnotalloc[i] = proc[i];
        } else {
            palloc[i] = proc[i];
        }
    }
    printf("Final state after allocation:\n");
    displayAllocationState(b1, balloc, m, n);
}

void bestFit(int block[], int m, int proc[], int n) {
    int b2[m];
    for (int i = 0; i < m; i++) {
        b2[i] = block[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (b2[i] > b2[j]) {
                int temp = b2[i];
                b2[i] = b2[j];
                b2[j] = temp;
            }
        }
    }
    firstFit(b2, m, proc, n);
}

void worstFit(int block[], int m, int proc[], int n) {
    int b3[m];
    for (int i = 0; i < m; i++) {
        b3[i] = block[i];
    }
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            if (b3[i] < b3[j]) {
                int temp = b3[i];
                b3[i] = b3[j];
                b3[j] = temp;
            }
        }
    }
    firstFit(b3, m, proc, n);
}

int main() {
    int n = 1;
    while (n == 1) {
        int x;
        printf("For first fit press 1\nFor best fit press 2\nFor worst fit press 3\nTo quit press 0\n");
        scanf("%d", &x);
        switch (x) {
            case 1: {
                int m, n;
                printf("\nEnter number of blocks: ");
                scanf("%d", &m);
                int block[m];
                printf("Enter block sizes:\n");
                for (int i = 0; i < m; i++) {
                    scanf("%d", &block[i]);
                }
                printf("\nEnter number of processes: ");
                scanf("%d", &n);
                int proc[n];
                printf("Enter process sizes:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &proc[i]);
                }
                firstFit(block, m, proc, n);
                break;
            }
            case 2: {
                int m, n;
                printf("\nEnter number of blocks: ");
                scanf("%d", &m);
                int block[m];
                printf("Enter block sizes:\n");
                for (int i = 0; i < m; i++) {
                    scanf("%d", &block[i]);
                }
                printf("\nEnter numbermksks of processes: ");
                scanf("%d", &n);
                int proc[n];
                printf("Enter process sizes:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &proc[i]);
                }
                bestFit(block, m, proc, n);
                break;
            }
            case 3: {
                int m, n;
                printf("\nEnter number of blocks: ");
                scanf("%d", &m);
                int block[m];
                printf("Enter block sizes:\n");
                for (int i = 0; i < m; i++) {
                    scanf("%d", &block[i]);
                }
                printf("\nEnter number of processes: ");
                scanf("%d", &n);
                int proc[n];
                printf("Enter process sizes:\n");
                for (int i = 0; i < n; i++) {
                    scanf("%d", &proc[i]);
                }
                worstFit(block, m, proc, n);
                break;
            }
            case 0:
                printf("\nThank you! Bye\n");
                n = 0;
                break;
            default:
                printf("\nPlease enter a valid value for x\n");
        }
    }
    return 0;
}
