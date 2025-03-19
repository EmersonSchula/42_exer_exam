## Subject

```
Nome da tarefa: repeat_alpha
Arquivos esperados: repeat_alpha.c
Funções permitidas: write
--------------------------------------------------------------------------------

Escreva um programa chamado repeat_alpha que pegue uma string e a exiba
repetindo cada caractere alfabético tantas vezes quanto seu índice alfabético,
seguido por uma nova linha.

'a' se torna 'a', 'b' se torna 'bb', 'e' se torna 'eeeee', etc...

A caixa permanece inalterada.

Se o número de argumentos não for 1, apenas exiba uma nova linha.

Exemplos:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | gato -e
abbacccaddddabba 42!$
$>./repeat_alpha | gato -e
$
$>
$>./repeat_alpha "" | gato -e
$
$>
```