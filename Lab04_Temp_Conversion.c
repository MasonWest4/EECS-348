#include <stdio.h>

// Conversion functions
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}

float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}

float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}

float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}

// Categorization function
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Category: Freezing\n");
        printf("Advisory: It's freezing, wear heavy clothing!\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Category: Cold\n");
        printf("Advisory: It's cold, consider wearing a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Category: Comfortable\n");
        printf("Advisory: The weather is comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Category: Hot\n");
        printf("Advisory: It's hot, stay hydrated.\n");
    } else {
        printf("Category: Extreme Heat\n");
        printf("Advisory: Extreme heat, stay indoors and avoid strenuous activity.\n");
    }
}

int main() {
    float input_temp, converted_temp;
    int input_scale, target_scale;

    // Prompt user for input
    printf("Enter the temperature value: ");
    if (scanf("%f", &input_temp) != 1) {
        printf("Invalid input. Please enter a numeric value.\n");
        return 1;
    }

    printf("Enter the input scale (1 for Celsius, 2 for Fahrenheit, 3 for Kelvin): ");
    if (scanf("%d", &input_scale) != 1 || input_scale < 1 || input_scale > 3) {
        printf("Invalid scale choice. Please enter 1, 2, or 3.\n");
        return 1;
    }

    printf("Enter the target scale (1 for Celsius, 2 for Fahrenheit, 3 for Kelvin): ");
    if (scanf("%d", &target_scale) != 1 || target_scale < 1 || target_scale > 3) {
        printf("Invalid scale choice. Please enter 1, 2, or 3.\n");
        return 1;
    }

    // Handle invalid Kelvin values
    if (input_scale == 3 && input_temp < 0) {
        printf("Invalid input: Temperature in Kelvin cannot be negative.\n");
        return 1;
    }

    // Convert the temperature based on user input using if-else instead of switch
    if (input_scale == 1 && target_scale == 2) {  // Celsius to Fahrenheit
        converted_temp = celsius_to_fahrenheit(input_temp);
        printf("Converted temperature: %.2f Fahrenheit\n", converted_temp);
    } 
    else if (input_scale == 1 && target_scale == 3) {  // Celsius to Kelvin
        converted_temp = celsius_to_kelvin(input_temp);
        printf("Converted temperature: %.2f Kelvin\n", converted_temp);
    } 
    else if (input_scale == 2 && target_scale == 1) {  // Fahrenheit to Celsius
        converted_temp = fahrenheit_to_celsius(input_temp);
        printf("Converted temperature: %.2f Celsius\n", converted_temp);
    } 
    else if (input_scale == 2 && target_scale == 3) {  // Fahrenheit to Kelvin
        converted_temp = fahrenheit_to_kelvin(input_temp);
        printf("Converted temperature: %.2f Kelvin\n", converted_temp);
    } 
    else if (input_scale == 3 && target_scale == 1) {  // Kelvin to Celsius
        converted_temp = kelvin_to_celsius(input_temp);
        printf("Converted temperature: %.2f Celsius\n", converted_temp);
    } 
    else if (input_scale == 3 && target_scale == 2) {  // Kelvin to Fahrenheit
        converted_temp = kelvin_to_fahrenheit(input_temp);
        printf("Converted temperature: %.2f Fahrenheit\n", converted_temp);
    } 
    else if (input_scale == target_scale) {  // No conversion needed
        printf("No conversion needed. Temperature: %.2f\n", input_temp);
        converted_temp = input_temp;
    } else {
        printf("Invalid conversion combination.\n");
        return 1;
    }

    // Categorize based on Celsius for advisory
    if (target_scale == 1) {
        categorize_temperature(converted_temp);
    } else if (target_scale == 2) {
        categorize_temperature(fahrenheit_to_celsius(converted_temp));
    } else {
        categorize_temperature(kelvin_to_celsius(converted_temp));
    }

    return 0;
}
