#include <iostream>
#include <queue>

using namespace std;

class node
{
    friend class adjlist;
    int data;
    int wt;
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
    void mst();
    void prinstMST(int parent[]);
    int minval(int key[], bool visit[]);
};

adjlist::adjlist(int e)
{
    vertices = e;
    start = new node *[e];
    for (int i = 0; i < e; i++)
    {
        // start[i] = new node;
        start[i] = NULL;
    }
}
void adjlist::addedge()
{

    int start_vertex, end_vertex, wt;
    cout << "Enter the starting vertex \n";
    cin >> start_vertex;
    cout << "Enter the ending vertex\n";
    cin >> end_vertex;
    cout << "Enter the weight of the edge\n";
    cin >> wt;
    node *temp;
    temp = new node;
    temp->data = end_vertex;
    temp->next = NULL;
    temp->wt = wt;
    if (start[start_vertex] == NULL)
    {
        node *nn = new node;
        nn->data = start_vertex;
        nn->wt = 0;
        nn->next = NULL;
        start[start_vertex] = nn;
        start[start_vertex]->next = temp;
    }
    else
    {
        bool isvisited = false;
        node *t;
        t = start[start_vertex];
        while (t->next != NULL)
        {
            if (t->data == temp->data)
                isvisited = true;
            t = t->next;
        }
        if (!isvisited)
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
int adjlist::minval(int key[], bool visit[])
{
    int min = INT32_MAX;
    int minindex;
    for (int i = 0; i < vertices; i++)
    {
        if (visit[i] == false && key[i] < min)
        {
            min = key[i];
            minindex = i;
        }
    }
    return minindex;
}
void adjlist::prinstMST(int parent[])
{
    for (int i = 0; i < vertices; i++)
    {
        cout << i << " " << parent[i] << endl;
    }
}
void adjlist::mst()
{
    int key[vertices], parent[vertices];
    bool visit[vertices];

    for (int i = 0; i < vertices; i++)
    {
        key[i] = INT32_MAX;
        parent[i] = -1;
        visit[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    int u = minval(key, visit);
    visit[u] = true;
    if (start[u]->next != NULL)
    {
        node *temp;
        temp = start[u];
        temp = temp->next;
        while (temp != NULL)
        {
            if (visit[temp->data] == false && temp->wt < key[temp->data])
            {
                parent[temp->data] = u;
                key[temp->data] = temp->wt;
            }
            temp = temp->next;
        }
    }
    prinstMST(parent);
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
        cout << "Enter 3 to display the MST of the graph\n";
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
        case 3:
            graph.mst();
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
