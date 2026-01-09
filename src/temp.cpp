#include<iostream>
using namespace std;
int main()
{
    string input;
    int value;
    cout<<"Enter subject num: ";
    getline(std::cin,input);

    try
    {
        value = stoi(input);
    }
    catch(exception& e)
    {
        cout<<"Exception: "<<e.what()<<endl;
    }



    return 0;

}