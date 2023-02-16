# IP-Converter

![💻_IP_Converter_ (3)](https://user-images.githubusercontent.com/116773652/217944775-814bb302-4527-4260-9c2e-e347a81047c7.png)

## Overview

This is a simple C program that runs in the terminal and allows for the conversion of decimal IP addresses to binary and vice versa.

## Features

- Ability to convert binary IP addresses to decimal
- Ability to convert decimal IP addresses to binary
- Error checking for IP addresses
- Reusable as many times as desired by the user 

## Installation

1) Clone the repository:

```
git clone https://github.com/Kaddakos/IP.Converter.git
```

2. Change into the project directory:

```
cd IP.Converter
```

3. Compile the program using gcc:

```
gcc -o ip_converter ip_converter.c
```

4. Run the program:

```
./ip_converter
```

If you don't have GCC installed, you can install it by following the instructions for your operating system.

Alternatively, the code may be copied and pasted into an editor for execution, or even an online compiler such as **[onlinegdb](https://www.onlinegdb.com/online_c_compiler)**

## Usage

Upon execution, the program will present three options:

- Convert a decimal IP address to a binary IP address
- Convert a binary IP address to a decimal IP address
- Exit

You will be prompted to make a selection by typing either `1`, `2`, or `3`. If you select `3`, the program will terminate.

You will then be asked to provide an IP address in the format of x.x.x.x. The program will then validate the IP address entered.

In the case of an invalid IP address, an error message will be displayed and you will be prompted to enter a new IP.

Once the conversion is complete, the program will display the resulting IP and prompt you to restart the program by typing either `y` or `n`.

![ezgif-3-3f4c34a5b5](https://user-images.githubusercontent.com/116773652/217937290-fe06bdee-7c32-4bbc-ac5a-50dfbcb6fdc5.gif)


## Explanation

The program prompts the user to select a menu choice by inputting the desired option. This input is saved as the **menu_choice** variable and is verified for validity through the use of a **do-while loop**. If the input is invalid, the user will continue to be prompted until a valid option is provided.

The **switch** method is then employed to execute the corresponding functions based on the selected menu choice. There are four functions in total: two functions for obtaining and validating the IP addresses (in decimal or binary format), and two functions for performing the conversion between the two formats.

- verify_decimal_IP - This function prompts the user to enter an IP address in decimal format, and checks if it consists of four octets with values ranging from 0 to 255.

- verify_binary_IP - This function prompts the user to enter an IP address in binary format, and checks if it consists of four octets with 8 digits each and if the digits are binary.

- decimalToBinary - This function takes each octet of the decimal IP address and converts it to binary, adding leading zeros if necessary to ensure each octet has 8 digits.

- binaryToDecimal - This function takes each octet of the binary IP address and converts it to decimal.

- In the verification functions, various error checks have been implemented and error messages have been provided to guide the user on proper usage of the program.

Finally, the program asks the user if they would like to restart the program. If the user inputs `y`, the program restarts and the user can perform another conversion. If the user inputs `n`, the program terminates. This is achieved through the use of another **do-while loop**.

**For more insight into the code implementation, kindly refer to the code and its accompanying comments. The code has been thoroughly commented to provide clarity and understanding of each component.**

## Contributors 

**[billpan84](https://github.com/billpan84)**

**[2wheelrider](https://github.com/2wheelrider)**
