#include <stdio.h>

int main() {
    int prices[100], n, i;
    int min_price, max_profit = 0;

    printf("Enter number of days: ");
    scanf("%d", &n);

    printf("Enter stock prices:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    min_price = prices[0];

    for(i = 1; i < n; i++) {
        if(prices[i] < min_price) {
            min_price = prices[i];
        }

        int profit = prices[i] - min_price;

        if(profit > max_profit) {
            max_profit = profit;
        }
    }

    printf("Maximum Profit: %d", max_profit);

    return 0;
}
