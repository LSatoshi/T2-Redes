#include "func.h"

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


// Funcao de encaminhamento para a proxima camada. Escolhe o tipo de verificacao e chama a proxima camada.
// Recebe o quadro de bits da mensagem e a opcao de verificacao escolhida pelo usuario.
// Retorna o quadro de bits resultantes apos as verificacoes.
list<char> CamadaEnlaceDadosTransmissoraControleDeErro (list<char> quadro, int tipoVerificacao) {
    // Escolhe o tipo de verificacao de acordo com a opcao selecionada pelo usuario.
    switch (tipoVerificacao) {
        case 0: // Verificacao por bit de paridade par.
            quadro = CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar(quadro);
            break;
        case 1: // Verificacao por bit de paridade impar.
            quadro = CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(quadro);
            break;
        case 2: // Verificacao por CRC.
            quadro = CamadaEnlaceDadosTransmissoraControleDeErroCRC(quadro);
            break;
    } // Fim do switch case.

    // Retorna o quadro de bits resultante.
    return(quadro);
}
// Fim do metodo CamadaEnlaceDadosTransmissoraControleDeErro.



list<char> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar (list<char> quadro) {
    bool par = true;
    for (auto it = quadro.begin(); it != quadro.end(); it++) {
        if((*it) == '1') par = !par;
    }
    if(par)quadro.push_back('0');
    else quadro.push_back('1');
    return(quadro);
}

list<char> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar (list<char> quadro) {
    bool impar = false;
    for (auto it = quadro.begin(); it != quadro.end(); it++) {
        if((*it) == '1') impar = !impar;
    }
    if(impar)quadro.push_back('0');
    else quadro.push_back('1');
    return(quadro);
}

list<char> CamadaEnlaceDadosTransmissoraControleDeErroCRC (list<char> quadro) {
    //implementacao do alg
    list<char> G {'1','0','0','1'};
    list<char> R;

    //calcula o resto e concatena
    R = division(quadro, G);
    quadro.splice(quadro.end(), R);

    //usar polinomio CRC-32(IEEE 802)
    return(quadro);
}


