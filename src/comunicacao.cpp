#include "func.h"

//funcao que simula a camada de comunicao de um fluxo de bits
//permite a escolha de uma simulacao de erro/corrompcao dos bits
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
    cout << "\n>> Bits antes da transmissao: ";
    debugMsg(fluxoBrutoDeBitsPontoA);
    cout << "\n>> Bits depois da transmissao: ";
    debugMsg(fluxoBrutoDeBitsPontoB);
    cout << endl;
    //CamadaDeAplicacaoReceptora(fluxoBrutoDeBitsPontoB);
    CamadaEnlaceDadosReceptora(fluxoBrutoDeBitsPontoB, tipoVerificacao);
    return;
}
// Fim do metodo MeioDeComunicacao.