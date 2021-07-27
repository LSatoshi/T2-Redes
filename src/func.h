#ifndef H_FUNC
#define H_FUNC

    #include <string>
    #include <list>
    #include <iostream>
    #include <bitset>
    #include <math.h>

    using namespace std;

    void AplicacaoReceptora (string mensagem);
    void CamadaDeAplicacaoReceptora (list<char> quadro);
    void CamadaEnlaceDadosReceptora(list<char> quadro, int tipoVerificacao);
    void MeioDeComunicacao (list<char> fluxo, int tipoVerificacao);
    list<char> CamadaEnlaceDadosTransmissoraControleDeErro (list<char> quadro, int tipoVerificacao);
    list<char> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadePar (list<char> quadro);
    list<char> CamadaEnlaceDadosTransmissoraControleDeErroBitParidadeImpar(list<char> quadro);
    list<char> CamadaEnlaceDadosTransmissoraControleDeErroCRC (list<char> quadro);
    void CamadaEnlaceDadosTransmissora(list<char> quadro, int tipoVerificacao);
    void CamadaDeAplicacaoTransmissora(string mensagem, int tipoVerificacao);
    void AplicacaoTransmissora();
    void AplicacaoTransmissora();
    list<char> strToBin(string s);
    void debugMsg(list<char> msg);
    string binToStr(list<char> msg);
    int countOnes(list<char> msg);
    list<char> division(list<char> msg, list<char> G);
    int binToInt(list<char> bin);
    list<char> intToBin(int i);
    int compareLists(list<char> a, list<char> b, list<char> G);
    list<char> remainderCollector(list<char> *msg, list<char> G);


#endif