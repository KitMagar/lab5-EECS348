#include <stdio.h>
#define MONTHS 12
// Author: Kit Magar
//Date: 10/10/24
//This project processes sales data, providing summary reports and sorted output while using basic statistical operations like finding minimum, maximum, and moving averages.


// Function prototypes
void monthlySalesReport(float sales[MONTHS]);
void salesSummaryReport(float sales[MONTHS]);
void sixMonthMovingAverage(float sales[MONTHS]);
void salesReportSorted(float sales[MONTHS], int months[MONTHS]);

void sortSales(float sales[MONTHS], int months[MONTHS]);

int main() {
    // Sample sales data for 12 months
    float sales[MONTHS] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 
                            67230.84, 68233.12, 80950.34, 95225.22};
    int months[MONTHS] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};  // Represents months 1 (January) to 12 (December)
    
    // Display reports
    printf("Monthly Sales Report:\n");
    monthlySalesReport(sales);
    
    printf("\nSales Summary Report:\n");
    salesSummaryReport(sales);
    
    printf("\nSix-Month Moving Average Report:\n");
    sixMonthMovingAverage(sales);
    
    printf("\nSales Report (Highest to Lowest):\n");
    salesReportSorted(sales, months);

    return 0;
}

// Function to print monthly sales report
void monthlySalesReport(float sales[MONTHS]) {
    char *monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t%.2f\n", monthNames[i], sales[i]);
    }
}

// Function to print sales summary report (min, max, average)
void salesSummaryReport(float sales[MONTHS]) {
    float min = sales[0], max = sales[0], sum = 0;
    int minMonth = 0, maxMonth = 0;

    for (int i = 0; i < MONTHS; i++) {
        if (sales[i] < min) {
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            maxMonth = i;
        }
        sum += sales[i];
    }

    printf("Minimum Sales: %.2f (Month %d)\n", min, minMonth + 1);
    printf("Maximum Sales: %.2f (Month %d)\n", max, maxMonth + 1);
    printf("Average Sales: %.2f\n", sum / MONTHS);
}

// Function to print six-month moving average report
void sixMonthMovingAverage(float sales[MONTHS]) {
    for (int i = 0; i <= MONTHS - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("Month %d-%d: %.2f\n", i + 1, i + 6, sum / 6);
    }
}

// Function to print sales report sorted from highest to lowest
void salesReportSorted(float sales[MONTHS], int months[MONTHS]) {
    sortSales(sales, months);
    char *monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    printf("Month\tSales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%s\t%.2f\n", monthNames[months[i] - 1], sales[i]);
    }
}

// Helper function to sort sales in descending order along with months
void sortSales(float sales[MONTHS], int months[MONTHS]) {
    for (int i = 0; i < MONTHS - 1; i++) {
        for (int j = 0; j < MONTHS - i - 1; j++) {
            if (sales[j] < sales[j + 1]) {
                // Swap sales
                float tempSales = sales[j];
                sales[j] = sales[j + 1];
                sales[j + 1] = tempSales;
                
                // Swap months
                int tempMonth = months[j];
                months[j] = months[j + 1];
                months[j + 1] = tempMonth;
            }
        }
    }
}
