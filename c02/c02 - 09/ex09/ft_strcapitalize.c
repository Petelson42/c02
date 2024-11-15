
#include <stdio.h>
#include <ctype.h>

char *ft_strcapitalize(char *str)
{
    int i = 0;
    int in_word = 0; // Indica se estamos no meio de uma palavra

    while (str[i] != '\0') // Percorre a string até o final
    {
        // Se o caractere atual é alfanumérico
        if (isalnum(str[i]))
        {
            // Se for a primeira letra de uma palavra, capitaliza
            if (!in_word)
            {
                str[i] = toupper(str[i]); // Converte para maiúscula
                in_word = 1; // Estamos dentro de uma palavra agora
            }
            else
            {
                str[i] = tolower(str[i]); // Converte para minúscula
            }
        }
        else
        {
            in_word = 0; // Estamos fora de uma palavra, portanto a próxima letra será a primeira de uma nova palavra
        }
        i++;
    }

    return str;
}