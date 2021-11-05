#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimeter "\n-------------------------------------------\n"

class String;
String operator+(const String& left, const String& right);

class String
{
	unsigned int size;  // размер в байтах
	char* str;			// указатель на строку в памяти
public:
	//			Getters. Setters
	unsigned int get_size() const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str() { return str; }
	//			Constructors
	explicit String(unsigned int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "Default constructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++) this->str[i] = str[i];
		cout << "Constructor: \t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		// this->str = other.str; !ERROR - Shallow copy
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i]; // Deep copy
		cout << "Copy constructor: \t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;
		cout << "MoveConstructor: \t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	//			Operators
	const char& operator[](unsigned int i)const	{ return str[i]; }
	
	char& operator[](unsigned int i) { return str[i]; }

	String& operator+=(const String& other)
	{
		return *this = *this + other;
	}

	String& operator=(const String& other)
	{
		if (this == &other) return *this;

		delete[] this->str;

		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++) this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	//			Methods
	void print() const
	{
		cout << "Size: " << size << endl;
		cout << "Str: " << str << endl;
	}
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		//cat.get_str()[i] = left.get_str()[i];
		cat[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		//cat.get_str()[i + left.get_size() - 1] = right.get_str()[i];
		cat[i + left.get_size() - 1] = right[i];

	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

//std::istream& operator>>(std::istream& is, const String& obj)
//{
//	return is >> obj.get_str();
//}

//#define CONSTRUCTORS_CHECK
//#define INPUT_CHECK
//#define OPERATOR_PLUS_CHECK

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	String str;
	str.print();

	String str1 = "Hello";
	str1.print();

	cout << str1 << endl;

	String str2 = str1;
	str2.print();

	String str3;
	str3 = str2;
	cout << str3 << endl;
#endif // CONSTRUCTORS_CHECK

#ifdef INPUT_CHECK
	String str;
	cout << "Input string";
	cin >> str;

	cout << str << endl;
#endif // INPUT_CHECK

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimeter;
	String str3 = str1 + " " + str2;
	cout << delimeter;

	cout << str3 << endl;

	str1 += str2;
	cout << str1 << endl;
#endif // OPERATOR_PLUS_CHECK



}