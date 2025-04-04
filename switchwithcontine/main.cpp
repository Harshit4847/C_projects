#include <iostream>

using namespace std;

int main()
{

    int a = 3;

    for(int i = 0; i < 5 ; i++){
        switch(a){

            case 1: cout<<"1"<< endl;
                break;

            case 2: cout<<"2"<< endl;
                break;

            case 3: cout<<"3"<< endl;
                continue;
            case 4: cout<<"4"<< endl;
                break;
            case 5: cout<<"5"<< endl;
                break;
        }
    }
}
