#include <iostream>
using namespace std;

void PrintPasswordWithNumberinIt(string password,unsigned int index, int Num){
    for(unsigned int i=0;i<password.length()+1;i++){
        if(i==index){
            cout<<Num;
        }
        if(i<password.length()){
            cout<<password[i];
        }
    }
    return;
}

bool doesPasswordHaveASpecialCharacter(string password, int j){
    if(password[j]=='!'||password[j]=='@'||password[j]=='#'||password[j]=='$'||password[j]=='%'||password[j]=='^'||password[j]=='&'||password[j]=='*'||password[j]=='('||password[j]==')'){
        return true;
    }
return false;
}

bool validateIndex(unsigned int index,string num){
    if(index>num.size()||index<1){
        return false;
    }
    return true;
}

bool validateNum(string num){
    for(unsigned int i=0;i<num.size();i++){
        if(num[i]!='1'&&num[i]!='2'&&num[i]!='3'&&num[i]!='4'&&num[i]!='5'&&num[i]!='6'&&num[i]!='7'&&num[i]!='8'&&num[i]!='9'&&num[i]!='0'){
            return false;
        }
    }
        return true;
}

bool evaluatePassword(string password){
    for(unsigned int i=0;i<password.length();i++){
        if(isalpha(password[i])==false&&doesPasswordHaveASpecialCharacter(password,i)==false){
            return false;
        }
    }
    return true;
}

bool doesPasswordHaveACapital(string password){ //checks if password has a capital letter
    for(unsigned int j=0;j<password.length();j++){
        if(isupper(password[j])==true){
            return true;
        }
    }
    return false;
}

int main(){
    string retry="";
    string desiredIndexS="";
    string numS;
    int desiredIndex;
    int num=0;
    bool isPasswordStrongEnough=false;
    bool doesPasswordHaveANumber=false;
    string Password="";
    while(isPasswordStrongEnough==false){
        doesPasswordHaveANumber=false;
    cout<<"Welcome to the password analyzer!"<<endl;
    cout<<"This program is to allow you to evaluate your password's strength and I will"<<endl;
    cout<<"provide suggested recommendations to improve your password"<<endl;
    cout<<"Please enter a password you use below:"<<endl;
    cout<<"note please only enter letters or special characters"<<endl;
    cout<<"Another note, the following are considered special characters: !, @, #, $, %, ^, &, *, (, and )"<<endl;
    getline(cin,Password);
    while(evaluatePassword(Password)==false){
        cout<<"Please enter a password that only contains letters or special characters"<<endl;
        getline(cin,Password);
    }
    if(doesPasswordHaveACapital(Password)==false){
        cout<<"Your password seems to not have a capital letter, that can make your password very easy to guess"<<endl;
        continue;
    }
    if(Password.length()<8){
        cout<<"your password looks to be a bit too short, your password needs to be at least 8 characters but the more"<<endl;
        cout<<"characters there are, the harder it would be for someone to guess your password"<<endl;
        continue;
    }
    cout<<"congrats, your password seems to be pretty secure, it would help if a number could be added to the password so lets do that"<<endl;
    while(doesPasswordHaveANumber==false){
        cout<<"please enter a one digit number to add to your password"<<endl;
        getline(cin,numS);
        while(validateNum(numS)==false){
            cout<<"please enter a 1 digit number"<<endl;
            getline(cin,numS);
        }
        num=stoi(numS);
        cout<<"congrats, in what index would you like to insert the number "<<num<< " to?"<<endl;
        cout<<"for example entering one would insert the number between "<<Password[0]<<" and "<<Password[1]<<endl;
        cout<<"note: the last index is "<<Password.size()<<endl;
        cout<<"password so far:"<<Password<<endl;
        getline(cin,desiredIndexS);
        while(validateNum(desiredIndexS)==false){ //need to check if index is valid a valid number,then put it inside validate index function
            cout<<"you need to enter a number"<<endl;
            cout<<"please enter a valid number"<<endl;
            getline(cin,desiredIndexS);
        }
        desiredIndex=stoi(desiredIndexS);
        while(validateIndex(desiredIndex,Password)==false){
            continue;
        }
        doesPasswordHaveANumber=true;
    }
    cout<<"you putted "<<num<<" into index "<<desiredIndex<<"!"<<endl;
    cout<<"your new password is: ";
    PrintPasswordWithNumberinIt(Password,desiredIndex,num);
    cout<<endl;
    cout<<"remember to remember your password or store it somwhere so you don't forget"<<endl;
    cout<<"some more tips: try not to use the same password for everything so if someone gets access to one of your accounts"<<endl;
    cout<<"they can't get access to your other accounts"<<endl;
    cout<<"Do you want to try this password program analyzer again?"<<endl;
    cout<<"Please enter yes or no"<<endl;
    getline(cin,retry);
    while(retry!="no"&&retry!="yes"){
        cout<<"please enter yes or no"<<endl;
        getline(cin,retry);
    }
    if(retry=="no"){
        break;
    }
}
}
