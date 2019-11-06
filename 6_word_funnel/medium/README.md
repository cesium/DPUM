# Funil de Palavras
![](https://img.shields.io/badge/-MEDIUM-yellow.svg?style=for-the-badge)

Um funil de palavras é uma série de palavras formada pela remoção de uma letra de cada vez de uma palavra inicial, mantendo as letras restantes em ordem. Para os fins deste desafio, uma palavra é definida como uma entrada na [lista](https://raw.githubusercontent.com/dolph/dictionary/master/enable1.txt) de palavras. Um exemplo de funil de palavras é:

```
gnash => gash => ash => ah
```

Dada uma palavra, determine o tamanho do funil de palavras mais longo que ele inicia.

## Formaro do Input

O input contém uma string 

## Formato do Output

O output deve imprimir no ecra o length do maior funil da palavra introduzida.

Exemplos
```
funnel("gnash") => 4
funnel("princesses") => 9
funnel("turntables") => 5
funnel("implosive") => 1
funnel("programmer") => 2
```
