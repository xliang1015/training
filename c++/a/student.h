class student
{
	int age;
	int sex;
	char name[4];
public:
	static int num;
	friend void show_student(student &s);
	student();
	student(const student &s);
	virtual ~student();
	const char *getname() const;
	virtual int getage() const;
	int getsex() const;
	void setage(int age);
};

class kindergarten_student: student
{
	bool can_piepie;
	bool can_poopoo;
public:
	kindergarten_student();
	kindergarten_student(const kindergarten_student &ks);
	~kindergarten_student();
	bool getcanpiepie() const;
	bool getcanpoopoo() const;
	void setcanpiepie(bool pie);
};
