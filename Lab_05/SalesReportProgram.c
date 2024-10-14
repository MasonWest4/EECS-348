/*
Author: Mason West
Class: EECS 348
Lab: 05
Program: Sales Report
Input: Input text File.
Outcome: Prints out the montly sales reports by month, six month moving averages, sorted sales report.
*/


#include <stdio.h>
#include <stdlib.h>  //For qsort

#define NUM_MONTHS 12

//Functions
void monthly_sales_report(float sales[], const char *months[]);
void sales_summary(float sales[], const char *months[]);
void six_month_moving_average(float sales[], const char *months[]);
void sales_report_sorted(float sales[], const char *months[]);
int compare_sales(const void *a, const void *b);

//Main function
int main() {
    //Define the sales and months arrays
    float sales[NUM_MONTHS];
    const char *months[NUM_MONTHS] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    //Open the input file and read the sales
    FILE *file = fopen("InputFile.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    for (int i = 0; i < NUM_MONTHS; i++) {
        fscanf(file, "%f", &sales[i]);
    }
    fclose(file);  //Close the file after reading

    //Generate the reports
    printf("Monthly Sales Report for 2024\n");
    monthly_sales_report(sales, months);

    printf("\nSales Summary Report:\n");
    sales_summary(sales, months);

    printf("\nSix-Month Moving Average Report:\n");
    six_month_moving_average(sales, months);

    printf("\nSales Report (Highest to Lowest):\n");
    sales_report_sorted(sales, months);

    return 0;
}

//Function to print the monthly sales report
void monthly_sales_report(float sales[], const char *months[]) {
    printf("%-12s %10s\n", "Month", "Sales");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-12s %10.2f\n", months[i], sales[i]);
    }
}

//Function to print the sales summary (minimum, maximum, and average)
void sales_summary(float sales[], const char *months[]) {
    float total_sales = 0;
    float min_sale = sales[0], max_sale = sales[0];
    const char *min_month = months[0], *max_month = months[0];

    //Loop through the sales to find min, max, and total
    for (int i = 0; i < NUM_MONTHS; i++) {
        total_sales += sales[i];
        if (sales[i] < min_sale) {
            min_sale = sales[i];
            min_month = months[i];
        }
        if (sales[i] > max_sale) {
            max_sale = sales[i];
            max_month = months[i];
        }
    }
    //Calculate average sales
    float average_sales = total_sales / NUM_MONTHS;

    //Print summary
    printf("Minimum sales: %.2f (%s)\n", min_sale, min_month);
    printf("Maximum sales: %.2f (%s)\n", max_sale, max_month);
    printf("Average sales: %.2f\n", average_sales);
}

//Function to print the six-month moving average report
void six_month_moving_average(float sales[], const char *months[]) {
    for (int i = 0; i <= NUM_MONTHS - 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        float moving_average = sum / 6;
        printf("%s-%s %10.2f\n", months[i], months[i + 5], moving_average);
    }
}

//Comparison function for qsort (sort in descending order by sales)
int compare_sales(const void *a, const void *b) {
    float saleA = *(const float *)a;
    float saleB = *(const float *)b;
    return (saleB > saleA) - (saleB < saleA);  //This sorts in descending order
}

//Function to print sales report sorted from highest to lowest
void sales_report_sorted(float sales[], const char *months[]) {
    //Temporary arrays to store sorted sales and corresponding months
    float sorted_sales[NUM_MONTHS];
    const char *sorted_months[NUM_MONTHS];

    // Copy original arrays into temporary ones
    for (int i = 0; i < NUM_MONTHS; i++) {
        sorted_sales[i] = sales[i];
        sorted_months[i] = months[i];
    }

    //Sort the sales and months together
    for (int i = 0; i < NUM_MONTHS; i++) {
        for (int j = i + 1; j < NUM_MONTHS; j++) {
            if (sorted_sales[i] < sorted_sales[j]) {
                //Swap sales
                float temp_sale = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp_sale;

                //Swap months
                const char *temp_month = sorted_months[i];
                sorted_months[i] = sorted_months[j];
                sorted_months[j] = temp_month;
            }
        }
    }

    //Print sorted sales report
    printf("%-12s %10s\n", "Month", "Sales");
    for (int i = 0; i < NUM_MONTHS; i++) {
        printf("%-12s %10.2f\n", sorted_months[i], sorted_sales[i]);
    }
}
