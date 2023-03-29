# Binary Operations


[![License](http://img.shields.io/:license-Apache%202-blue.svg)](http://www.apache.org/licenses/LICENSE-2.0.txt)

A simple didatic implementation of same basic binary operations in C/C++ language, in a code::block windows project.

This implementation was created for academic use. 


## Use Cases

Use this for:

- If you just want to review basic binary operatins in C
- basic network operations between IP and MASC
- basic operations of logic ports


## Compilation

```
g++.exe -Wall -fexceptions -g -std=c++0x  -c main.cpp -o obj\Debug\main.o
g++.exe  -o bin\Debug\BinaryOperations.exe obj\Debug\main.o   
```


## Usage

Simple usage (basically choose an option in a C++ menu):

```c++
int main()
{
		....
		
		printf("Pick a choice from the list:     \n");
		printf("                                 \n");
		printf("  1 - showBasicBinaryOperations  \n");
		printf("                                 \n");
		printf("  2 - showLogicPortOperations  \n");
		printf("                                 \n");
		printf("  3 - showNetworkOperations      \n");
		printf("                                 \n");
		printf("  4 - Finish                     \n");

		...
		
    return 0;
}

```



# Execution Example

	show menu:
``` 
Pick a choice from the list:

  1 - showBasicBinaryOperations

  2 - showLogicPortOperations

  3 - showNetworkOperations

  4 - Finish
```

	Show Nework calculus:

``` 
------- CONSIDERING THE FOLLOWING: ---------:

 1. GET WILCARD EXECUTING NOT IN MASC:
-----------------------------------


IP   DECIMAL NUMBER 192.168.43.189
MASC DECIMAL NUMBER 255.255.255.128
                    ---------------
MASC DECIMAL NUMBER 0.0.0.127

IP BYNARY NUMBER:  11000000.10101000.00101011.10111101
MASC BYNARY NUMBER:11111111.11111111.11111111.10000000
                   -----------------------------------
WILDCARD          :00000000.00000000.00000000.01111111


 2. GET SUB-NET EXECUTING 'AND' BETWEEN IP AND MASC:
-----------------------------------


IP   DECIMAL NUMBER 192.168.43.189
MASC DECIMAL NUMBER 255.255.255.128
                    ---------------
MASC DECIMAL NUMBER 192.168.43.128

IP BYNARY NUMBER:  11000000.10101000.00101011.10111101
MASC BYNARY NUMBER:11111111.11111111.11111111.10000000
                   -----------------------------------
SUB-NET           :11000000.10101000.00101011.10000000


 3. GET BROADCAST EXECUTING 'OR' BETWEEN WILDCARD AND SUB-NET:
-----------------------------------


IP   DECIMAL NUMBER 192.168.43.189
MASC DECIMAL NUMBER 255.255.255.128
                    ---------------
MASC DECIMAL NUMBER 192.168.43.255

IP BYNARY NUMBER:  11000000.10101000.00101011.10111101
MASC BYNARY NUMBER:11111111.11111111.11111111.10000000
                   -----------------------------------
SUB-NET           :11000000.10101000.00101011.11111111

 4. GET IP VALID LIST SUB-NET + 1 UNTIL BROADCAST -1:
-----------------------------------


FIRST IP ADRESS (FROM SUB-NET +1):
  -----------------------------------
DECIMAL NUMBER       :192.168.43.129
BINARY CORRESPONDENT :11000000.10101000.00101011.10000001

LAST IP ADRESS (UNTIL BROADCAST -1):
  -----------------------------------
DECIMAL NUMBER       : 192.168.43.254
BINARY CORRESPONDENT :11000000.10101000.00101011.11111110
``` 


## References:

[1.] [Subnetwork](<https://en.wikipedia.org/wiki/Subnetwork> "Wikipedia:Subnetwork")

[2.] [Logic gate](<https://en.wikipedia.org/wiki/Logic_gate> "Wikipedia:Logic gate")

[3.] [Operator Computer](<https://en.wikipedia.org/wiki/Operator_(computer_programming)> "Wikipedia:Operator Computer")

