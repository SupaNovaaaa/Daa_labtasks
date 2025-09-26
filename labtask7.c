#include<stdio.h> //standard input and output
#include<stdlib.h> // standard library

int main() {
    int n, capacity;

    printf("Enter the capacity:");
    scanf("%d", &capacity);

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int weight[n], value[n];
    float ratio[n];

    // Enter the values and weights of the items
    printf("Enter value and weight of each item:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &value[i], &weight[i]);  // value first, then weight
    }

    // Calculate the ratio (value/weight)
    for(int i = 0; i < n; i++) {
        ratio[i] = (float)value[i] / weight[i];
    }

    // Print the ratios
    printf("Value/Weight ratios:\n");
    for(int i = 0; i < n; i++) {
        printf("%.2f ", ratio[i]);   // added space
    }
    printf("\n");


    //Sort the value, weight and ratio using bubble sort
    for(int i =0;i<n-1;i++) {
        for(int j  = 0; j<n-i-1;j++) {
            if(ratio[j] < ratio[j+1]) {
                int temp = ratio[j];
                ratio[j] = ratio[j+1];
                ratio[j + 1] = temp;

                int t1 = value[j];
                value[j] = value[j+1];
                value[j + 1] = t1;

                int t2 = weight[j];
                weight[j] = weight[j+1];
                weight[j+1] = t2;
            }
        }
    }

    float totalValue = 0.0;

    int remainingWeight = capacity;
    for(int i = 0; i<n && remainingWeight > 0 ;i++) {
        if(weight[i] <=capacity) {
            totalValue += value[i];
            remainingWeight -= weight[i];
        } else {
            totalValue += value[i]*((float)remainingWeight/weight[i]);
        }
    }

    printf("The total value is %.2f", totalValue);

    return 0;
}
