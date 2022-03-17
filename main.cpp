#include <iostream>
#include <string>
#include <vector>

using namespace std;

int encrypt(char letter,int key[]){
    letter=tolower(letter);
    if (letter==' ')
        return 0;
    if (letter >='j')
        letter--;
    int num=letter-97;
    int column= (num%5) ;
    int row = (num/5) ;
    int sum=10*key[row] +key[column];
    return sum;

}


char decrypt(int key[],char alpha[5][5],int row, int column){
    for(int i=0;i<5;i++){
        if (key[i]==row){
            row =i;
            break;
        }
    }
    for(int i=0;i<5;i++){
        if (key[i]==column){
            column =i;
            break;
        }
    }

    return alpha[row][column];



}



void encryption_func(int key[],int arr[]){
    cin.clear();
    cin.sync();
    string c;
    getline(cin,c);
    for (int z=0;z<c.length();z++){
        arr[z] = encrypt(c[z],key);

    }
    cout<<"the encryption is : ";
    for (int i=0;i<c.length();i++){
        if (arr[i]==0){
            cout<<" ";
            continue;
        }
        cout<<arr[i];
    }
    cout<<"\n";

}


void decryption_func(int key[],char alpha[5][5],vector<char>sentence){
    int row,column;
    char x ;
    string numbers;
    cin.clear();
    cin.sync();
    getline(cin,numbers);

    for (int i=0;i<numbers.length();i+=2){
        if (numbers[i]==' '){
            sentence.push_back(' ');
            i--;
            continue;
        }
        else if (numbers[i]=='j')
            numbers[i]=='i';

        else if ((int)numbers[i]>106){
            numbers[i]--;
        }

        row=numbers[i]-'0';
        column =numbers[i+1]-'0';
        char x=decrypt(key,alpha,row,column);
        sentence.push_back(x) ;
    }
    cout<<"the real message was: ";
    for(int i=0;i<sentence.size();i++)
        cout<<sentence.at(i);
    cout<<"\n";
}


int main()
{
    while(1){
    int operation;
    vector<char> sentence;
    int row=1,column=1;
    cout<<"if you want to encrypt enter 1 , to decrypt enter 2  and any other number to exit \n";
    cin>>operation;
    char alpha[5][5];
    char letter='a';
    for (int i =0;i<5;i++){
        for (int j=0;j<5;j++){
           if(letter=='j')
                letter++;

           alpha[i][j]=letter++;
        }
    }
    cout<<"enter the key (5 integers) \n";
    int key [5];
    for (int i=0;i<5;i++)
        cin>>key[i];

    int arr[500];
    if(operation==1){
        cout<<"enter string to encrypt : ";
        encryption_func(key, arr);
    }
    else if (operation==2){
        cout<<"enter the code : ";
        decryption_func(key,alpha,sentence);
    }
    else
        break;
    }
    return 0;
}
