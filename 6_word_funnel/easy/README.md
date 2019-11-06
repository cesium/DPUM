# Funil de Palavras
![](https://img.shields.io/badge/-EASY-easy.svg?style=for-the-badge)

Dadas duas strings, determine se a segunda pode ser feita a partir da primeira removendo uma letra. As letras restantes devem permanecer na mesma ordem. A lista de palavras válidas pode ser consultada [aqui](https://raw.githubusercontent.com/dolph/dictionary/master/enable1.txt)

# Formato Input
Por exemplo:
`reset`
`rest`

# Formato Output
True ou False

Exemplos:

```
funnel("leave", "eave") => true
funnel("reset", "rest") => true
funnel("dragoon", "dragon") => true
funnel("eave", "leave") => false
funnel("sleet", "lets") => false
funnel("skiff", "ski") => false
```

