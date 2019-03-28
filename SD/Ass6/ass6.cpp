#include <iostream>
using namespace std;

class heap
{
  private:
    int *n;
    int size;

  public:
    heap(int s);
    void accept();
    void heapify(int *n, int pos, int s);
    void display();
    void build_heap();
    void sortheap();
};
heap::heap(int s)
{
    n = new int[s];
    size = s;
}
void heap::accept()
{
    cout << "Enter the array as follows\n";
    for (int i = 0; i < size; i++)
    {
        cin >> n[i];
    }
}
void heap::heapify(int *n, int pos, int len)
{
    int large, l, r;
    large = pos;
    l = 2 * pos + 1;
    r = 2 * pos + 2;
    if (l < len && n[l] > n[large])
        large = l;
    if (r < len && n[r] > n[large])
        large = r;
    if (large != pos)
    {
        int temp;
        temp = n[large];
        n[large] = n[pos];
        n[pos] = temp;
        heapify(n, large, len);
    }
}
void heap::build_heap()
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(n, i, size);
    }
}
void heap::sortheap()
{
    build_heap();
    int tempsize = size;
    for (int i = size - 1; i >= 1; i--)
    {
        int temp;
        temp = n[0];
        n[0] = n[i];
        n[i] = temp;
        tempsize -= 1;
        heapify(n, 0, tempsize);
    }
}
void heap::display()
{
    for (int i = 0; i < size; i++)
        cout << n[i] << " ";
    cout << endl;
}
int main()
{
    cout << "Enter the size of the array\n";
    int s;
    cin >> s;
    int ch;
    heap obj(s);
    do
    {
        cout << "Enter 1 to Enter the array\n";
        cout << "Enter 2 to heapify the array\n";
        cout << "Enter 3 to Sort the array\n";
        cout << "Enter 4 to Display the array\n";
        cout << "Enter 5 to Exit the array\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            obj.accept();
            break;
        case 2:
            obj.build_heap();
            break;
        case 3:
            obj.sortheap();
            break;
        case 4:
            obj.display();
            break;
        case 5:
            cout << "Exit\n";
            break;
        default:
            break;
        }
    } while (ch != 5);
    return 0;
}
