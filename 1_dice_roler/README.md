# Cria um lançador de dados
![](https://img.shields.io/badge/-EASY-brightgreen.svg?style=for-the-badge)

Imagina que queres jogar *Dungeons & Dragons* mas não tens dados de várias
dimensões. Resolve este problema criando um programa que possa lançar qualquer
tipo de dados.

## Formato do Input

O input contém uma ou mais linhas, onde cada linha têm sempre o formato `NdM`.
Por exemplo:

```
3d6
4d12
1d10
5d4
```

Se já jogaste alguma vez *D&D*, provavelmente reconheces o formato mas para os
restantes, isto é o que significa:

O primeiro número é a quantidade de dados a lançar, o d significa "dado", é
usado apenas para separar os dois números, e o segundo número é a quantidade de
lados que os dados têm. Usando como exemplo a primeira linha, `3d6` significa
lança 3 dados de 6 faces.

O primeiro número, o número de dados a lançar, é um inteiro entre 1 e 100,
inclusive.

O segundo número, o número de faces do dado, é um inteiro entre 2 e 100,
inclusive.

## Formato do Output

O teu programa deve imprimir no ecrã a soma dos lançamentos de um dado pedido.
Cada um destes na sua linha. Usando o exemplo `3d6`, o resultado devia ser algo
como:

```
14
```

Um simples número, foram lançados 3 dados com 6 faces cada, e a soma do
resultado deu 14.

## Notas/Pistas

O lançamento de um dado é basicamente o mesmo que escolher um número aleatório
entre 1 e 6 (ou 12, 20 ou quantas faces o dado tiver). Deves encontrar uma
maneira de escolher aleatoriamente um número nesse intervalo dado no input. O
teu programa deve gerar resultados o mais aleatórios possível. Se o correres e
para os mesmo dados der sempre o mesmo output isso não seria muito aleatório,
pois não? Tenta garantir que isso não acontece.

Não multipliques um lançamento pelo número de dados, por favor. Isso estaria
incorreto pois estarias a eliminar vários valores possíveis. Por exemplo, não é
possível obter o resultado `14` a partir do input `3d6` se apenas lançares um
dado uma vez e o multiplicares por 3. Todos os lançamentos devem ser
independentes.

## Bónus

Além de imprimires no ecrã o resultado da soma, podes imprimir o resultado de
todos os lançamentos para cada linha. Por exemplo, assim:

```
14: 6 3 5
22: 10 7 1 4
9: 9
11: 3 2 2 1 3
```

---

_Podes ler o enunciado original [aqui](https://redd.it/8s0cy1/)._

