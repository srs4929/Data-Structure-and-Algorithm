//Output trace

#include <iostream>
using namespace std;
void pr(int n)
{
    if (n < 1)
        return;
    pr(n / 2);
    cout << n<<" ";
}
int main()
{
    pr(17);
    return 0;
}

// Output : 1 2 4 8 17

// ouput trace of the code
#include <iostream>
using namespace std;
void pr(int n)
{
    if(n>0)
    {
        pr(n-1);
        cout<<n<<endl;
        pr(n-1);
    }
}
int main()
{
    pr(4);
    return 0;
}
// 1 2 1 3 1 2 1 4 1 2 1 3 1 2 1