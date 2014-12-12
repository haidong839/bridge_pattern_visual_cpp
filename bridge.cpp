// bridge.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;
using namespace System;


ref class Color abstract
{  
public:
	virtual void fillColor() = 0;  
};  

ref class RedColor : Color
{  
public:
	virtual void fillColor  () override
	{  
		Console::WriteLine("red color");  
	}  
}; 

ref class BlueColor : Color
{  
public:
	virtual void fillColor  () override
	{  
		Console::WriteLine("blue color");  
	}  
}; 

ref class Shape abstract
{ 
public:
	Shape(void)	{;}
	Color^ color;  
	Shape(Color^ color)  
	{  
		this->color=color;  
	} 

	virtual void colorIt() = 0;  
};

ref class Rectangle : Shape
{  
public:
	Rectangle(void){;}
	Rectangle(Color^color)
	{
		__super::color = color;
	}
	virtual void colorIt() override 
	{  
		Console::WriteLine("Rectangle filled with ");  
		color->fillColor();  
	}  
};

ref class Circle : Shape
{  
public:
	Circle(void){;}
	Circle(Color^color)
	{
		__super::color = color;
	}
	virtual void colorIt() override 
	{  
		Console::WriteLine("Circle filled with ");  
		color->fillColor();  
	}  
};

int _tmain(int argc, _TCHAR* argv[])
{
	Shape^ s1=gcnew Rectangle(gcnew RedColor());  
	s1->colorIt();  
	Shape^ s2=gcnew Circle(gcnew BlueColor());  
	s2->colorIt();  
	Console::ReadLine();
	return 0;
}

