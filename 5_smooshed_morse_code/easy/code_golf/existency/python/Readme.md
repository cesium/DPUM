# Algoritmos & Complexidade + Boredom present you morse code in just 121 characters

A ideia aqui é simples. Vamos representar [a..z][0..9] dentro de uma [tree]( https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Morse_code_tree3.png/770px-Morse_code_tree3.png), "estendida" em um array.

[(powered by morse code wikipedia)](https://en.wikipedia.org/wiki/Morse_code)

Regras de criação do array para a árvore
    - ([A-Z0-9])
    - Todos os outros valores/saltos serão substituidos por um espaço, ' '.
    - valores vão ser colocados da esquerda para direita, segundo imagem. Link da tree em cima.
Array: ' etianmsurwdkgohvf l pjbxcyzq  54 3   2       16       7   8 90'

Compromissos a tomar para compactar ao máximo possível:
    - lowercase only. SORRY.
    - Não há verificação de nenhum tipo de erro o que inclui mas não está limitado a caracteres inválidos e input nulo.
    - Aceitar apenas uma palavra de cada vez. Aceitar múltiplas palavras iria pôr o código à volta de 130,135 chars.


Por fim utilizar o atributo __file__ para poupar chars.
Isto permite-me poupar (178-121) 57 chars.


Usage:
	python ' etianmsurwdkgohvf l pjbxcyzq  54 3   2       16       7   8 90' TypeYourWordHere
