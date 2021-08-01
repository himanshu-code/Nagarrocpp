#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
    string s;
    s = "Welcome To Coding Blocks we are learning strings.";
    char a[100005];
    strcpy(a, s.c_str());
    cout << a << endl;
    char *ptr = strtok(a, " .$");
    while (ptr != NULL)
    {
        cout << ptr << endl;
        ptr = strtok(NULL, " .$");
    }
    return 0;
}