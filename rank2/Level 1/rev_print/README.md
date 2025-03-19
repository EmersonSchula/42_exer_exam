## Subject

```
Nome da tarefa: rev_print
Arquivos esperados: rev_print.c
Funções permitidas: write
--------------------------------------------------------------------------------

Escreva uma função que receba uma string e exiba a string ao contrário
seguida por uma nova linha.

A string original não deve ser modificada.

Você deve retornar a string passada como parâmetro.

Sua função deve ser declarada da seguinte forma:

char *rev_print(char *str);

Exemplos:

int main(void)
{
rev_print("Olá mundo");
write (1, "\n", 1);
rev_print("tnirp esreveR");
write (1, "\n", 1);
rev_print("");
write (1, "\n", 1);
}

Saída:
$> ./a.out | cat -e
dlrow olleH$
$> ./a.out | cat -e
Impressão reversa$
$> ./a.out | cat -e
$

````