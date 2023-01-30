#include "Player.h"
#include "Help.h"
#include "Map_generator.h"
#include "View.h"

#ifdef _WIN32
Player::Player() :Entity("GgWalks.png", generate_random_number(tr.tree[tr.tree.size() - 1][0]->room.x1 * 128, tr.tree[tr.tree.size() - 1][0]->room.x2 * 128), generate_random_number(tr.tree[tr.tree.size() - 1][0]->room.y2 * 128, tr.tree[tr.tree.size() - 1][0]->room.y1 * 128), 128, 128)
{
	//image.createMaskFromColor(Color(41, 33, 59));//������� �������� �����-����� ����, ��� ���� ��� ���������� �� ��������.
	health = 100;
	current_frame = 0;
	animation_speed = 0.07;
	is_shoot = false;
	xBlocks = int(x / 128);
	yBlocks = int(y / 128);
	sprite.setTextureRect(IntRect(7 * w, int(current_frame) * h, w, h));
	vel = 0.2;
	get_player_coordinate_for_view(x, y, view);
	Damage = 7;
}
#else
Player::Player() :Entity("/home/sergey/Desktop/4sem/kt/currentBuild/fuckGame/Images/GgWalks.png", generate_random_number(tr.tree[tr.tree.size() - 1][0]->room.x1 * 128, tr.tree[tr.tree.size() - 1][0]->room.x2 * 128), generate_random_number(tr.tree[tr.tree.size() - 1][0]->room.y2 * 128, tr.tree[tr.tree.size() - 1][0]->room.y1 * 128), 128, 128)
{
	//image.createMaskFromColor(Color(41, 33, 59));//������� �������� �����-����� ����, ��� ���� ��� ���������� �� ��������.
	health = 100;
	current_frame = 0;
	animation_speed = 0.06;
	is_shoot = false;
	xBlocks = int(x / 128);
	yBlocks = int(y / 128);
	sprite.setTextureRect(IntRect(7 * w, int(current_frame) * h, w, h));
	vel = 0.24;

	get_player_coordinate_for_view(x, y, view);
	Damage = 10;
}
#endif // _WIN32



Player::~Player()
{
}

void Player::animate(char dir)
{
	if (dir == 'A') { //���� ������ ������� ������� ����� ��� ���� ����� �
		speed = vel;
		direction = 1; current_frame += 2 * animation_speed;   //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
		if (current_frame > 4) current_frame -= 4; // ���� ������ � �������� ����� - ������������ �����.
		sprite.setTextureRect(IntRect(2 * w, int(current_frame) * h, w, h)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
		get_player_coordinate_for_view(x, y, view);
	};

	if (dir == 'D') { //���� ������ ������� ������� ����� ��� ���� ����� D
		speed = vel;
		direction = 0; current_frame += 2 * animation_speed;   //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
		if (current_frame > 4) current_frame -= 4; // ���� ������ � �������� ����� - ������������ �����.
		sprite.setTextureRect(IntRect(3 * w, int(current_frame) * h, w, h)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
		get_player_coordinate_for_view(x, y, view);
	};

	if (dir == 'W') { //���� ������ ������� ������� ����� ��� ���� ����� W
		speed = vel;
		direction = 3; current_frame += 2 * animation_speed; //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
		if (current_frame > 4) current_frame -= 4; // ���� ������ � �������� ����� - ������������ �����.
		sprite.setTextureRect(IntRect(4 * w, int(current_frame) * h, w, h)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
		get_player_coordinate_for_view(x, y, view);
	};

	if (dir == 'S') { //���� ������ ������� ������� ����� ��� ���� ����� S
		speed = vel;
		direction = 2; current_frame += 2 * animation_speed;  //������ ��� ����������� �� "������". ���������� ������� �� ���� �������� ������������ ������� � ��������. ������� 0.005 ����� �������� �������� ��������
		if (current_frame > 4) current_frame -= 4; // ���� ������ � �������� ����� - ������������ �����.
		sprite.setTextureRect(IntRect(7 * w, int(current_frame) * h, w, h)); //���������� �� ����������� �. ���������� �������� ��������� � ���������� � ������ 0,96,96*2, � ����� 0
		get_player_coordinate_for_view(x, y, view);
	}
}

void Player::interaction_with_map(bool** MAP)//�-��� �������������� � ������
{
	for (int i = y / 128; i < (y + h) / 128; i++)//���������� �� ��������, �������������� � �������, �� ���� �� ���� ����������� ������� 32*32, ������� �� ���������� � 9 �����. ��� ������� ������� ����.
		for (int j = x / 128; j < (x + w) / 128; j++)//��� ����� �� 32, ��� ����� �������� ����� ���������, � ������� �������� �������������. (�� ���� ������ ������� 32*32, ������� ����� ������������ ������ �� ���������� ���������). � j<(x + w) / 32 - ������� ����������� ��������� �� ����. �� ���� ���������� ������ ������� ��������, ������� ������������� � ����������. ����� ������� ���� � ����� ����� ������� �� ����, ������� �� �� ������ �������� (���������������� � ������), �� ������� �������� (���������������� � ������)
		{
			if (MAP[i][j] == false)//���� ��� ��������� ������������� ������� 0 (�����), �� ��������� "����������� ��������" ���������:
			{
				if (dy > 0)//���� �� ��� ����,
				{
					y = i * 128 - h;//�� �������� ���������� ����� ���������. ������� �������� ���������� ������ ���������� �� �����(�����) � ����� �������� �� ������ ������� ���������.
				}
				if (dy < 0)
				{
					y = i * 128 + h;//���������� � ������� �����. dy<0, ������ �� ���� ����� (���������� ���������� ������)
				}
				if (dx > 0)
				{
					x = j * 128 - w;//���� ���� ������, �� ���������� � ����� ����� (������ 0) ����� ������ ���������
				}
				if (dx < 0)
				{
					x = j * 128 + w;//���������� ���� �����
				}
			}
		}
}

void Player::control()
{
	if (Keyboard::isKeyPressed(Keyboard::A)) {
		animate('A');
	}
	if (Keyboard::isKeyPressed(Keyboard::D)) {
		animate('D');
	}
	if (Keyboard::isKeyPressed(Keyboard::S)) {
		animate('S');
	}
	if (Keyboard::isKeyPressed(Keyboard::W)) {
		animate('W');
	}
}

void Player::update(float time, bool** Map) {
	switch (direction)//��������� ��������� � ����������� �� �����������. (������ ����� ������������� �����������)
	{
	case 0: dx = speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ��������, ��� �������� ���� ������ ������
	case 1: dx = -speed; dy = 0; break;//�� ���� ������ ������������� ��������, �� ������ ��������. ����������, ��� �������� ���� ������ �����
	case 2: dx = 0; dy = speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ ����
	case 3: dx = 0; dy = -speed; break;//�� ���� ������ ������� ��������, �� ������ �������������. ����������, ��� �������� ���� ������ �����
	}
	x += dx * time;//�� �������� �� �������� �����. ���� ��������� �� ����� �������� �������� ��������� � ��� ��������� ��������
	y += dy * time;//���������� �� ������
	xBlocks = int(x / 128);
	yBlocks = int(y / 128);
	speed = 0;//�������� ��������, ����� �������� �����������.
	sprite.setPosition(x, y); //������� ������ � ������� x y , ����������. ���������� ������� � ���� �������, ����� �� ��� ������ ����� �� �����.
	interaction_with_map(Map);
	change_view(view);
	if (health <= 0) {
		is_life = false;
	}
}