#include <iostream>
#include <cstring>
#include "LinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
    Monster* pNew = new Monster{};
   
    // ���ڿ��� ������ �� �����Ƿ� strcpy ��� ( ex) arrayA = arrayB (X) )
    strcpy_s(pNew->name,  NAME_LENGTH , name);
                            //  strcpy (char* Destination, const char* Source)
                            //  strcpy�� �迭�� ũ�⸦ �ȳѰ��ֹǷ� �Ҿ���
                            //  ���� ������ strcpy_s �� ����Ѵ�
             // strcpy_s (char* Destination, rsize_t Size, const char* Source)
    pNew->hp = hp;

    if (list.pTail == nullptr)
    {
        list.pHead = pNew;
        list.pTail = pNew;
    }
    else
    {
        list.pTail->pNext = pNew;
        // ȭ��ǥ ������ = *(list.pTail).pNext�� �����ϰ� ǥ���Ѱ�
        // ��, ������ ��, �� ���� ����� �����ϴ� ���̴�.
        // �̹� list.pTail�� �� ���� Monster*�� ����Ǿ��ֱ� ������
        // list.pTail�� ������ ��, �� ���� ����� pNext�� �����ϴ� ���̴�.
        // �׷��� list.pTail->pNext�� ������ ���̴�.
        // �ڼ��� �׸��� �º�����

        list.pTail = pNew;

        // ���� �ٲ�� �ȵ�!
        // ���� �ٲٸ� pHead->pNext->pNext ���� ���¸� �����
    }

    return pNew;
}

int GetCountMonsterList(MonsterList& list)
{
    int count{};
    Monster* temp = list.pHead;

    while (temp != nullptr)
    {
        count++;
        temp = temp->pNext;
    }
    return count;
}

void PrintMonsterList(MonsterList& list)
{
    Monster* temp = list.pHead;

    while (temp != nullptr)
    {   
        std::cout << temp->name << " : " << temp->hp << std::endl;
        temp = temp->pNext;
    }
}

void PrintMonsterListRecursvie(Monster* monster)
{
    // base case
    if (monster == nullptr)
    {
        return;
    }

    // recursive case
    std::cout << monster->name  << " : " << monster->hp << std::endl;
    PrintMonsterListRecursvie(monster->pNext);
}

// �迭, ���� ���� ����Ʈ �� ó������ ������ �̵��ϴ� ���� traverse ��� �Ѵ�.
// traverse�� ����Լ��� ����� �����ϴ�

Monster* FindMonster(MonsterList& list, const char* name)
{
    Monster* temp = list.pHead;

    while (temp != nullptr)
    {
        if (strcmp(temp->name, name) == 0)   
        // �����ͳ��� ���ٰ� �Ѵٸ� �װ� ����Ű�� ���� ���� ���̴�.
        // �׷��� ������ == ������ �� ǥ��� ���� �ʴ�.
        // ���� strcmp�� ����Ѵ�.
        // strcmp = string compare(const char* str1, const char* str2)
        // ASCII �ڵ带 ���� ���̹Ƿ�, ���� ���� 0�̴�
        {
            return temp;
        }
        temp = temp->pNext;
    }

    return nullptr;
}

void DeleteList(MonsterList& list)
{
    Monster* temp = list.pHead;
    Monster* next;              // delete ��, pNext ���� ���󰡱� ������
                                // temp->pNext�� ����� �� ���� �ȴ�
                                // temp->pNext�� ����� ������ next�� ������
    while (temp != nullptr)
    {
        next = temp->pNext;
        delete temp;

        temp = next;
    }

    // ���� ������ ���ĵ�, list.pHead�� list.pTail�� �������̴�. (dangling pointer)
    // ����, nullptr�� ���ƾ� ������ ��������.
    list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
    // Ư�� ���Ҹ� ã�� �����

    // e1 -> e2 -> e3 �� ����Ʈ���� e2�� ����� �ʹٸ�?
    // 1. e2�� ����� = e2 -> e3�� �ڿ������� �����
    // 2. e1 -> e3

    Monster* temp = list.pHead;                 // ����� ���� e2
    Monster* prev{};                            // e2 ���� e1

    while (temp != nullptr)
    {
        if (strcmp(temp->name, name) == 0)
        {
            break;
        }

        prev = temp;
        temp = temp->pNext;
    }
    
    // 1. ã�� ���Ұ� ����Ʈ�� �������� ���� ��
    // 2. ����Ʈ�� ���Ұ� �ƿ� ���� ��
    if (temp == nullptr)
    {
        return false;
    }

    // ���Ұ� �ϳ��ۿ� ���� ��
    if (list.pHead == list.pTail)  // if(GetCountMonsterList(list)) == 1 �� ����
    {                             
        list.pHead = nullptr;
        list.pTail = nullptr;
    }
    // ���� �������� ���Ұ� pHead�� �ִٸ�
    else if (temp == list.pHead)                   
    {
        list.pHead = temp->pNext;
    }
    // ���� �������� ���Ұ� pTail�� �ִٸ�
    else if (temp == list.pTail)
    {
        prev->pNext = nullptr;      // dangling pointer�� ���ش�
        list.pTail = prev;
    }
    // �Ϲ����� ���
    else
    {
        prev->pNext = temp->pNext; 
        // prev->pNext = e1�� ������, temp->pNext = e3
    }

    // ���� 4��쿡 ��� delete temp;�� ���Ƿ� ������ ����
    delete temp;       
    
    return true;
}

