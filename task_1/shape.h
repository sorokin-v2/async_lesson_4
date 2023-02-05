#pragma once
#define _USE_MATH_DEFINES
//#include <cmath>											//����� �� ��������� M_PI, �� ����� ���������� ���������� math.h
#include<math.h>

enum class ShapeTypes { line = 0, sqr, cube, circle, cylinder };

struct Point2D {
	int x{ 0 };
	int y{ 0 };
};

std::ostream& operator<< (std::ostream& os, const Point2D& src) {
	std::cout << src.x << " " << src.y;
	return os;
}


struct Point3D {
	int x{ 0 };
	int y{ 0 };
	int z{ 0 };
};

std::ostream& operator<< (std::ostream& os, const Point3D& src) {
	std::cout << src.x << " " << src.y << " " << src.z;
	return os;
}

class Shape {
public:
	int getType() const { return static_cast<int>(_type); }

protected:
	Shape() = default;										//��������� �������� ����������� ����� ������
	ShapeTypes _type{ ShapeTypes::line };
	double _square{ 0.0 };
};


class Shape2D : public Shape {
public:
	Shape2D() = delete;										//������� ����������� �� ���������

	const Point2D& getPointA() const { return _a; }

protected:
	Shape2D(const Point2D& a) : _a{ a } {}					//��������� �������� ����������� ����� ������
	Point2D _a;	
};


class Shape3D : public Shape{
public:
	
	Shape3D() = delete;										//������� ����������� �� ���������

	const Point3D& getPointA() const { return _a; }
	const double getVolume() const { return _volume; }

protected:
	
	Shape3D(const Point3D& a) : _a{ a } {}					//��������� �������� ����������� ����� ������
	Point3D _a;
	double _volume{ 0.0 };
};


class Line : public Shape2D {
public:
	Line() = delete;										//��������� ����������� �� ���������
	Line(const Point2D& a, const Point2D& b) : Shape2D(a), _b{ b } { _type = ShapeTypes::line; }
	void shift(const int m, const int n) {
		_a.x += m;
		_a.y += n;
		_b.x += m;
		_b.y += n;
	}

	void scaleX(const int a) {
		_a.x *= a;
		_b.x *= a;
	}

	void scaleY(const int d) {
		scaleX(d);										//�� ������� ������ � scaleY ���������� �� �� ����� ������, ��� � � scaleX
	}

	void scaleZ(const int e) {
		scaleX(e);										//�� ������� ������ � scaleZ ���������� �� �� ����� ������, ��� � � scaleX
	}

	void scale(const int s) {
		_a.x /= s;
		_a.y /= s;
		_b.x /= s;
		_b.y /= s;
	}

	const Point2D& getPointB() const { return _b; }

private:
	Point2D _b;
};

class Sqr : public Shape2D {
public:
	Sqr() = delete;											//��������� ����������� �� ���������
	Sqr(const Point2D& a, const Point2D& b) : Shape2D(a), _b{ b }	{
		_type = ShapeTypes::sqr;
		_square = abs(a.x - b.x)* abs(a.y - b.y);
	}
	void shift(const int m, const int n) {
		_a.x += m;
		_a.y += n;
		_b.x += m;
		_b.y += n;
	}

	void scaleX(const int a) {
		_a.x *= a;
		_b.x *= a;
	}

	void scaleY(const int d) {
		scaleX(d);										//�� ������� ������ � scaleY ���������� �� �� ����� ������, ��� � � scaleX
	}

	void scaleZ(const int e) {
		scaleX(e);										//�� ������� ������ � scaleZ ���������� �� �� ����� ������, ��� � � scaleX
	}

	void scale(const int s) {
		_a.x /= s;
		_a.y /= s;
		_b.x /= s;
		_b.y /= s;
	}

	const Point2D& getPointB() const { return _b; }

private:
	Point2D _b;												//��� �������� ���������� ��������� 2-� ������������ �����
};

class Cube : public Shape3D {
public:
	Cube() = delete;										//��������� ����������� �� ���������
	Cube(const Point3D& a, const Point3D& b, const Point3D& c) : Shape3D(a), _b{ b }, _c (c)
	{
		_type = ShapeTypes::cube;
		int delta_a = abs(a.x - b.x);
		int delta_b = abs(a.y - b.y);
		int delta_c = abs(a.z - b.z);

		_square = 2 * delta_a * delta_b + 2 * delta_a * delta_c + 2 * delta_b * delta_c;
		_volume = delta_a * delta_b * delta_c;
	}

	void shift(const int m, const int n, const int k) {
		_a.x += m;
		_a.y += n;
		_a.z += k;
		_b.x += m;
		_b.y += n;
		_b.z += k;
		_c.x += m;
		_c.y += n;
		_c.z += k;
	}

	void scaleX(const int a) {
		_a.x *= a;
		_b.x *= a;
		_c.x *= a;
	}

	void scaleY(const int d) {
		scaleX(d);										//�� ������� ������ � scaleY ���������� �� �� ����� ������, ��� � � scaleX
	}

	void scaleZ(const int e) {
		scaleX(e);										//�� ������� ������ � scaleZ ���������� �� �� ����� ������, ��� � � scaleX
	}


	void scale(const int s) {
		_a.x /= s;
		_a.y /= s;
		_a.z /= s;
		_b.x /= s;
		_b.y /= s;
		_b.z /= s;
		_c.x /= s;
		_c.y /= s;
		_c.z /= s;
	}

	const Point3D& getPointB() const { return _b; }
	const Point3D& getPointc() const { return _c; }

private:
	Point3D _b;
	Point3D _c;												//��� ���� ���������� 3-� �����
};

class Circle : public Shape2D {
public:
	Circle() = delete;										//��������� ����������� �� ���������
	Circle(const Point2D& a, const double radius) : Shape2D(a), _radius{ radius }
	{
		_type = ShapeTypes::circle;
		_square = M_PI * _radius * _radius;
	}

	const double getRadius() const { return _radius;  }

protected:
	double _radius{ 0.0 };
};


class Cylinder : public Circle {							//�� �������� ������ ���������� �������� �������� 2 ����������� (�.�. ������� ��� 2D �������, �� ����� ����� ������������� �� Circle)
public:
	Cylinder() = delete;									//��������� ����������� �� ���������
	Cylinder(const Point2D& a, const double radius, const double height) : Circle(a, radius), _height{ height }
	{
		_type = ShapeTypes::cylinder;
		_volume = _square * _height;						// M_PI * _radius * _radius ��� ���� ���������� � ������������ Circle � ��������� square
		_square += 2 * _radius * _height;					// M_PI * _radius * _radius ��� ���� ���������� � ������������ Circle � ��������� square
	}

	const double getHeight() const { return _height; }
	const double getVolume() const { return _volume; }

private:
	double _height{ 0.0 };
	double _volume{ 0.0 };
};
