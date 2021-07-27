#include "func.h"

#define _byteSize 8;


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

// mensagens de debug (visualizar bits binarios em campos de bytes)
void debugMsg(list<char> msg){
    int count = 0;

    cout << "\n";
    
    for (auto it = msg.begin(); it != msg.end(); it++){
        count++;
        cout << *it;

        if(count % 8 == 0){
            cout << ' ';
        }
    }

    cout << "\n";

    return;
}

// binario para string
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

// conta numero de 1s na lista binaria
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

// divisao entre bits msg/G
list<char> division(list<char> msg, list<char> G){
    list<char> divide(msg);
    list<char> R;
    int intG = binToInt(G);
    int res = 0;

    // incrementar bits anteriores
    for(int i = 0; i < G.size()-1; i++){
        divide.push_back('0');
    }
    
    // pegar o minimo de bits (4)
    for(int i = 0; i < G.size(); i++){
        R.push_back(divide.front());
        divide.pop_front();
    }

    // se os 4 primeiros bits dividem...
    while(divide.size()+1 > 0){
        if(binToInt(R) > intG){
            // obter o resto da divisao inicial
            res = binToInt(R) % intG;
            R = intToBin(res);

            // puxar proximo bit
            R.push_back((char)divide.front());
            divide.pop_front();

        // se não...
        } else {
            // Puxa mais um bit, se possivel
            R.push_back((char)divide.front());
            divide.pop_front();
        }
    }

    // caso o resto não ocupe bits necessarios (obs: hardcoded. nao sei como incrementar de um jeito mais modular)
    if(R.size() < 4){
        R.push_front('0');
        if(R.size() < 4){
            R.push_front('0');
        }
    }
    R.pop_back();

    return R;
}

// binario para inteiro
int binToInt(list<char> bin){
    long value = 0, count = 0;

    for (auto it = bin.begin(); it != bin.end(); it++){
        value += ((int)(*it) - '0') * pow(2, bin.size() - count - 1);
        count++;
    }

    return value;
}

// inteiro para binario
list<char> intToBin(int i){
    list<char> ret;

    while(i > 0){
        (i % 2)?  ret.push_front('1') :
                  ret.push_front('0');
        i /= 2; 
    }

    return ret;
}

// comparar duas listas binarias
int compareLists(list<char> a, list<char> b, list<char> G){

    for(int i = 0; i < G.size() - 1; i++){
        if(a.front() != b.front()){
            return 0;
        }
        a.pop_front();
        b.pop_front();
    }

    return 1;
}

// coletar o resto da mensagem
list<char> remainderCollector(list<char> *msg, list<char> G){
    list<char> ret;

    for(int i = 0; i < G.size() - 1; i++){
        ret.push_front(msg->back());
        msg->pop_back();
    }

    return ret;
}