//	INSERT AT ANY POSITION,
//	DELETE AT ANY POSITION,
//	REVERSE BY BREAKING AND CREATING LINKS (ITERATE APPROACH & RECURSIVE APPROACH).

#include <iostream>

using namespace std;

class Node
{
public:

    int data;
    Node* next;
};

Node* head;

void Insert(int x, int n)
{
    Node* node = new Node();
    (*node).data = x;
    (*node).next = NULL;

    if(n==1)
    {
        (*node).next = head;
        head = node;
        return;
    }

    Node* temp = head;
    for(int i=0;i<n-2;i++)
    {
        temp = (*temp).next;
    }
    (*node).next = (*temp).next;
    (*temp).next = node;
}

void Print()
{
    Node* temp = head;
    while(temp!=NULL)
    {
        cout << (*temp).data << " ";
        temp = (*temp).next;
    }
}

void Delete(int r)  //deleting element
{
    Node* temp = head;

    if((*temp).data==r)
    {
        head = (*temp).next;
        delete temp;
        return;
    }

    Node* temp3;

    while((*temp).next!=NULL)
    {
        temp3 = temp;
        temp = (*temp).next;
        if((*temp).data==r)
        {
            break;
        }
    }
    if((*temp).next!=NULL)
    {
        Node* temp2 = (*temp3).next;
        (*temp3).next = (*temp2).next;

        delete temp2;

        //(*temp).next = (*((*temp).next)).next;
    }
    else
    {
        cout << "ITEM NOT PRESENT" << endl;
    }
}

void Reverse()	//	ITERATE APPROACH
{
    Node* temp;
    Node* temp2;
    Node* temp3;

    temp = head;
    temp2 = NULL;

    while(temp!=NULL)
    {
        temp3 = (*temp).next;
        (*temp).next = temp2;
        temp2 = temp;
        temp = temp3;
    }
    head = temp2;
}

void reversePrint(Node* temp)	//	RECURSIVE APPROACH
{
    if((*temp).next == NULL)
    {
        head = temp;
        return;
    }
    reversePrint((*temp).next);

    Node* temp2;
    temp2 = (*temp).next;
    (*temp2).next = temp;
    (*temp).next = NULL;
}

int main()
{
    head = NULL;
    cout << "Enter the number of Elements to Add in the Linked List" << endl;
    int numb;
    cin >> numb;

    int z=1;
    for(int i=0;i<numb;i++)
    {
        int n;
        cout << "Enter the Position of Element to Insert" << endl;
        cin >> n;

        if(n<=z)
        {
            int x;
            cout << "Enter the Element to be Inserted at " << n << endl;
            cin >> x;

            Insert(x, n);
            z++;
        }
        else
        {
            cout << "Warning: Position is less" << endl << "Enter Again" << endl;
            i--;
        }
    }
    Print();

    while(head!=NULL)
    {
        cout << endl;

        cout << "Do you want to delete a Node (y/n)" << endl;

        char ch;

        cin >> ch;

        if(ch=='y')
        {
            cout << "Enter the Element to delete" << endl;

            int r;
            cin >> r;

            Delete(r);
            Print();
        }
        else
        {
            break;
        }
    }
    cout << endl << "Reversing Linked List..." << endl;
    Reverse();
    //reversePrint();
    Print();
}
