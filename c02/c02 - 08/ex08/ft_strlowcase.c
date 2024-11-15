char *ft_strlowcase(char *str)
{
    int i;

    // Garantir que a string está bem inicializada
    if (str == NULL)
        return NULL; // Verifica se a string é nula (caso de erro)
    
    i = 0;
    while (str[i] != '\0') // Itera até o fim da string
    {
        if (str[i] >= 'A' && str[i] <= 'Z') // Verifica se o caractere é maiúsculo
        {
            str[i] += 32; // Converte para minúsculo
        }
        i++;
    }
    return str; // Retorna a string convertida
}