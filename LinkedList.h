#pragma once
#include "monster.h"		// �̰� �־�� Monster ����ü�� ��� ����


// head, tail�� �˾ƾ� ��� �����ϰ� �������� �� �� �ִ�.
struct MonsterList
{
	Monster* pHead = nullptr;
	Monster* pTail = nullptr;
};

Monster* CreateMonster(MonsterList& list, const char* name, const int hp);
										// �迭�� ������ �����Ƿ� const ���
int GetCountMonsterList(MonsterList& list);
void PrintMonsterList(MonsterList& list);
void PrintMonsterListRecursvie(Monster* monster);
Monster* FindMonster(MonsterList& list, const char* name);
void DeleteList(MonsterList& list);
bool DeleteMonster(MonsterList& list, const char* name);


// ����, ����, �˻�, ����, ����