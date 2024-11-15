
#include <stdio.h>

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t i;

    // Se size é 0, não copiamos nada
    if (size == 0)
        return 0;

    // Copiar caracteres de src para dest até o limite size-1
    for (i = 0; i < size - 1 && src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }

    // Garantir que a string de destino seja terminada com '\0'
    dest[i] = '\0';

    // Retornar o comprimento total da string src
    while (src[i] != '\0') // Se o tamanho de src for maior que size-1
        i++;

    return i;
}