/* TextRip.c - A Program to rip legiable text from binary files
**
*/

/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include        <stdio.h>
#include        <conio.h>
#include		<malloc.h>
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

main (int argc, char **argv)

{
    FILE    *f1;
    int     buffer  = 32767;
    char    *pBuffer;
    int     n;
    int     x;

    printf("TextRip v1.o1a - 17.10.96 - MaF\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    while (1)
    {
        pBuffer = (char *)malloc(buffer);

        if ( pBuffer || (buffer < 1024) )
        {
            break;
        }
        else
        {
            buffer = buffer / 2;
        }
    }
        
    if ( !pBuffer )
    {
        printf(" Err : Cant allocate enough memory \n");
        return 0;
    }

    printf("Allocated %d bytes for rip buffer.\n",buffer);
    printf("Processing file %s ... \n\n",argv[1]);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    if ( argc < 2 )
    {
        printf("A diddy little program that ripz A..Z, a..z SPACE & _ from binary files\n");
        printf("and sends the output to STDOUT.  Suggested usage: \n\n");
        printf("  'Textrip filename.ext > output.txt' \n\n");
		return 0;
    }

    f1 = fopen(argv[1], "rb");
    
    if ( !f1 )
    {
        printf("Err : Cant open file %s \n",argv[1]);
        return 0;
    }

    while (1)
    {          
        n = fread( pBuffer, 1, buffer, f1);                 /* Should read 1kb at a time           */

        if (!n) break;

        for (x = 0; x < n; x++)
        {
            if ( ( (pBuffer[x] >= 'a') && (pBuffer[x] <= 'z') ) ||   /* If the char is lowercase alphabetic */
                 ( (pBuffer[x] >= 'A') && (pBuffer[x] <= 'Z') ) ||   /* or upper case alphabetic            */
                 ( (pBuffer[x] == '_') ) ||                          /* or an underscore                    */
                 ( (pBuffer[x] == ' ') ) ||                          /* or a space then print it!           */
                 ( (pBuffer[x] == 10 ) ) )                           /* or a CR code                        */    
                 printf("%c",pBuffer[x]);
        }
    }

    fclose(f1);
    free( pBuffer );

    return 0;
}


