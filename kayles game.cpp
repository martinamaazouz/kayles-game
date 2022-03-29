#include <iostream>
#include <string>
#include <array>
#include <cstring>
using namespace std;

void printArr(string arr[], int n)
{
  for (int i=0; i<n; i++){
    if(i==n-1){
        cout<<arr[i];
    }
    else{
    cout<<arr[i]<<",";
  }
  }
}

bool alldashes(string arr[], int n){
    string temp="-";
    bool flag=true;
    for (int i=0; i<n;i++){
        if (arr[i]!=temp){
            flag = false;
            break;
        }
        else{
            flag= true;
        }
    }
    return flag;
}



bool foundInArray(string arr[],int n,string l){
    bool x = false;
    for (int i=0; i<n; i++){
        if (l!=arr[i])
        {
          x = false;
        }
        else{
          x= true;
          break;
        }

}
return x;
}
int main()
{
    string symbols[20] = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"};
    bool flag =true;
    int player = 1;
    int deletNum1;
    int deletNum2;
    cout<<"Rules:\nThis game is played by two players.\n Each one chooses a number or two, and the last player to choose is the winner.\n But if you choose two numbers, they must be consecutive numbers.";
    cout<<"the number of symbols is "<<endl;
    cout<<"[";
    printArr(symbols,20);
    cout<<"]"<<endl;

    while (!alldashes(symbols,20)){

        cout<<"player "<<player<<endl;

        while (flag){
            string answer;
            cout<<"do you want to select one or two numbers: ";
            cin>>answer;

            if (answer == "two"){
            cout<<"please enter the first number: ";
            cin>>deletNum1;
            cout<<"please enter the second number: ";
            cin>>deletNum2;

            string str1 = to_string(deletNum1);
            string str2 = to_string(deletNum2);
            if (deletNum1==deletNum2-1||deletNum2==deletNum1-1){

                if(foundInArray(symbols,20,str1)&&foundInArray(symbols,20,str2)){
                    symbols[deletNum1-1] = "-";
                    symbols[deletNum2-1] = "-";
                    printArr(symbols,20);
                    cout<<endl;
                    flag = false;
                    }else{
                        cout<<"number not found in the array"<<endl;
                            }

            }else{
                        cout<<"it must be adjacent numbers"<<endl;
                    }


                }else if (answer=="one"){
                    cout<<"please enter the number: ";
                    cin>>deletNum1;
                    string str1 = to_string(deletNum1);

                    if(foundInArray(symbols,20,str1)){
                        symbols[deletNum1-1] = "-";
                        printArr(symbols,20);
                        cout<<endl;
                        flag = false;
                    }else{
                        cout<<"number not found in the array"<<endl;
                    }}
                    }
            if (player==1){
            player=2;
            }else{
            player=1;
                }
                flag = true;




    }
    if (player==1){
        player =2;

    }
    else{
        player = 1;
    }
    cout<<"the player number "<< player<< " wins!!\n game is over ";

    return 0;
}

