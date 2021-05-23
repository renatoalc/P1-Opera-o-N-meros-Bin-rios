#include <iostream>
#include <math.h>
using namespace std;

int main() {
  int NB1[8]; //NUMERO BINÁRIO 1
  int NB2[8]; 
  int ND1 = 0; //NUMERO DECIMAL 1
  int ND2 = 0;
  int RESD = 0; //RESULTADO EM DECIMAL
  int RESB[8]; //RESULTADO EM BINÁRIO
  char OP;
  int k=0;
  int aux=0;

  cout<<"Qual a operação desejada? (+,-,/,*,%)"<<endl;
  cin>>OP;

  cout<<"Pimeiro número binário de 8 bits iniciando pelo MSB?"<<endl;
  while (k<8){ // preecnhe o primeiro vetor de número binário
    cin>>NB1[k];
    k=k+1;
  }
  k=0;

  while (k<8){ // converte o primeiro número binário para decimal
    aux = pow(2,7-k);
    ND1 = NB1[k] * aux + ND1;
    k=k+1;
  }
  aux=0;
  k=0;

  cout<<"Segundo número binário de 8 bits iniciando pelo MSB?"<<endl;
  while (k<8){ // preecnhe o segundo vetor de número binário
    cin>>NB2[k];
    k=k+1;
  }
  k=0;

  while (k<8){ // converte o segundo número binário para decimal
    aux = pow(2,7-k);
    ND2 = NB2[k] * aux + ND2;
    k=k+1;
  }
  aux=0;
  k=0;

  //INICIA AS OPERAÇÕES, PRIMEIRO CALCULA EM DECIMAL E DEPOIS CONVERTE PARA BINÁRIO 

  if (OP == '+') { //Operação de soma
    RESD = ND1 + ND2;
    if (RESD < 256){ //Verifica se o resultado tem até 8 bits
      while (k<8){ //Converte o resultado para binário
        RESB[k] = RESD % 2;
        RESD = RESD/2;
        k = k + 1;
      }
      k=0;
      cout << "Resultado: ";
      while (k<8){ //Imprime o vetor contendo o resultado em binário
        cout << RESB[7-k];
        k=k+1;
      }
    }
    else{
      cout << "Inválido, reultado da soma é maior que 8 bts"<<endl;
    } 
  }

  if (OP == '-') { //Operação de subtração
    if (ND1 > ND2) {
      RESD = ND1 - ND2;
      while (k<8){ //Converte o resultado para binário
        RESB[k] = RESD % 2;
        RESD = RESD/2;
        k = k + 1;
      }
      k=0;
      cout << "Resultado: ";
      while (k<8){ //Imprime o vetor contendo o resultado em binário
        cout << RESB[7-k];
        k=k+1;
      }
    }
    else{ //Operação de subtração com resultado negativo
      RESD = (ND1 - ND2)*-1;
      while (k<8){ //Converte o resultado para binário
        RESB[k] = RESD % 2;
        RESD = RESD/2;
        k = k + 1;
      }
      k=0;
      cout << "Resultado: ";
      cout << "-";
      while (k<8){ //Imprime o vetor contendo o resultado em binário
        cout << RESB[7-k];
        k=k+1;
      }
    } 

  }
  
  if (OP == '*') { //Operação de multiplicação
    RESD = ND1 * ND2;
    if (RESD < 256){ //Verifica se o resultado é maior que 8 bits
      while (k<8){ //Converte o resultado para binário
        RESB[k] = RESD % 2;
        RESD = RESD/2;
        k = k + 1;
      }
      k=0;
      cout << "Resultado: ";
      while (k<8){ //Imprime o vetor contendo o resultado em binário
        cout << RESB[7-k];
        k=k+1;
      }
    }
    else{
      cout << "Inválido, reultado da multiplicação maior que 8 bts"<<endl;
    }
  }

  if (OP == '/') { //Operação que retorna a parte inteira da divisão
    RESD = ND1 / ND2;
    while (k<8){
      RESB[k] = RESD % 2;
      RESD = RESD/2;
      k = k + 1;
    }
    k=0;
    cout << "Resultado: ";
    while (k<8){
      cout << RESB[7-k];
      k=k+1;
    }
  }     
  
  if (OP == '%') { //Operação que retorna o resto da divisão
    RESD = ND1 % ND2;
    while (k<8){
      RESB[k] = RESD % 2;
      RESD = RESD/2;
      k = k + 1;
    }
    k=0;
    cout << "Resultado: ";
    while (k<8){
      cout << RESB[7-k];
      k=k+1;
    }
  }

}