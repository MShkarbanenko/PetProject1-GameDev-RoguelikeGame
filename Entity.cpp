#include "Entity.h"

Entity::Entity(String F, float X, float Y, float W, float H)
{
    dx = 0; dy = 0; speed = 0; direction = 0;
    is_life = true;
    is_bullet = false;
    File = F;//��� �����+����������
    w = W; h = H;//������ � ������
#ifdef _WIN32
    image.loadFromFile("Images/" + File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� image.loadFromFile("images/hero/png");

#else
    image.loadFromFile(File);//���������� � image ���� ����������� ������ File �� ��������� ��, ��� �������� ��� �������� �������. � ����� ������ "hero.png" � ��������� ������ ���������� image.loadFromFile("images/hero/png");
#endif // _WIN32
    texture.loadFromImage(image);//���������� ���� ����������� � ��������
    sprite.setTexture(texture);//�������� ������ ���������
    x = X; y = Y;//���������� ��������� �������
    sprite.setPosition(x, y);
}

Entity::~Entity()
{
}


void Entity::interaction_with_map(bool** MAP)//�-��� �������������� � ������
{
}

void Entity::animate(int dir)
{
}

void Entity::sleepcp(int milliseconds) // Cross-platform sleep function
{
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif // _WIN32
}


void Entity::update(float time, bool** Map)
{
}
