#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

string encipher(string plaintext , int key);

int main(int argc , string argv[])
{
    // refusing more than one key entered 
    if (argc != 2)
    {
        printf("Please enter one key next to the file name using space\n");
        return 1;
    }
    string key_command = argv[1];
    // refusing non-numeric keys
    for (int i = 0; i < strlen(key_command); i++)
    {
        if (isdigit(key_command[i]) == 0)
        {
        printf("Usage: ./caesar key\n");
        return 1;
        }
    }
    // changing command line arg to integer
    int key = atoi(key_command) % 26;

    string plaintext = get_string("Plaintext: ");
    string ciphertext = encipher(plaintext , key);
    printf("ciphertext: %s\n", ciphertext);
}

// function does the encryption and returns the ciphertext

string encipher(string plaintext , int key)
{
    string ciphertext = plaintext;
    for (int i = 0; i < strlen(plaintext); i++)
    {
        // checking if uppercase and converting
        
        if (isupper(plaintext[i]))
        {
            int temp = plaintext[i] - 65;
            int ci = (temp + key) % 26;
            ciphertext[i] = ci + 65;
        }
        
        // checking if lowercase and converting
        
        else if (islower(plaintext[i]))
        {
            int temp = plaintext[i] - 97;
            int ci = (temp + key) % 26;
            ciphertext[i] = ci + 97;
        }
        
        // if not upper or lower copy it as it is
        
        else
        {
            ciphertext[i] = plaintext[i];    
        }
    }
    return ciphertext;
}