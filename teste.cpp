#include <stdio.h>

#include <iostream>
#include <string>
#include <list>
#include <math.h>
#include <bitset>
#include "main.h"

#define _byteSize 8;

using namespace std;

/*void AplicacaoTransmissora();
list<char> strToBin(string s);
void debugMsg(list<char> msg);
string binToStr(list<char> msg);
int countOnes(list<char> msg);*/




/*int main(void) {
    AplicacaoTransmissora();
    return 0;
    //fim do metodo main
}*/

/* void AplicacaoTransmissora(){
    string mensagem;
    list<char> msg;

    cout << "Digite uma mensagem: " << endl;
    std::getline(std::cin, mensagem);
    //chama a proxima camada

    msg = strToBin(mensagem);

    debugMsg(msg);

    printf("%d", countOnes(msg));

    binToStr(msg);

    //cout << mensagem;
    //em um exemplo mais realista, aqui seria dado um SEND do SO
} */

// Transforma a mensagem em uma lista de bits. Garante que os caracteres tenham formato de byte.
list<char> strToBin(string s){
    int n = s.length();
    int val;
    list <char> msg;

    string bin;

    for(int i = n; i >= 0; i--) {
        val = int(s[i]);

        while(val > 0){
            (val % 2)?  msg.push_front('1') :
                        msg.push_front('0');
            val /= 2; 
        }

        while((msg.size() % 8) != 0) {
            msg.push_front('0');
        }
    }

    return msg;
}

void debugMsg(list<char> msg){
    int count = 0;
    
    for (auto it = msg.begin(); it != msg.end(); it++){
        count++;
        cout << *it;

        if(count % 8 == 0){
            cout << ' ';
        }
    }

    return;
}

string binToStr(list<char> msg){
    int count = 0, character = 0, first = 1;
    char c;
    string str = "";
    
    for (auto it = msg.begin(); it != msg.end(); it++){
        character += ((int)(*it) - '0') * pow(2, 7 - ((count) % 8));
        //printf("%d ", character);
        if((count % 8) == 0){
            if(first){
                first = 0;
            } else {
                str += character;
                character = 0;
            }
        }
        count++;
    }

    str += character;

    return(str);
}

int countOnes(list<char> msg) {
    int count = 0;
    
    for (auto it = msg.begin(); it != msg.end(); it++){

        if(*it == '1'){
            count++;
        }
    }

    printf("\ncontagem: %d\n", count);

    return count;
}