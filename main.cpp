#include <stdio.h>

void printBinary(const char * text, void const * const p, const char * text2 , size_t const size);
void showBasicBinaryOperations();
void showLogicPortOperations();
void showNetworkOperations();

int main()
{
    int choice = 0;
    do
    {
		printf("Pick a choice from the list:     \n");
		printf("                                 \n");
		printf("  1 - showBasicBinaryOperations  \n");
		printf("                                 \n");
		printf("  2 - showLogicPortOperations  \n");
		printf("                                 \n");
		printf("  3 - showNetworkOperations      \n");
		printf("                                 \n");
		printf("  4 - Finish                     \n");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                showBasicBinaryOperations();
                break;

            case 2:
                showLogicPortOperations();
                break;

            case 3:
                showNetworkOperations();
                break;

            case 4:
                printf("FINISHING...\n");
                break;

            default:
                printf("Bad choice! Please try again later.\n");
        }
    } while (choice > 0 && choice <= 3);

	return 0;
}

void printBinary(const char * text, void const * const p, const char * text2 = "\n", size_t const size = sizeof(unsigned char))
{
    unsigned char *b = (unsigned char*) p;
    printf("%s",text);
    for (int i=size-1;i>=0;i--)
        for (int j=7;j>=0;j--)
            printf("%u", (b[i] >> j) & 1);
    printf("%s",text2);
}

void showBasicBinaryOperations()
{
    const unsigned char F = 0x00; //Falso
    const unsigned char V = 0x01; //Verdadeiro

    printf("Impressao dos valores de F e V:\n");
    printBinary("Zero = ", &V);
    printBinary("Ummm = ",&F);
    printf("\n");

	const unsigned char valor1      = 0x0A; //0000 1010
	const unsigned char valor2      = 0x0C; //0000 1100
	const unsigned char valor3      = 0x08; //0000 1000
	const unsigned char valor4      = 0x0E; //0000 1110
	const unsigned char valor5      = 0x06; //0000 0110
	const unsigned char valor6      = 0x01; //0000 0001
	const unsigned char valor7      = 0xFE; //1111 1110
	unsigned char valorX            = 0x00;


    printBinary("0x0A =                ", &valor1);
    printBinary("0x0C =                ", &valor2);
    printBinary("0x08 =                ", &valor3);
    printBinary("0x0E =                ", &valor4);
    printBinary("0x06 =                ", &valor5);
    printBinary("0x01 =                ", &valor6);
    printBinary("0xFE =                ", &valor7);

	valorX = valor6+valor7;
    printBinary("0x01 +  0xFE =        ", &valorX);

	valorX += valor6;
    printBinary("0x01 +  0xFE + 0x01 = ", &valorX);

	valorX += valor6;
    printBinary("0x01 +  0xFE + 0x01 = ", &valorX);

	printf("\n");
    printf("------- NOT OPERATION: -------------:\n");
    valorX = ~0x0C;
    printBinary("NOT 0x0C =            ", &valorX);

	printf("\n");
    printf("------- AND OPERATION: -------------:\n");
    valorX = 0x0C & 0x0A;
    printBinary("0x0C AND 0x0A =       ", &valorX);

	printf("\n");
    printf("-------  OR OPERATION: -------------:\n");
    valorX = 0x0C | 0x0A;
    printBinary("0x0C OR 0x0A  =       ", &valorX);

	printf("\n");
    printf("------- SUM OPERATION -------------:\n");
    valorX = 0x0C + 0x0A;
    printBinary("0x0C =                ", &valor2);
    printBinary("0x0A =                ", &valor1);
    printBinary("0x0C + 0x0A   =       ", &valorX);

	printf("\n");
    printf("------- SUB OPERATION ---------:\n");
    printBinary("0x0C =                ", &valor2);
    printBinary("0x0A =                ", &valor1);
    valorX = 0x0C - 0x0A;
    printBinary("0x0C - 0x0A   =       ", &valorX);

	printf("\n");
    printf("------- SUB OPERATION ---------:\n");
    printBinary("0x0A =                ", &valor1);
    printBinary("0x0C =                ", &valor2);
    valorX = 0x0A - 0x0C;
    printBinary("0x0A - 0x0C   =       ", &valorX);

}

