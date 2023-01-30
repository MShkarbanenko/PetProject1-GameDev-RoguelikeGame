#pragma once
#include "Libraries.h"
#include "Map.h"
#include "Bullet.h"
#include "Timer.h"
#include "Map_generator.h"

int generate_random_number(int x1, int x2);//���������� ��������� ����� �� x1 �� x2

bool wall_or_not(bool** MAP, int x, int y);//���������� ����� ��� ��� ������������ �� �������

bool super_floor_or_not(bool** MAP, int x, int y);

void map_draw(bool** MAP, Map &M, int y, int x);

void bullets_clear(list<Bullet*> bullets, list<Bullet*> ::iterator BuIt);
