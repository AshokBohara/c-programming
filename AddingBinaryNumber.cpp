//mistakely cpp is gone in c program but ntg wrong for this code .. is for adding binary number using c++ programming language
#include <stdio.h>
#include <string.h>

// Function to add two binary numbers
void addBinary(char a[], char b[], char result[]) 
{
    int i = strlen(a) - 1;  // Index of the last digit of first binary number
    int j = strlen(b) - 1;  // Index of the last digit of second binary number
    int k = (i > j ? i : j) + 1; // Result index (max length of the two binaries + 1 for carry)
    
    result[k + 1] = '\0';  // Null-terminate the result string
    
    int carry = 0;  // Initialize carry to 0

    // Loop through both binary strings from right to left
    while (i >= 0 || j >= 0 || carry == 1) 
    {
        int sum = carry;

        if (i >= 0) 
		{
            sum += a[i] - '0';  // Convert char to integer
            i--;
        }

        if (j >= 0) {
            sum += b[j] - '0';  // Convert char to integer
            j--;
        }

        result[k] = (sum % 2) + '0';  // Convert sum to binary (either 0 or 1)
        carry = sum / 2;  // Calculate carry
        k--;  // Move to next position
    }

    // Shift result if there's no carry
    if (k >= 0) 
    {
        for (int l = 0; result[l + 1] != '\0'; l++) 
		{
            result[l] = result[l + 1];
        }
        result[strlen(result) - 1] = '\0';
    }
}

int main() 
{
    char a[100], b[100], result[101];

    // Input two binary numbers as strings
    printf("Enter the first binary number: ");
    scanf("%s", a);
    printf("Enter the second binary number: ");
    scanf("%s", b);

    addBinary(a, b, result);

    // Output the result
    printf("Sum of the binary numbers: %s\n", result);

    return 0;
}

