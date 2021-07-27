#include "func.h"

//verifica se os bits chegaram certos de acordo com o tipo de verificacao
//se deu certo, retira os bits de verificacao e manda para a proxima camada
//caso contrario imprime mensagem de erro, em uma aplicação real requisitaria o pacote novamente
void CamadaEnlaceDadosReceptora(list<char> quadro, int tipoVerificacao) {

    //tipo 0: par
    if(tipoVerificacao == 0){
        if(countOnes(quadro)%2 == 0) {
            quadro.pop_back();
            CamadaDeAplicacaoReceptora(quadro);
        }
        else{
            cout << "A verificacao do pacote falhou.\n";
        }
    
    //tipo 1: impar
    } else if (tipoVerificacao == 1){
        
        if(countOnes(quadro)%2 == 1) {
            quadro.pop_back();
            CamadaDeAplicacaoReceptora(quadro);
        }else {
            cout << "A verificacao do pacote falhou.\n";
        }
        
    //tipo 2: crc32
    } else if (tipoVerificacao == 2){
        list<char> G {'1','0','0','1'};
        list<char> T = remainderCollector(&quadro, G);
        list<char> R = division(quadro, G);

        if(compareLists(R, T, G)){
            CamadaDeAplicacaoReceptora(quadro);
        } else {
            cout << "A verificacao do pacote falhou.\n";
        }
    }
    
    return;
}

void CamadaDeAplicacaoReceptora(list<char> quadro) {
    string mensagem = binToStr(quadro);
    AplicacaoReceptora(mensagem);
    return;
}

void AplicacaoReceptora(string mensagem) {
    cout << "A mensagem recebida foi: " << mensagem << endl;
    return;
}   