void showLogicPortOperations()
{
	const unsigned char F = 0x00; //Falso
	const unsigned char V = 0x01; //Verdadeiro

	printf("Logic Port NOT:\n");
	printf("A | S\n");
	printf("%X | %X\n", V, !V );
	printf("%X | %X\n", F, !F );

    printf("\n");
	printf("Logic Port AND:\n");
	printf("A B | S\n");
	printf("%X %X | %X\n", F, F, (F && F) );
	printf("%X %X | %X\n", F, V, (F && V) );
	printf("%X %X | %X\n", V, F, (V && F) );
	printf("%X %X | %X\n", V, V, (V && V) );

    printf("\n");
	printf("Logic Port OR:\n");
	printf("A B | S\n");
	printf("%X %X | %X\n", F, F, (F || F) );
	printf("%X %X | %X\n", F, V, (F || V) );
	printf("%X %X | %X\n", V, F, (V || F) );
	printf("%X %X | %X\n", V, V, (V || V) );

    printf("\n");
	printf("Logic Port NAND:\n");
	printf("A B | S\n");
	printf("%X %X | %X\n", F, F, !(F && F) );
	printf("%X %X | %X\n", F, V, !(F && V) );
	printf("%X %X | %X\n", V, F, !(V && F) );
	printf("%X %X | %X\n", V, V, !(V && V) );

    printf("\n");
	printf("Logic Port NOR:\n");
	printf("A B | S\n");
	printf("%X %X | %X\n", F, F, !(F || F) );
	printf("%X %X | %X\n", F, V, !(F || V) );
	printf("%X %X | %X\n", V, F, !(V || F) );
	printf("%X %X | %X\n", V, V, !(V || V) );

    printf("\n");
	printf("Logic Port XOR:\n");
	printf("A B | S\n");
	printf("%X %X | %X\n", F, F, 0 );
	printf("%X %X | %X\n", F, V, 0 );
	printf("%X %X | %X\n", V, F, 0 );
	printf("%X %X | %X\n", V, V, 0 );

    printf("\n");
	printf("Logic Port XNOR:\n");
	printf("A B | S\n");
	printf("%X %X | %X\n", F, F, 0 );
	printf("%X %X | %X\n", F, V, 0 );
	printf("%X %X | %X\n", V, F, 0 );
	printf("%X %X | %X\n", V, V, 0 );
}


