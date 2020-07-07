/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 512

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }
    
    char* infile = argv[1];
    
    FILE* file = fopen(infile, "r");
    if (file == NULL)
    {
        printf("Could not open 'card.raw'.\n");
        return 2;
    }
    
    unsigned char buffer [BLOCK_SIZE];
    
    char filename[8];
    
    int k = 0;
    
    char arr_0[4] = {0xff, 0xd8, 0xff, 0xe0};
    char arr_1[4] = {0xff, 0xd8, 0xff, 0xe1};
    
    FILE* img = NULL;
    
    while (fread(buffer, BLOCK_SIZE, 1, file) == 1)
    {
        if (memcmp(arr_0, buffer, 4) == 0 || memcmp(arr_1, buffer, 4) == 0)
        {        
            if (k > 0)
                fclose(img);
            
            sprintf(filename, "%03d.jpg", k);
            
            img = fopen(filename, "w");
            if (img == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
            k++;
        }
        if (img != NULL)
            fwrite(buffer, BLOCK_SIZE, 1,img);                  
    }
    
    fclose(img);
    fclose(file);
    
    return 0;
    
}
