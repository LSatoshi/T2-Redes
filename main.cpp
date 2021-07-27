/*  Grupo:
 *  
 *  Gustavo Akira Hirakawa      - 11381768
 *  Leandro Satoshi de Siqueira - 10893103
 *  Luana Terra do Couto        - 11218917
 *  Paolo Paolo Paolo           - 00000000
 *  Yago Poletto Salgado        - 10724455
*/

// Bibliotacas usadas.

#include <iostream>
#include <string>
#include <bitset>
#include "main.h"

#define _PacketSize 128

using namespace std;



void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi: " << mensagem << endl;
    return;
}   


void CamadaDeAplicacaoReceptora(list<char> quadro) {
    string mensagem = binToStr(quadro);
    AplicacaoReceptora(mensagem);
    return;
}


void CamadaEnlaceDadosReceptora(list<char> quadro, int tipoVerificacao) {
    //verifica se os bits chegaram certos de acordo com o tipo de verificacao
    //se deu bom tira os bits de verificacao e manda pra frente
    //se nao da erro
}

void MeioDeComunicacao (list<char> fluxoBrutoDeBits, int tipoVerificacao) {
    int erro, porcentagemDeErros;
    list<char> fluxoBrutoDeBitsPontoA, fluxoBrutoDeBitsPontoB;

    porcentagemDeErros = 0;
    cout << "Insira a porcentagem de erro (inteiro entre 0 e 100)\n";
    cin >> porcentagemDeErros;

    fluxoBrutoDeBitsPontoA = fluxoBrutoDeBits;
    
    for (auto it = fluxoBrutoDeBitsPontoA.begin(); it != fluxoBrutoDeBitsPontoA.end(); it++) {
        if((rand()%100) >= porcentagemDeErros) {
            fluxoBrutoDeBitsPontoB.push_back(*it);
        }else {
            if((*it) == '0')
                fluxoBrutoDeBitsPontoB.push_back('1');
            else
                fluxoBrutoDeBitsPontoB.push_back('0');
        }
    }
    cout << "\n Bits antes da transmissao: \n";
    debugMsg(fluxoBrutoDeBitsPontoA);
    cout << "\n Bits depois da transmissao: \n";
    debugMsg(fluxoBrutoDeBitsPontoB);
    cout << endl;
    CamadaDeAplicacaoReceptora(fluxoBrutoDeBitsPontoB);
    //CamadaEnlaceDadosReceptora(fluxoBrutoDeBitsPontoB, tipoVerificacao);
    return;
}
// Fim do metodo MeioDeComunicacao.

list<char> CamadaEnlaceDadosTransmissoraControleDeErro (list<char> quadro, int tipoVerificacao) {
    int tipoDeControleDeErro = tipoVerificacao;
    switch (tipoDeControleDeErro) {
        case 0: // Verificacao por bit de paridade par.
            quadro = CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro);
            break;
        case 1: // Verificacao por bit de paridade impar.
            quadro = CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(quadro);
            break;
        case 2: // Verificacao por CRC.
            quadro = CamadaEnlaceDadosTransmissoraControleDeErroCRC(quadro);
            break;
    }// Fim do switch case
    return(quadro);
}
// Fim do metodo CamadaEnlaceDadosTransmissoraControleDeErro.

list<char> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar (list<char> quadro) {
    bool par = true;
    for (auto it = quadro.begin(); it != quadro.end(); it++) {
        if((*it) == 1) par = !par;
    }
    if(par)quadro.push_back('0');
    else quadro.push_back('1');
    return(quadro);
}

list<char> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar (list<char> quadro) {
    bool impar = false;
    for (auto it = quadro.begin(); it != quadro.end(); it++) {
        if((*it) == 1) impar = !impar;
    }
    if(impar)quadro.push_back('0');
    else quadro.push_back('1');
    return(quadro);
}

list<char> CamadaEnlaceDadosTransmissoraControleDeErroCRC (list<char> quadro) {
    //implementacao do alg
    //usar polinomio CRC-32(IEEE 802)
    return(quadro);
}

// Responsavel por chamar a funcao que ajusta os bits da mensagem (controle de erro) e prosseguir para a proxima camada.
// Recebe o quadro de bits da mensagem e a opcao de verificacao escolhida pelo usuario.
void CamadaEnlaceDadosTransmissora(list<char> quadro, int tipoVerificacao) {
    // Chamando a funcao de controle de erro.
    quadro = CamadaEnlaceDadosTransmissoraControleDeErro(quadro, tipoVerificacao);

    // Chamando a proxima camada.
    MeioDeComunicacao(quadro, tipoVerificacao);
    return;
}
// Fim do metodo CamadaEnlaceDadosTransmissora.

// Realiza a conversao de uma string em um vetor de bits (quadro de bits).
// Recebe a string com a mensagem e a opcao de verificacao escolhida pelo usuario.
void CamadaDeAplicacaoTransmissora(string mensagem, int tipoVerificacao) {

    // Realiza a conversao.
    list<char> quadro = strToBin(mensagem);

    // Chamando a proxima camada.
    CamadaEnlaceDadosTransmissora(quadro, tipoVerificacao);
    return;
}

// Fim do metodo CamadaDeAplicacaoTransmissora.

// Realiza interacao com o usuario. Permite a escolha de uma opcao de verificacao.
void AplicacaoTransmissora() {
    string mensagem;
    int tipoVerificacao;
    
    // Comunicacao com o usuario.
    cout << "Digite uma mensagem:\n" << endl;
    std::getline(std::cin, mensagem);

    // O usuario pode escolher o tipo de verificacao desejada.
    cout << "Selecione uma das opcoes abaixo de verificacao:\n\nVerificacao por paridade par - Digite 0.\nVerificacao por paridade impar - Digite 1.\nVerificacao por CRC - Digite 2.\n";
    cin >> tipoVerificacao;
    
    // Chamamando a proxima camada.
    CamadaDeAplicacaoTransmissora(mensagem, tipoVerificacao);
    
    return;
}
// Fim do metodo AplicacaoTransmissora.


int main(void) {
    AplicacaoTransmissora();
    return 0;
}
// Fim do metodo main.
