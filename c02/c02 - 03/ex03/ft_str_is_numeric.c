int ft_str_is_numeric(char *str)
{
    int i = 0;

    // Verifica cada caractere da string
    while (*(str + i) != '\0')
    {
        // Se o caractere não estiver entre '0' e '9', retorne 0
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }

    return 1;
}