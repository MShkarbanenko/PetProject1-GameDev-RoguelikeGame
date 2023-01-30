#pragma once
#include "Libraries.h"

extern const int MIN_LEAF_WIDTH, MIN_LEAF_HEIGHT, LEVEL_NUMBER, MAX_LEAF_NUMBER, ROOM_WIDTH, ROOM_HEIGHT, MAP_WIDTH, MAP_HEIGHT;
extern int leaf_number;
//bool** MAP = new bool* [MAP_HEIGHT];

struct rectangle {
	int x1;
	int y1;
	int x2;
	int y2;
	int width = x2 - x1 + 1;
	int height = y1 - y2 + 1;
};

class Leaf
{

public:

	rectangle r;	//���������� �����
	rectangle room;	//���������� ������� ������ �����
	rectangle hall;	//���������� �������� ������������ �������� �����
	bool rooM;	//������� �������
	int width, height;//������ � ������ �����

	Leaf* Left_child;	//����� �������
	Leaf* Right_child;	//������ �������


	Leaf(int X1, int Y1, int X2, int Y2);	//������� ����

	~Leaf();

	void print_leaf();//�������� ����

	bool split();	//��������� ����

	bool create_room();	//������� �������
};

class Tree {

public:

	int n;

	vector<vector<Leaf*>> tree;

	vector<rectangle> halls;

	Tree();

	~Tree();

	bool generate_random_section(int x1, int x2, const int l, int& x);

	bool create_hall(rectangle& r1, rectangle& r2); //������� ������� ����� ����� ���������

	bool generate_tree(); // ������� ������ ������

	void print_tree();	// �������� ������

};

extern Tree tr;


void add_leaf(bool** M, Leaf& l);

void add_room(bool** M, Leaf& l);  

void add_hall(bool** M, rectangle& hall);

void print_map(bool** M);

void create_map(vector<vector<Leaf*>>& tree, vector<rectangle> Halls, bool** Map);

bool GENERATE_MAP(bool** Map);