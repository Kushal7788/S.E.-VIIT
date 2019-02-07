#include <iostream>

using namespace std;

class graphMatrix
{
  private:
    int **v;
    int size;

  public:
    graphMatrix(int m);
    void display();
    void accept();
};

graphMatrix::graphMatrix(int m)
{
    size = m;
    v = new int *[m];
    for (int i = 0; i < m; i++)
        v[i] = new int[m];
}
void graphMatrix::display()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << v[i][j];
        }
        cout << endl;
    }
}
void graphMatrix::accept()
{
    cout << "Enter the graph now\n";
    for (int i = 0; i < size; i++)
    {
        cout << "Enter all edges connected to " << i << endl;
        for (int j = 0; j < size; j++)
        {
            cout << "Enter 1 if there is an edge between " << i << " and " << j << endl;
            cin >> v[i][j];
        }
    }
}

int main()
{
    int size;
    cout << "Enter the No of Edges in the graph\n";
    cin >> size;
    graphMatrix ob(size);
    int ch;
    do
    {
        cout << "Enter 1 to accept the graph in matrix\n";
        cout << "Enter 2 to display the graph in matrix\n";
        cout << "Enter 5 to exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            ob.accept();
            break;
        case 2:
            ob.display();
            break;
        case 3:
            cout << "Exit\n";
            break;

        default:
            break;
        }
    } while (ch != 5);
    return 0;
}