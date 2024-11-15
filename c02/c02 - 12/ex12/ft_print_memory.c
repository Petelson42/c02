#include <unistd.h>
#include <stdint.h>  // Necessário para uintptr_t

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr_base(unsigned int nbr, char *base)
{
    unsigned int len = 0;
    unsigned int temp = nbr;

    // Calcular o comprimento da base
    while (base[len])
        len++;

    // Caso o número seja maior que 0
    if (nbr >= len)
        ft_putnbr_base(nbr / len, base);
    ft_putchar(base[nbr % len]);
}

void ft_print_memory(void *addr, unsigned int size)
{
    unsigned char *ptr = addr;
    unsigned int i, j;
    
    // Se o tamanho for 0, não imprimimos nada
    if (size == 0)
        return;

    for (i = 0; i < size; i += 16)  // Processa a memória em blocos de 16 bytes
    {
        // Imprimir o endereço da linha atual
        ft_putnbr_base((uintptr_t)(ptr + i), "0123456789abcdef");
        ft_putchar(':');
        ft_putchar(' ');

        // Imprimir os valores hexadecimais
        for (j = 0; j < 16; j++)
        {
            if (i + j < size)  // Imprime apenas até o final da memória
                ft_putnbr_base(ptr[i + j], "0123456789abcdef");
            else
                ft_putchar(' ');  // Preenche com espaço se não houver valor
            ft_putchar(' ');  // Espaço entre os bytes
        }

        // Imprimir os caracteres legíveis
        for (j = 0; j < 16; j++)
        {
            if (i + j < size)  // Imprime até o final da memória
            {
                if (ptr[i + j] >= 32 && ptr[i + j] <= 126)
                    ft_putchar(ptr[i + j]);  // Imprime o caractere, se for imprimível
                else
                    ft_putchar('.');  // Caso contrário, imprime um ponto
            }
        }
        
        ft_putchar('\n');  // Nova linha ao final de cada bloco
    }
}

int main(void)
{
    char str[] = "Bonjour les amis. C'est une phrase.\nHello world!";
    ft_print_memory(str, 64);  // Exemplo de uso
    return 0;
}

