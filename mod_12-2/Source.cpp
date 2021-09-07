#include "List.h"
#include <iostream>
using namespace std;
/*
void List::push_back(int data)
{
    // создаем новый узел
    Node* node = new Node(data);
    // если список пуст, возвращаем узел
    if (m_head == nullptr)
    {
        m_head = node;
        return;
    }
    // в цикле ищем последний элемент списка
    Node* last = m_head;
    while (last->m_next != nullptr)
    {
        last = last->m_next;
    }
    // Обновляем указатель next последнего узла на указатель на новый узел
    last->m_next = node;
    return;
}
*/



int main()
{
    setlocale(LC_ALL, "");

    List newLst;
    for(int i = 1; i < 11; i++) newLst.push_back(i * i);
    newLst.show();

    newLst.deleteNodePos(3);
    newLst.show();

    newLst.deleteNode(25);
    newLst.show();

    newLst.deleteNodePos(1);
    newLst.show();

    newLst.deleteNodePos(7);
    newLst.show();

    newLst.deleteNodePos(7);
    newLst.show();
}
