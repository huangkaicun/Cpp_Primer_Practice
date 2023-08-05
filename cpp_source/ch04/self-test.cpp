#include <iostream>

using namespace std;


int num_calculate(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("b cannot be 0!");
    }
    else
    {
        return a / b;
    }
    



}
int main(int argc, char const *argv[])
{
    try
    {
        int ros = num_calculate(10, 0);
        cout << ros << endl;
    }
    catch(const std::exception& e)
    {
            
    }
    
}
