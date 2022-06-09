#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;

//PlusDecimal.exe 10 21
//31
//PlusDecimal.exe 100348 9999999947774

string plusDecimal(string a, string b){
    int maxLength = (a.length() > b.length()) ? a.length() : b.length();
    int difLength = abs((int)a.length() - (int)b.length());
    string c;
    string buff;

    for(int i=0; i <= difLength; i++){
        buff += "0";
    }

    for(int i=0; i<=maxLength; i++){
        c += "0";
    }

    if(a.length() != maxLength){
        a = buff + a;
        b = "0" + b;
    } else {
        a = "0" + a;
        b = buff + b;
    }

    for(int i=0; i<=maxLength; i++){
        int f = a[i]-48;
        int s = b[i]-48;
        int num = f+s;

        if(num>9){
            int j = i;
            c[j] = num + 48 - 10;
            while(j>0){
                if((c[j-1])==57){
                    c[j-1] = '0';
                    j--;
                } else {
                    c[j-1]+=1;
                    break;
                }
            }
        } else {
            c[i] = num+48;
        }
    }

    if(c[0]=='0'){
        c.erase(0,1);
    }

    return c;
}

int main(int argc,char** argv) {

    if(argc == 3){
        string a = argv[1];
        string b = argv[2];

        string result = plusDecimal(a, b);
        cout << result;

    } else {
        cout << "Invalid number of arguments";
    }

}
