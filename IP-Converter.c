#include <stdio.h>
#include <math.h>
#include <string.h>

void logo();
void verify_decimal_IP(int *ip_parts);
void verify_binary_IP(int *ip_parts);
void binaryToDecimal(int *parts);
void decimalToBinary(int *parts);

int main()
{  
    char restart;
    logo();
    do {
        int menu_choice, result; // Stores the menu choice the user will make, we use that to see which function to call and what type of IP we check for validation.
        int ip_parts[4]; // Will store each octet of the IP through the verifyUserIP, then we can pass it to the other functions to make the convertion
        char input[10];


        do {    // This will ask the user for his choice, it will continue doing so until he writes the right choice.
            printf("\nSelect one of the following options by entering 1 or 2.\n1) Convert a decimal IP address to a binary IP address.\n2) Convert a binary IP address to a decimal IP address.\n3) Exit the program"); 
            printf("\nWhich option would you like to choose: ");
            fgets(input, 10, stdin);
            result = sscanf(input, "%d", &menu_choice); // Here the sscanf will return value of 1 it means the convertion to int was successful, if it doesn't it means the input was not a number. Also we need the sscanf to save the input to int.
        } while(result != 1 || (menu_choice != 1 && menu_choice !=2 && menu_choice != 3));
        
        switch (menu_choice)
        {
        case 1:
            verify_decimal_IP(ip_parts);
            decimalToBinary(ip_parts);
            break;
        
        case 2:
            verify_binary_IP(ip_parts);
            binaryToDecimal(ip_parts);
            break;
        
        case 3:
            return 0;
        }

        do {
            printf("\nWould you like to restart the program? (y/n): "); // Will ask the user if he wants to use the program again, if he select 'y' it will continue and if he select 'n' it will close.
            fgets(input, 10, stdin);
            sscanf(input, " %c", &restart);
        } while ((restart != 'y' && restart != 'Y') && (restart != 'n' && restart != 'N'));
        
    } while (restart == 'y' || restart == 'Y');

    printf("\nPress ENTER to exit the program ");
    getchar();
    return 0;
}

void verify_decimal_IP(int *ip_parts) {
    
    char userIPstored[40]; // Storing the IP he selected as a whole and exit is to keep the program working until the user type exit it helps the executable to work and not close instantly.
    
    printf("\nEnter the decimal IP address you wish to convert: ");
    fgets(userIPstored, 40, stdin);
    int matches = sscanf(userIPstored, "%d.%d.%d.%d", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]); // Will store how many of the arrays were used in the sscanf. We use that later on to check if the user typed IP with 4 octets as it is suppose to be.
    userIPstored[strcspn(userIPstored, "\n")] = '\0'; // Will find where the newline is in the string and replace it with a null character. This helps bcause later on in the error message the newline would cause the output to be in a weird form.

    for (int i = 0; i < 4; i++) { // For loop to check every octet of the IP if it's valid
        while (ip_parts[i] < 0 || ip_parts[i] > 255 || matches != 4) { //Checking if the decimal IP has 4 octets and if each number is between 0 and 255. If it's wrong then we give error and ask the user for a new IP.
            if (matches != 4) {
                printf("\nError: The IP address '%s' does not contain 4 octets.", userIPstored);
            } if (ip_parts[i] < 0 || ip_parts[i] > 255) {
                printf("\nError: The octets in the IP address '%s' are not numbers between 0 and 255.", userIPstored);
            }
            
            printf("\n\nEnsure that your IP address contains 4 octets in the format x.x.x.x, where x is a number between 0 and 255.");
            printf("\nEnter the decimal IP address you wish to convert: ");
            fgets(userIPstored, 40, stdin);
            matches = sscanf(userIPstored, "%d.%d.%d.%d", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
            userIPstored[strcspn(userIPstored, "\n")] = '\0';
        }
    }
}

