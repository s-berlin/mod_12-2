#include "Node.h"
#include <iostream>
using namespace std;

class List
{
public:
    List() : m_head(nullptr) {}
    void push_back(int data);
    void push_front(int data);
    void insert(int pos, int data);
    void deleteNode(int data);
    void deleteNodePos(int position);
    void show();
private:
    Node* m_head;
};

void List::push_back(int data)
{
    // ������� ����� ����
    Node* node = new Node(data);
    // ���� ������ ����, ���������� ����
    if (m_head == nullptr)
    {
        m_head = node;
        return;
    }
    // � ����� ���� ��������� ������� ������
    Node* last = m_head;
    while (last->m_next != nullptr)
    {
        last = last->m_next;
    }
    // ��������� ��������� next ���������� ���� �� ��������� �� ����� ����
    last->m_next = node;
    return;
};

void List::push_front(int data)
{
    Node* node = new Node(data);
    node->m_next = m_head;
    m_head = node;
};

void List::insert(int pos, int data)
{
    // ������� ����� ���� 
    Node* newNode = new Node(data);
    if (m_head == nullptr)
    {
        // ���� ������ ����, ����� ���� � ����� ������� ������
        m_head = newNode;
        return;
    }

    if (pos == 0)
    {
        // ������� ������ - �������  � ������ ������
        newNode->m_next = m_head;
        m_head = newNode;
        return;
    }

    int currPos = 0;

    Node* current = m_head;
    // � ����� ���� �� ������, ���� ������ �� ��������, ��� ���� �� ������ �� �������
    while (currPos < pos - 1 && current->m_next != nullptr)
    {
        current = current->m_next;
        currPos++;
    }
    // ������ ��������� �� ��������� ���� �� ��������� �� ����� ����
    Node* next = current->m_next;
    current->m_next = newNode;
    // ��������� ������ �������, ������ ��������� �� ����, ��������� ����� ������ ����, �� ��������� �� ����, ��������� �� current
    newNode->m_next = next;
};

void List::show()
{
    Node* current = m_head;

    cout << "������:" << endl;
    while (current != nullptr)
    {
        cout << current->m_data << endl;
        current = current->m_next;
    }
};

void List::deleteNode(int data)
{
    Node* temp = m_head;
    Node* prev = nullptr;

    // ������� ������ �������� ������ ������
    if (temp && temp->m_data == data)
    {
        m_head = temp->m_next;
        delete temp;
        return;
    }
    // ���� �� ������, ���� �� ������ ���� �� ��������� ������, ������ �����
    while (temp && temp->m_data != data)
    {
        prev = temp;
        temp = temp->m_next;
    }
    // ���� ���� �� ������, ����������
    if (!temp)
        return;
    // ������ ��������� ���������� ���� ��� ����������� ���� �� ����, ��������� �� ��������� �����, � ������� ���� � �������
    prev->m_next = temp->m_next;
    delete temp;
};

void List::deleteNodePos(int position)
{
    Node* current = m_head;
    Node* prev = nullptr;

    int i = 1;
    while(i < position && current != nullptr)
    {
        prev = current;
        current = current->m_next;
        i++;
    }
    
    if (i == position)
    {
        if (i == 1) m_head = current->m_next;
        if (i > 1 && current != nullptr) prev->m_next = current->m_next;
        delete current;
    }
    
    return;
    
};

