#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putstr_non_printable(char *str)
{
    int i;
    char hex_chars[] = "0123456789abcdef";

    i = 0;
    while (str[i] != '\0')  // Percorre cada caractere da string
    {
        if (str[i] >= 32 && str[i] <= 126)  // Verifica se o caractere é imprimível
        {
            ft_putchar(str[i]);  // Se for imprimível, imprime o caractere
        }
        else  // Se o caractere não for imprimível
        {
            ft_putchar('\\');  // Imprime a barra invertida
            ft_putchar(hex_chars[(unsigned char)str[i] / 16]);  // Imprime o primeiro dígito hexadecimal
            ft_putchar(hex_chars[(unsigned char)str[i] % 16]);  // Imprime o segundo dígito hexadecimal
        }
        i++;
    }
}