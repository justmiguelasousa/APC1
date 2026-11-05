/*
a) Um int normalmente ocupa 4 bytes (32 bits).
   Faixa aproximada: de -2.147.483.648 até +2.147.483.647.

b) Um char ocupa 1 byte (8 bits).
   Faixa aproximada: de -128 até +127 (signed) ou de 0 até 255 (unsigned).

c) Usar unsigned int em vez de int é útil quando sabemos que o número nunca será negativo.
   Isso elimina o bit de sinal e dobra a faixa positiva:
   - int: até quase 2 bilhões
   - unsigned int: até quase 4 bilhões
   Exemplo: contadores, índices de arrays, tamanhos de estruturas.
*/
