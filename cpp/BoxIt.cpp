#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated, BoxesDestroyed;

class Box {
private:
	int l, b, h;
public:
	Box():
		l(0),
		b(0),
		h(0){
		BoxesCreated++;
	}
	Box(int length, int breadth, int height):
		l(length),
		b(breadth),
		h(height){
		BoxesCreated++;
	}
	Box(const Box& B) {
		l = B.l;
		b = B.b;
		h = B.h;
		BoxesCreated++;
	}
	virtual ~Box() {
		BoxesDestroyed++;
	}

	int getLength() {
		return l;
	}
	int getBreadth() {
		return b;
	}
	int getHeight() {
		return h;
	}
	long long CalculateVolume() {
		return (long long)l*b*h;
	}

	//Overload operator < as specified
	bool operator<(Box &b) {
		if ((l < b.l) ||
			((this->b < b.b) && (l == b.l)) ||
			((h < b.h) && (this->b == b.b) && (l == b.l))) {
			return true;
		}
		else
			return false;
	}

	/*
	//	Overload operator << as specified
	friend ostream& operator<<(ostream& out, Box B) {
		out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
		return out;
	}
	*/
};

//	Overload operator << as specified
 ostream& operator<<(ostream& out, Box B) {
	out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();
	return out;
}

void check2()
{
	int n;
	cin >> n;
	Box temp;
	for (int i = 0; i<n; i++)
	{
		int type;
		cin >> type;
		if (type == 1)
		{
			cout << temp << endl;
		}
		if (type == 2)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			temp = NewBox;
			cout << temp << endl;
		}
		if (type == 3)
		{
			int l, b, h;
			cin >> l >> b >> h;
			Box NewBox(l, b, h);
			if (NewBox<temp)
			{
				cout << "Lesser" << endl;
			}
			else
			{
				cout << "Greater" << endl;
			}
		}
		if (type == 4)
		{
			cout << temp.CalculateVolume() << endl;
		}
		if (type == 5)
		{
			Box NewBox(temp);
			cout << NewBox << endl;
		}

	}
}

int main()
{
	BoxesCreated = 0;
	BoxesDestroyed = 0;
	check2();
	cout << "Boxes Created : " << BoxesCreated << endl << "Boxes Destroyed : " << BoxesDestroyed << endl;
}