void verify_binary_IP(int *ip_parts) {
    char userIPstored[40]; // Storing the IP he selected as a whole and exit is to keep the program working until the user type exit it helps the executable to work and not close instantly.
    

    printf("\nEnter the binary IP address you wish to convert: ");
    fgets(userIPstored, 40, stdin);
    int matches = sscanf(userIPstored, "%d.%d.%d.%d", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]); // Will store how many of the arrays were used in the sscanf. We use that later on to check if the user typed IP with 4 octets as it is suppose to be.
    userIPstored[strcspn(userIPstored, "\n")] = '\0'; // Will find where the newline is in the string and replace it with a null character. This helps bcause later on in the error message the newline would cause the output to be in a weird form.

    for (int i = 0; i < 4; i++) {
        
        char octet1[9], octet2[9], octet3[9], octet4[9]; // Will store the octets, we use a char here because ''int'' removes the leading 0's and we want to keep them.
        sscanf(userIPstored, "%8[^.].%8[^.].%8[^.].%8s", octet1, octet2, octet3, octet4); // Seperating the octets and storing them to their own viarable.

        int len1, len2, len3, len4; // Will store the lenght of the octets
        len1 = strlen(octet1), len2 = strlen(octet2), len3 = strlen(octet3), len4 = strlen(octet4); // Using strlen to find out the lenght of each octet.

        while( ip_parts[i] % 10 != 0 && ip_parts[i] % 10 != 1 || matches != 4 || len1 != 8 || len2 != 8 || len3 != 8 || len4 != 8) { // Checking if each number is binary, if the IP has 4 octets and also if each octet is 8 digits.
            if ( matches !=4 ) {
                printf("\nError: The IP address '%s' does not contain 4 octets.", userIPstored);
            } if ( len1 != 8 || len2 != 8 || len3 != 8 || len4 != 8 ) {
                printf("\nError: The IP address '%s' does not contain octets with 8 binary digits.", userIPstored);
            } if ( ip_parts[i] % 10 != 0 && ip_parts[i] % 10 != 1 ) {
                printf("\nError: The octets in the IP address '%s' are not valid binary numbers.", userIPstored);
            }
            
            printf("\n\nEnsure that your IP address contains 4 octets in the format x.x.x.x, where each x is an 8-bit binary number represented by '0' and '1'.");
            printf("\nEnter the binary IP address you wish to convert: ");
            fgets(userIPstored, 40, stdin);
            matches = sscanf(userIPstored, "%d.%d.%d.%d", &ip_parts[0], &ip_parts[1], &ip_parts[2], &ip_parts[3]);
            userIPstored[strcspn(userIPstored, "\n")] = '\0';

            sscanf(userIPstored, "%8[^.].%8[^.].%8[^.].%8s", octet1, octet2, octet3, octet4);
            len1 = strlen(octet1), len2 = strlen(octet2), len3 = strlen(octet3), len4 = strlen(octet4);
        }
    }
}

void decimalToBinary(int *parts) {
    
    int binaryip[4][32]; // Here we are storing the converted parts of the IP, each array is full of '1' and '0' so we can reverse them but also to check if they are 8 digits and add more '0' if needed.
    char octet_1[9], octet_2[9], octet_3[9], octet_4[9]; // Will store each octet of the binary IP inside those strings, so later on we combine them inside the binary and have right format of an IP (x.x.x.x)
    char binary_ip[36];
    
    // Convert each decimal part of the IP into binary. It is storing them into a 2D Array.
    for (int i = 0; i < 4; i++) {
        int a = 0;
        while (parts[i] > 0) {
            binaryip[i][a++] = parts[i] % 2;
            parts[i] /= 2;
        }
    }

    // Will check if there are 8 binaries in each octet, if there are less (because the decimal number was not big) it will add leading 0's until it is 8 digits.
    for (int i = 0; i < 4; i++) {
        for (int b = 0; b < 8; b++) {
            if (!(binaryip[i][b] == 0 || binaryip[i][b] == 1)) {
                binaryip[i][b] = 0;
            }
        }
    } 

    // Converting the each part of the IP (which is int) into a string.
    sprintf(octet_1, "%d%d%d%d%d%d%d%d", binaryip[0][7], binaryip[0][6], binaryip[0][5], binaryip[0][4], binaryip[0][3], binaryip[0][2], binaryip[0][1], binaryip[0][0]);
    sprintf(octet_2, "%d%d%d%d%d%d%d%d", binaryip[1][7], binaryip[1][6], binaryip[1][5], binaryip[1][4], binaryip[1][3], binaryip[1][2], binaryip[1][1], binaryip[1][0]);
    sprintf(octet_3, "%d%d%d%d%d%d%d%d", binaryip[2][7], binaryip[2][6], binaryip[2][5], binaryip[2][4], binaryip[2][3], binaryip[2][2], binaryip[2][1], binaryip[2][0]);
    sprintf(octet_4, "%d%d%d%d%d%d%d%d", binaryip[3][7], binaryip[3][6], binaryip[3][5], binaryip[3][4], binaryip[3][3], binaryip[3][2], binaryip[3][1], binaryip[3][0]);
    sprintf(binary_ip, "%s.%s.%s.%s", octet_1, octet_2, octet_3, octet_4); // It saves all the IP parts into one string that is in a form of the IP.

    printf("The binary IP is: %s\n", binary_ip);
}

void binaryToDecimal(int *parts) {
    int decimal_ip[4]; 

    for (int i = 0; i < 4; i++) { // Utilizing the pow from math library so we can convert binary to decimal
        int sum = 0;
        for (int j = 0; j < 8; j++) {
            int a = parts[i] % 10;
            sum += a * pow(2, j);
            parts[i] /= 10;
        }
        decimal_ip[i] = sum;
    }
    printf("The decimal IP is: %d.%d.%d.%d\n", decimal_ip[0], decimal_ip[1], decimal_ip[2], decimal_ip[3]);
}

void logo() {
    
    printf("+---------------------+\n");
    printf("|    IP Converter     |\n");
    printf("|                     |\n");
    printf("|  Unmasked Subnets   |\n");
    printf("+---------------------+\n");
}