void showNetworkOperations()
{
	printf("\n");
    printf("------- NETWORIKING EXAMPLES: ---------:\n");

    unsigned char  __IP1;
    unsigned char  __IP2;
    unsigned char  __IP3;
    unsigned char  __IP4;

    unsigned char  __MASC1;
    unsigned char  __MASC2;
    unsigned char  __MASC3;
    unsigned char  __MASC4;

    unsigned char  __WILD1;
    unsigned char  __WILD2;
    unsigned char  __WILD3;
    unsigned char  __WILD4;

    unsigned char  __SUBNET1;
    unsigned char  __SUBNET2;
    unsigned char  __SUBNET3;
    unsigned char  __SUBNET4;

    unsigned char  __BROAD1;
    unsigned char  __BROAD2;
    unsigned char  __BROAD3;
    unsigned char  __BROAD4;


	printf("\n");
    printf("------- CONSIDERING THE FOLLOWING: ---------:\n");
	printf("\n");

    __IP1 = 192;
    __IP2 = 168;
    __IP3 = 43;
    __IP4 = 189;

    __MASC1 = 255;
    __MASC2 = 255;
    __MASC3 = 255;
    __MASC4 = 128;

    __WILD1 = 0;
    __WILD2 = 0;
    __WILD3 = 0;
    __WILD4 = 0;

    __SUBNET1 = 0;
    __SUBNET2 = 0;
    __SUBNET3 = 0;
    __SUBNET4 = 0;

    __BROAD1 = 0;
    __BROAD2 = 0;
    __BROAD3 = 0;
    __BROAD4 = 0;

    printf("IP   DECIMAL NUMBER %d.%d.%d.%d\n", __IP1, __IP2, __IP3, __IP4);
    printf("MASC DECIMAL NUMBER %d.%d.%d.%d\n", __MASC1, __MASC2, __MASC3, __MASC4);
	printf("\n");


    printBinary("IP BYNARY NUMBER:  ", &__IP1, ""); printBinary(".", &__IP2, ""); printBinary(".", &__IP3, ""); printBinary(".", &__IP4, "");
	printf("\n");
    printBinary("MASC BYNARY NUMVER:", &__MASC1, ""); printBinary(".", &__MASC2, ""); printBinary(".", &__MASC3, ""); printBinary(".", &__MASC4, "");
	printf("\n");
	printf("\n");
    printf("------- CONSIDERING THE FOLLOWING: ---------:\n");
    printf("\n");
    printf(" 1. GET WILCARD EXECUTING NOT IN MASC:   \n");
    printf("-----------------------------------\n");
    printf("\n");
    printf("\n");
    __WILD1 = ~__MASC1;
    __WILD2 = ~__MASC2;
    __WILD3 = ~__MASC3;
    __WILD4 = ~__MASC4;


    printf("IP   DECIMAL NUMBER %d.%d.%d.%d\n", __IP1, __IP2, __IP3, __IP4);
    printf("MASC DECIMAL NUMBER %d.%d.%d.%d\n", __MASC1, __MASC2, __MASC3, __MASC4);
    printf("                    ---------------\n");
    printf("MASC DECIMAL NUMBER %u.%u.%u.%u\n", (unsigned char)__WILD1, (unsigned char)__WILD2, (unsigned char)__WILD3, (unsigned char)__WILD4);
	printf("\n");


    printBinary("IP BYNARY NUMBER:  ", &__IP1, ""); printBinary(".", &__IP2, ""); printBinary(".", &__IP3, ""); printBinary(".", &__IP4, "");
	printf("\n");
    printBinary("MASC BYNARY NUMBER:", &__MASC1, ""); printBinary(".", &__MASC2, ""); printBinary(".", &__MASC3, ""); printBinary(".", &__MASC4, "");
    printf("\n");
    printf("                   -----------------------------------\n");
    printBinary("WILDCARD          :", &__WILD1, ""); printBinary(".", &__WILD2, ""); printBinary(".", &__WILD3, ""); printBinary(".", &__WILD4, "");
	printf("\n");
	printf("\n");


    printf("\n");
    printf(" 2. GET SUB-NET EXECUTING 'AND' BETWEEN IP AND MASC:   \n");
    printf("-----------------------------------\n");
    printf("\n");
    printf("\n");
    __SUBNET1 = __MASC1 & __IP1;
    __SUBNET2 = __MASC2 & __IP2;
    __SUBNET3 = __MASC3 & __IP3;
    __SUBNET4 = __MASC4 & __IP4;


    printf("IP   DECIMAL NUMBER %d.%d.%d.%d\n", __IP1, __IP2, __IP3, __IP4);
    printf("MASC DECIMAL NUMBER %d.%d.%d.%d\n", __MASC1, __MASC2, __MASC3, __MASC4);
    printf("                    ---------------\n");

    printf("MASC DECIMAL NUMBER %u.%u.%u.%u\n", (unsigned char)__SUBNET1, (unsigned char)__SUBNET2, (unsigned char)__SUBNET3, (unsigned char)__SUBNET4);
	printf("\n");


    printBinary("IP BYNARY NUMBER:  ", &__IP1, ""); printBinary(".", &__IP2, ""); printBinary(".", &__IP3, ""); printBinary(".", &__IP4, "");
	printf("\n");
    printBinary("MASC BYNARY NUMBER:", &__MASC1, ""); printBinary(".", &__MASC2, ""); printBinary(".", &__MASC3, ""); printBinary(".", &__MASC4, "");
    printf("\n");
    printf("                   -----------------------------------\n");
    printBinary("SUB-NET           :", &__SUBNET1, ""); printBinary(".", &__SUBNET2, ""); printBinary(".", &__SUBNET3, ""); printBinary(".", &__SUBNET4, "");
	printf("\n");
	printf("\n");


    printf("\n");
    printf(" 3. GET BROADCAST EXECUTING 'OR' BETWEEN WILDCARD AND SUB-NET:   \n");
    printf("-----------------------------------\n");
    printf("\n");
    printf("\n");
    __BROAD1 = __WILD1 | __SUBNET1;
    __BROAD2 = __WILD2 | __SUBNET2;
    __BROAD3 = __WILD3 | __SUBNET3;
    __BROAD4 = __WILD4 | __SUBNET4;


    printf("IP   DECIMAL NUMBER %d.%d.%d.%d\n", __IP1, __IP2, __IP3, __IP4);
    printf("MASC DECIMAL NUMBER %d.%d.%d.%d\n", __MASC1, __MASC2, __MASC3, __MASC4);
    printf("                    ---------------\n");

    printf("MASC DECIMAL NUMBER %u.%u.%u.%u\n", (unsigned char)__BROAD1, (unsigned char)__BROAD2, (unsigned char)__BROAD3, (unsigned char)__BROAD4);
	printf("\n");


    printBinary("IP BYNARY NUMBER:  ", &__IP1, ""); printBinary(".", &__IP2, ""); printBinary(".", &__IP3, ""); printBinary(".", &__IP4, "");
	printf("\n");
    printBinary("MASC BYNARY NUMBER:", &__MASC1, ""); printBinary(".", &__MASC2, ""); printBinary(".", &__MASC3, ""); printBinary(".", &__MASC4, "");
    printf("\n");
    printf("                   -----------------------------------\n");
    printBinary("SUB-NET           :", &__BROAD1, ""); printBinary(".", &__BROAD2, ""); printBinary(".", &__BROAD3, ""); printBinary(".", &__BROAD4, "");
	printf("\n");
	printf("\n");



    printf(" 4. GET IP VALID LIST SUB-NET + 1 UNTIL BROADCAST -1:   \n");
    printf("-----------------------------------\n");
    printf("\n");
    printf("\n");
    __BROAD4--;
    __SUBNET4++;

    printf("FIRST IP ADRESS (FROM SUB-NET +1):\n");
    printf("  -----------------------------------\n");
    printf("DECIMAL NUMBER       :%u.%u.%u.%u\n", (unsigned char)__SUBNET1, (unsigned char)__SUBNET2, (unsigned char)__SUBNET3, (unsigned char)__SUBNET4);
    printBinary("BINARY CORRESPONDENT :", &__SUBNET1, ""); printBinary(".", &__SUBNET2, ""); printBinary(".", &__SUBNET3, ""); printBinary(".", &__SUBNET4, "");
	printf("\n");
	printf("\n");

    printf("LAST IP ADRESS (UNTIL BROADCAST -1):\n");
    printf("  -----------------------------------\n");
    printf("DECIMAL NUMBER       : %u.%u.%u.%u\n", (unsigned char)__BROAD1, (unsigned char)__BROAD2, (unsigned char)__BROAD3, (unsigned char)__BROAD4);
    printBinary("BINARY CORRESPONDENT :", &__BROAD1, ""); printBinary(".", &__BROAD2, ""); printBinary(".", &__BROAD3, ""); printBinary(".", &__BROAD4, "");
	printf("\n");
	printf("\n");


	printf("\n");
	printf("\n");

}

