#include "romanos.hpp"
#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <algorithm>
using namespace std;
int roman_inteiro(string s) {
    //Map para transformar chars para ints
    unordered_map<char, int> romanos = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    //Começa a variavel acumuladora
    int result = 0;
    //Usa um for para percorrer a string e usar a int certa
    for (int i = 0; i < (int)s.length(); i++) {
        //o if é usado para ver se o numero deve ser adcionado ou subtraido
        if (i == (int)s.length() - 1 || romanos[s[i]] >= romanos[s[i+1]]) {
            result += romanos[s[i]];
        } else {
            result -= romanos[s[i]];
        }
    }

    return result;
}
bool Valid(string str,int num) {
    // Descobre se existe uma letra invalida
    string validnum = "IVXLCDM";
    // Check if all chars sao validos
    for (char c : str) {
        if (validnum.find(c) == string::npos) {
            return false;
        }
    }
    string roman = "";
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    //construçao da string de numeros romanos
    //funciona da forma de retirar os valores do numero recebido e adicionar os simbolos ou o cinjunto de simbolos
    for(int i = 0; i < 13; i++) {
        while(num >= values[i]) {
            num -= values[i];
            roman += symbols[i];
        }
    }
    //checa se a conversão é igual
    if (roman==str){
        return true;
    }else{
        return false;
    }
}
int romanos_para_decimal(char const * roman)
{
    //Manda testar se e valido
    int numero = roman_inteiro(roman);
    bool f1=Valid(roman,numero);
    if (f1==true){ 
        if (numero <=3000){
            return numero ;
        }else{
            return -1;
        }
    }else{
        //Caso de não ser valido ou ser maior que 3000
        return-1;
    }
  return 0; 
}