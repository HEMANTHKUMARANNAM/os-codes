#include <stdio.h>

int main()
{
    int array_a1[30], array_a2[30], array_a3[30], array_a4[30], array_a5[30], array_a6[30];
    int div, count, j, key, plaintext, temp, dec = 0;
    
    printf("\nEnter a Plain-Text value:\t");
    scanf("%d", &plaintext);

    printf("\nEnter the Key:\t");
    scanf("%d", &key);

    printf("\nEnter the Bit-Stream\n");
    for (count = 0; count < plaintext; count++)
    {
        scanf("%d", &array_a1[count]);
    }

    div = plaintext / 2;
    temp = div - key;
    for (count = 0; count <= temp; count++)
    {
        array_a3[count] = 0;
        dec++;
    }
    dec = dec - 1;

    printf("Enter the Key Bit Stream\n");
    for (count = 0; count < key; count++)
    {
        scanf("%d", &array_a3[dec++]);
    }

    printf("Left Hand\n");
    for (count = 0; count < div; count++)
    {
        array_a5[count] = array_a1[count];
        printf("%d", array_a1[count]);
    }
    printf("\nRight Hand\n");
    for (count = div; count < plaintext; count++)
    {
        array_a2[count - div] = array_a1[count];
        printf("%d", array_a1[count]);
    }
    printf("\n");

    // Ensure array_a6 is properly initialized
    for (j = 0; j < key; j++)
    {
        if (array_a2[j] == 1 && array_a3[j] == 1)
        {
            array_a6[j] = 0;
        }
        else if (array_a2[j] == 1 && array_a3[j] == 0)
        {
            array_a6[j] = 1; // Corrected logic to make array_a6 consistent
        }
        else
        {
            array_a6[j] = 0;
        }
    }

    printf("\nFirst XOR\n");
    for (count = 0; count < key; count++)
    {
        printf("%d", array_a6[count]);
    }
    printf("\n");

    for (j = 0; j < div; j++)
    {
        if (array_a5[j] == 1 && array_a6[j] == 1)
        {
            array_a4[j] = 0;
        }
        else if (array_a5[j] == 1 && array_a6[j] == 0)
        {
            array_a4[j] = 1; // Corrected logic to make array_a4 consistent
        }
        else if (array_a5[j] == 0 && array_a6[j] == 1)
        {
            array_a4[j] = 1; // Corrected logic to make array_a4 consistent
        }
        else
        {
            array_a4[j] = 0;
        }
    }

    printf("\nSecond XOR\n");
    for (count = 0; count < div; count++)
    {
        printf("%d", array_a4[count]);
    }
    printf("\n");

    return 0;
}
