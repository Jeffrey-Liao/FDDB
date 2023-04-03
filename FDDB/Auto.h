#pragma once
#ifndef AUTO_H
#define AUTO_H
#include <typeinfo>
#include <iostream>
namespace Manipulate
{
#define NAMEINT "int"
#define NAMECHAR "char"
#define NAMEFLOAT "float"
#define NAMEDOUBLE "double"
#define NAMELONG "__int64"
#define NAMEUNSIGN "unsigned int"
#define NAMESTRING "class std::basic_string<char,struct std::char_traits<char>,class std::allocator<char> >"
#define ASINT *(int*)
#define ASUNSIGNED *(unsigned int*)
#define ASFLOAT *(float*)
#define ASDOUBLE *(double*)
#define ASCHAR *(char*)
#define ASSTRING *(string*)
#define ASLONG *(long long*)
#define ADDINT(x,y) (ASINT x + ASINT y)
#define ADDFLOAT(x,y) (ASFLOAT x + ASFLOAT y)
#define ADDINT(x,y) (ASINT x + ASINT y)
#define ADDINT(x,y) (ASINT x + ASINT y)
	using namespace std;
	enum class AutoTypes
	{
		EMPTY,
		INT,
		UNSIGNED,
		FLOAT,
		DOUBLE,
		CHAR,
		STRING,
		LONG,
		STRUCT
	};
	class Auto
	{
	private:
		void* Data;
		AutoTypes Type;
		bool Const;
		//Varviable
	public:
	
	private:
		template<class TYPE>
		void Assign(TYPE inData, bool inConst=0)
		{
			if (Data != NULL)
				delete Data;
			Data = new TYPE;
			*(TYPE*)Data = inData;
			string Typeid = typeid(inData).name();
			if (Typeid == NAMEINT)
				Type = AutoTypes::INT;
			else if (Typeid == NAMEUNSIGN)
				Type = AutoTypes::UNSIGNED;
			else if (Typeid == NAMECHAR)
				Type = AutoTypes::CHAR;
			else if (Typeid == NAMEFLOAT)
				Type = AutoTypes::FLOAT;
			else if (Typeid == NAMEDOUBLE)
				Type = AutoTypes::DOUBLE;
			else if (Typeid == NAMESTRING)
				Type = AutoTypes::STRING;
			else if (Typeid == NAMELONG)
				Type = AutoTypes::LONG;
			else
				Type = AutoTypes::STRUCT;
			Const = inConst;
		}
		Auto& Plus(Auto& inData)
		{
			Auto Temp;
			if (inData.Type == this->Type)
			{
				if (Type == AutoTypes::INT)
					Temp = ASINT this->Data + ASINT inData.Data;
				else if (Type == AutoTypes::FLOAT)
					Temp = ASFLOAT this->Data + ASFLOAT inData.Data;
				else if (Type == AutoTypes::DOUBLE)
					Temp = ASDOUBLE this->Data + ASDOUBLE inData.Data;
				else if (Type == AutoTypes::UNSIGNED)
					Temp = ASUNSIGNED this->Data + ASUNSIGNED inData.Data;
				else if (Type == AutoTypes::CHAR)
					Temp = ASCHAR this->Data + ASCHAR inData.Data;
				else if (Type == AutoTypes::STRING)
					Temp = ASSTRING this->Data + ASSTRING inData.Data;
				else if (Type == AutoTypes::LONG)
					Temp = ASLONG this->Data + ASLONG inData.Data;
			}
			else
			{

			}
			return Temp;
		}
	public:
		explicit Auto() :Type(AutoTypes::EMPTY), Const(0), Data(NULL)
		{}
		explicit  Auto(int inData,bool inConst = 0)
		{
			Assign<int>(inData, inConst);
		}
		explicit Auto(char inData, bool inConst = 0)
		{
			Assign<char>(inData, inConst);
		}
		explicit Auto(double inData, bool inConst = 0)
		{
			Assign<double>(inData, inConst);
		}
		explicit Auto(float inData, bool inConst = 0)
		{
			Assign<float>(inData, inConst);
		}
		 explicit Auto(unsigned int& inData, bool inConst = 0)
		{
			Assign<unsigned int>(inData, inConst);
		}
		explicit Auto(long long& inData, bool inConst = 0)
		{
			Assign<long long>(inData, inConst);
		}
		explicit Auto(string inData, bool inConst = 0)
		{
			Assign<string>(inData, inConst);
		}
		template <class TYPE>
		explicit Auto(TYPE inData, bool inConst = 0)
		{
			Assign<TYPE>(inData, inConst);
		}
		constexpr Auto& operator=(Auto& inData)
		{
			if (Type == AutoTypes::INT)
				ASINT this->Data = ASINT inData.Data;
			else if (Type == AutoTypes::FLOAT)
				 ASFLOAT this->Data = ASFLOAT inData.Data;
			else if (Type == AutoTypes::DOUBLE)
				 ASDOUBLE this->Data = ASDOUBLE inData.Data;
			else if (Type == AutoTypes::UNSIGNED)
				 ASUNSIGNED this->Data = ASUNSIGNED inData.Data;
			else if (Type == AutoTypes::CHAR)
				 ASCHAR this->Data = ASCHAR inData.Data;
			else if (Type == AutoTypes::STRING)
				 ASSTRING this->Data = ASSTRING inData.Data;
			else if (Type == AutoTypes::LONG)
				ASLONG this->Data = ASLONG inData.Data;
			return *this;
		}
		template <class TYPE>
		void operator= (TYPE inData)
		{
			Assign<TYPE>(inData);
		}
		int operator=(int inData)
		{
			Assign<int>(inData);
			return ASINT(Data);
		}
		char operator=(char inData)
		{
			Assign<char>(inData);
			return ASCHAR(Data);
		}
		float operator= (float inData)
		{
			Assign<float>(inData);
			return ASFLOAT(Data);
		}
		double operator= (double inData)
		{
			Assign<double>(inData);
			return ASDOUBLE(Data);
		}
		string operator= (string inData)
		{
			Assign<string>(inData);
			return ASSTRING(Data);
		}
		long long operator= (long long inData)
		{
			Assign<long long>(inData);
			return ASLONG(Data);
		}
		unsigned int operator= (unsigned int inData)
		{
			Assign<unsigned int>(inData);
			return ASUNSIGNED(Data);
		}
		friend ostream& operator<<(ostream& Out, Auto& Obj)
		{
			if (Obj.Type == AutoTypes::INT)
				Out << ASINT(Obj.Data);
			else if (Obj.Type == AutoTypes::CHAR)
				Out << ASCHAR(Obj.Data);
			else if (Obj.Type == AutoTypes::FLOAT)
				Out << ASFLOAT(Obj.Data);
			else if (Obj.Type == AutoTypes::DOUBLE)
				Out << ASDOUBLE(Obj.Data);
			else if (Obj.Type == AutoTypes::LONG)
				Out << ASLONG(Obj.Data);
			else if (Obj.Type == AutoTypes::UNSIGNED)
				Out << ASUNSIGNED(Obj.Data);
			else if (Obj.Type == AutoTypes::STRING)
				Out << ASSTRING(Obj.Data);
			return Out;
		}
		~Auto()
		{
			delete this->Data;
			this->Type = AutoTypes::EMPTY;
			this->Const = false;
		}
	};
}
#endif