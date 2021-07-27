#ifndef headers
#define headers
    #include <string>
    #include <list>
    using namespace std;

    void AplicacaoReceptora (string mensagem);
    void CamadaDeAplicacaoReceptora (int quadro);
    void MeioDeComunicacao (list<char> fluxo);
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


#endif