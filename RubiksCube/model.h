#include <iostream>

using namespace std;

class Position
{
public:
	int facet;
	int position;
public:
	Position(): facet(0), position(0) {}
	void Swap(Position pos1, Position pos2)
	{
		swap(pos1.facet, pos2.facet);
		swap(pos1.position, pos2.position);
	}
	friend ostream& operator << (ostream& out, const Position& m)
	{
		out << "Facet: " << m.facet << "  position: " << m.position;
		return out;
	}
	Position& operator = (Position const& m)
	{
		facet = m.facet;
		position = m.position;
		return *this;
	}
	Position& operator = (int const a)
	{
		facet = a;
		position = a;
		return *this;
	}
	bool operator == (Position const m) { return facet == m.facet && position == m.position ? 1 : 0;}
	friend bool operator == (Position const m, int a) { return m.facet == a && m.position == a ? 1 : 0;}
	bool operator != (Position const m) { return facet != m.facet && position != m.position ? 1 : 0;}
	friend bool operator != (Position const m, int a) { return m.facet != a && m.position != a ? 1 : 0;}
};

class Model
{
public:
	Color* Matr;
	int top_facet;
	int current_facet;
public:
	Model();
	~Model();
	void Up_color();
    void Up_color_stroke();
	void Down_color();
    void Down_color_stroke();
	void Middle_color();
	void Middle_color_stroke();
	void Second_color();
	void Second_color_stroke();
	void Rw_color();
	void Rw_color_stroke();
	void Right_color();
    void Right_color_stroke();
	void Lw_color();
	void Lw_color_stroke();
	void Left_color();
    void Left_color_stroke();
	void Fw_color();
	void Fw_color_stroke();
	void Front_color();
    void Front_color_stroke();
	void Bw_color();
	void Bw_color_stroke();
	void Back_color();
    void Back_color_stroke();
	bool p(int i);
	bool is_full();
	Position Find_part(Col pos);
	int F2l(Model& a, string& str);
	int OLL(Model& a, string& str);
	int PLL(Model& a, string& str);
	Position Pos(int* ind, int& n);
	Position Pst(int* ind, int& n);
	int Turn(int facet, string& str);
	int* Between(int ind, string str);
	void Search(Model& a, string& str);
	Position Combination(string* color);
	bool Check_part(string str, int ind);
	Position Combination(int* ind, int* b);
	Position Find_part(string str, int ind);
	int Data(Model& a, int& pos, int& count);
	int Corners_slow(Model& a, string& moves);
	int Middels_slow(Model& a, string& moves);
	int Turn_up(int ind, int pos, string& str);
	int Turn_up(Position x, int pos, string& str);
	int Intersection_slow(Model& a, string& moves);
	int Intersection_fast(Model& a, string& moves);
	bool Check_part(string str, int ind, int facet);
	int Turn_corners(Position x, int pos, string& str);
	Position Find_part(string str, int ind, int facet);
	int Down_intersection_slow(Model& a, string& moves);
	string Turn_corners(Position x, Position y, int ind);
	int Turn_up(string col, int ind, int pos, string& str);
	int Turn_down(string col, int ind, int pos, string& str);
	int Turn_corners(string col, int ind, int pos, string& str);
	int Turn_md(Position x, int facet, string& str, int flag = 0);
	Position Sequence(Col* color, int* ind, Position& pos, int& n, int& m);
	bool Check(int a, int b, int c, int d, int e, int f, int g, int h, int i);
	void Facet(string str1, string str2, string str3, string str4, string& str);
    Color& operator [] (const int i);
	Col operator () (const int facet, const int position);
    friend ostream& operator << (ostream& out, const Model& m);
};