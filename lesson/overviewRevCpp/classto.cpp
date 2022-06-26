#include<bits/stdc++.h>
using namespace std;

class IntCell
{
    public:
        explicit IntCell(int initialValue=0)
            : storedValue{ initialValue } {}
        int read() const
        {
            return storedValue;
        }
        void write(int x)
        {
            storedValue=x;
        }
    private:
        int storedValue;
};

int main()
{
    IntCell *m;
    m = new IntCell{ 0 };
    m->write(5);
    cout << m->read();
    delete m;
}
