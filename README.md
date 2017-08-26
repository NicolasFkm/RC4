# RC4
RC4 é um algoritmo de criptografia que não utiliza calculos complexos, funciona basicamente por meio de permutações.

## Functions
O algoritmo utiliza basicamente dois algoritmos: o algoritmo KSA ou *Key-Scheduling Algorithm* que inicializa um array de estado preenchendo-o com valores de 0 a 255, depois são feitas diversas permutações, dentro de um laço de 0 a 255, baseando-se em valores do array no qual a chave está contida; e o algoritmo PRGA ou **Pseudo-Random Generation Algorithm** que inicializa variáveis com 0, depois inicializa o loop de 0 ate o tamanho do array da chave,são feitas trocas dentro do array de estado, e no passo final do laço realiza-se um XOR entre o array de estado e o array do texto enviado.


