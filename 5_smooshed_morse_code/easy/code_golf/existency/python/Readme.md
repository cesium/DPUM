# Algoritmos & Complexidade + Boredom present you morse code in just 127 characters

A ideia aqui é simples. Vamos representar [a..z] dentro de uma [tree]( https://upload.wikimedia.org/wikipedia/commons/thumb/c/ca/Morse_code_tree3.png/770px-Morse_code_tree3.png), "estendida" em um array.

[(powered by morse code wikipedia)](https://en.wikipedia.org/wiki/Morse_code)

Regras de criação do array para a árvore
    - ([A-Z])
    - Todos os outros valores/saltos serão substituidos por um espaço, ' '.
    - valores vão ser colocados da esquerda para direita, segundo imagem. Link da tree em cima.
Array: ' etianmsurwdkgohvf l pjbxcyzq'

Decidi fazer 2 versões de python, deverão contar como entradas separadas. Com o tempo posso tentar compactar mais o código.

Usage:
	python easymorse3.py
	python2.7 easymorse2_7.py
