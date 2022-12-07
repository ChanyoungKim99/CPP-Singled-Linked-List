#include <iostream>
#include <cstring>
#include "LinkedList.h"

Monster* CreateMonster(MonsterList& list, const char* name, const int hp)
{
    Monster* pNew = new Monster{};
   
    // 문자열을 복사할 수 없으므로 strcpy 사용 ( ex) arrayA = arrayB (X) )
    strcpy_s(pNew->name,  NAME_LENGTH , name);
                            //  strcpy (char* Destination, const char* Source)
                            //  strcpy는 배열의 크기를 안넘겨주므로 불안정
                            //  따라서 안전한 strcpy_s 를 사용한다
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
        // 화살표 연산자 = *(list.pTail).pNext를 간략하게 표기한것
        // 즉, 역참조 후, 그 안의 멤버로 접근하는 것이다.
        // 이미 list.pTail이 그 전의 Monster*와 연결되어있기 때문에
        // list.pTail을 역참조 후, 그 값의 멤버인 pNext에 접근하는 것이다.
        // 그래서 list.pTail->pNext가 가능한 것이다.
        // 자세한 그림은 태블릿으로

        list.pTail = pNew;

        // 순서 바뀌면 안됨!
        // 순서 바꾸면 pHead->pNext->pNext 같은 형태를 써야함
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

// 배열, 단일 연결 리스트 등 처음부터 끝까지 이동하는 것을 traverse 라고 한다.
// traverse는 재귀함수의 사용이 가능하다

Monster* FindMonster(MonsterList& list, const char* name)
{
    Monster* temp = list.pHead;

    while (temp != nullptr)
    {
        if (strcmp(temp->name, name) == 0)   
        // 포인터끼리 같다고 한다면 그건 가리키는 곳이 같을 뿐이다.
        // 그래서 포인터 == 포인터 의 표기는 옳지 않다.
        // 따라서 strcmp를 사용한다.
        // strcmp = string compare(const char* str1, const char* str2)
        // ASCII 코드를 통한 비교이므로, 같을 때는 0이다
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
    Monster* next;              // delete 시, pNext 까지 날라가기 때문에
                                // temp->pNext를 사용할 수 없게 된다
                                // temp->pNext를 백업할 포인터 next를 만들자
    while (temp != nullptr)
    {
        next = temp->pNext;
        delete temp;

        temp = next;
    }

    // 위의 과정을 거쳐도, list.pHead와 list.pTail은 남을것이다. (dangling pointer)
    // 따라서, nullptr로 놓아야 완전히 지워진다.
    list.pHead = list.pTail = nullptr;
}

bool DeleteMonster(MonsterList& list, const char* name)
{
    // 특정 원소를 찾아 지우기

    // e1 -> e2 -> e3 인 리스트에서 e2만 지우고 싶다면?
    // 1. e2를 지우기 = e2 -> e3가 자연스럽게 사라짐
    // 2. e1 -> e3

    Monster* temp = list.pHead;                 // 지우고 싶은 e2
    Monster* prev{};                            // e2 앞의 e1

    while (temp != nullptr)
    {
        if (strcmp(temp->name, name) == 0)
        {
            break;
        }

        prev = temp;
        temp = temp->pNext;
    }
    
    // 1. 찾는 원소가 리스트에 존재하지 않을 때
    // 2. 리스트에 원소가 아예 없을 때
    if (temp == nullptr)
    {
        return false;
    }

    // 원소가 하나밖에 없을 때
    if (list.pHead == list.pTail)  // if(GetCountMonsterList(list)) == 1 도 가능
    {                             
        list.pHead = nullptr;
        list.pTail = nullptr;
    }
    // 만약 지우고싶은 원소가 pHead에 있다면
    else if (temp == list.pHead)                   
    {
        list.pHead = temp->pNext;
    }
    // 만약 지우고싶은 원소가 pTail에 있다면
    else if (temp == list.pTail)
    {
        prev->pNext = nullptr;      // dangling pointer를 없앤다
        list.pTail = prev;
    }
    // 일반적인 경우
    else
    {
        prev->pNext = temp->pNext; 
        // prev->pNext = e1의 포인터, temp->pNext = e3
    }

    // 위의 4경우에 모두 delete temp;가 들어가므로 밖으로 빼자
    delete temp;       
    
    return true;
}

