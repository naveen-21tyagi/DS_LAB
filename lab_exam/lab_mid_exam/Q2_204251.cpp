//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;
struct node
{
    string name;
    int rollNo;
    node *next;
};
class LL
{
    int size = 0;

public:
    node *head = NULL;
    node *sorted = NULL;
    LL()
    {
        node *head = new node;
    }

    void insertFront(int x, string name)
    {
        node *nn = new node;
        nn->next = head;
        head = nn;
        nn->rollNo = x;
        nn->name = name;
        size++;
    }
    void insertionSort()
    {
        node *current = head;
        while (current != NULL)
        {
            node *next = current->next;
            sort(current);
            current = next;
        }
        head = sorted;
    }

    void sort(node *nn)
    {
        if (sorted == NULL || sorted->name >= nn->name)
        {
            nn->next = sorted;
            sorted = nn;
        }
        else
        {
            node *current = sorted;
            while (current->next != NULL && current->next->name < nn->name)
            {
                current = current->next;
            }
            nn->next = current->next;
            current->next = nn;
        }
    }
};

node *CreateClass(int n)
{
    LL list;
    int rl;
    string name;

    cout << "Enter Rollno & Name:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> rl >> name;
        list.insertFront(rl, name);
    }

    list.insertionSort();

    return list.head;
}

node *MergeClass(node *h1, node *h2)
{
    node *nn = h1;
    while (nn->next != NULL)
    {
        nn = nn->next;
    }
    nn->next = h2;

    LL list;

    list.head = h1;
    list.insertionSort();

    return list.head;
}
void print(node *head)
{
    node *p = head;
    while (p->next != NULL)
    {
        cout << p->name << " " << p->rollNo << "\n";
        p = p->next;
    }
    cout << p->name << " " << p->rollNo << endl;
}
int main()
{
    cout << "\nH1\n";
    node *h1 = CreateClass(3);
    cout << "\nH2\n";
    node *h2 = CreateClass(2);
    cout << "\n---H1---\n";
    print(h1);
    cout << "\n---H2---\n";
    print(h2);

    node *hm = MergeClass(h1, h2);
    cout << "\nMerged\n";
    print(hm);
}