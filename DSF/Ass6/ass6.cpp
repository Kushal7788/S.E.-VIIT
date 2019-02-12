#include <iostream>
#include <stack>

using namespace std;

class node
{
    friend class adjlist;
    int data;
    node *next;
};

class adjlist
{
  private:
    int vertices;
    node **start;

  public:
    adjlist();
    adjlist(int e);
    void addedge();
    void display();
};

adjlist::adjlist(int e)
{
    vertices = e;
    start = new node *[e];
    for (int i = 0; i < e; i++)
    {
        start[i] = new node;
        start[i] = NULL;
    }
}
void adjlist::addedge()
{
    int start_vertex, end_vertex;
    cout << "Enter the starting vertex \n";
    cin >> start_vertex;
    cout << "Enter the ending vertex\n";
    cin >> end_vertex;
    node *temp;
    temp = new node;
    temp->data = end_vertex;
    temp->next = NULL;
    if (start[start_vertex] == NULL)
    {
        node *nn = new node;
        nn->data = start_vertex;
        nn->next = NULL;
        start[start_vertex] = nn;
        start[start_vertex]->next = temp;
    }
    else
    {
        node *t;
        t = start[start_vertex];
        while (t->next != NULL)
            t = t->next;
        t->next = temp;
    }
}
void adjlist::display()
{
    for (int i = 0; i < vertices; i++)
    {
        node *temp;
        temp = start[i];
        if (temp == NULL)
            cout << "No Data Yet\n";
        else
        {
            while (temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
}

int main()
{
    int ver;
    int ch;
    cout << "Enter the number of vertices\n";
    cin >> ver;
    adjlist graph(ver);
    do
    {
        cout << "Enter 1 to insert the edges of graph\n";
        cout << "Enter 2 to display the edges of the graph\n";
        cout << "Enter 5 to exit\n";
        cin >> ch;
        switch (ch)
        {
        case 1:
            graph.addedge();
            break;
        case 2:
            graph.display();
            break;
        case 5:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid Input\n";
            break;
        }
    } while (ch != 5);
    return 0;
}
