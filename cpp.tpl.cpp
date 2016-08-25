#include <iostream>
#include <string>
#include <vector>

using namespace std;
void printVectorInt(vector<int> & vs);



int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}


void printVectorInt(vector<int> & vs){
    for (int i = 0; i < vs.size(); ++i)
    {
        cout<< vs[i] << " ";
    }
    cout<< endl;
}