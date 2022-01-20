#include <stdio.h>
#include <cs50.h>
#include <string.h>

string get_input(void);
int key_validator(string cy_key, int cy_key_length);
void encoder(string input_text, string cy_key);
int main(int argc, string argv[])
{
   
    if (argc != 2)
    {
        printf("Please provide only 2 Command Line arguemnets. The execution Command and the cypher key.\n");
        return 1;
        
    }
   
    string plain_text = get_input();
    
    string key = argv[1];
    int key_len = strlen(key);
    
    
    return key_validator(key, key_len);
    encoder(plain_text, key);

    return 0;


}






string get_input(void)
{
    string plain_text = get_string("Plain Text: ");
    return plain_text;
}

int key_validator(string cy_key, int cy_key_length)
{
    for (int i = 0; i < cy_key_length; i++)
    {
        int letter_pos = (int)(cy_key[i]);
        
        if (cy_key_length != 26)
        {
           
            return 1;
        }
    
        if (letter_pos < 65 || (letter_pos > 90 && letter_pos < 97) || letter_pos > 122)
        {
            printf("Your key may only contain alphabet characters\n");
            return 1;
        } 
    
        for(int j = i+1; j < cy_key_length; j++)
        {
            if(cy_key[i] == cy_key[j])
            {
                printf("NO DUPLICATES\n");
                return 1;
            }   
        }   
    }
    

    return 0;
}

void encoder(string input_text, string cy_key)
{
    int size = strlen(input_text);
    char cypher_text[size];
    int alpha_order;
    int plain_text_character_integer;
    
    
    for (int i = 0, n = size; i < n; i++)
    {
        plain_text_character_integer = (int)(input_text[i]);
        
        if(plain_text_character_integer >= 65 && plain_text_character_integer <= 90)//CAPITAL
        {
            
            alpha_order = (plain_text_character_integer + 26) - 90;
        
            
        }
        
        else if((plain_text_character_integer >= 97) && (plain_text_character_integer <= 122))//LOWER CASE
        {
        
         alpha_order = (plain_text_character_integer + 26) - 122;
        
            
        }
        
        
        if((plain_text_character_integer < 65) || ((plain_text_character_integer > 90) && (plain_text_character_integer < 97)) || (plain_text_character_integer > 122))
        {
            
            cypher_text[i] = input_text[i];
        
        }
        else
        {
            
            cypher_text[i] = cy_key[alpha_order-1];
        
        }
        
        if(((int)(cypher_text[i]) >= 65 && (int)(cypher_text[i]) <= 90) && plain_text_character_integer >= 97 && plain_text_character_integer <= 122)
        {
            
            cypher_text[i] = (char)((int)(cypher_text[i]) + 32);
        
        }
    }
    
    
    printf("ciphertext: %s\n",cypher_text);   
}