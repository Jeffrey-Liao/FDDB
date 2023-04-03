#pragma once
#include <vector>
#include <string>
#include <fstream>
using namespace std;
namespace ManiCmd
{
	class Command
	{
		string Cmd;
		string Sht;
	public:
		Command(string Long, string Short)
		{
			Cmd = Long;
			Sht = Short;
		}
		string setCommand(string Long)
		{
			this->Cmd = Long;
		}
		string getCommand()
		{
			return Cmd;
		}
		string setShort(string Short)
		{
			this->Sht = Short;
		}
		string getShort()
		{
			return Sht;
		}
		void Clear()
		{
			Cmd.clear();
			Sht.clear();
		}
		const Command& operator = (string UnChecked)
		{
			this->Cmd = this->Sht = UnChecked;
			return *this;
		}
		const Command& operator =(Command& Obj)
		{
			this->Cmd = Obj.Cmd;
			this->Sht = Obj.Sht;
			return *this;
		}
		bool operator == (string Uncheck)
		{
			if (this->Cmd == Uncheck || this->Sht == Uncheck)
				return true;
			else
				return false;
		}
		bool operator==(Command& Obj)
		{
			if (this->Cmd == Obj.Cmd || this->Sht == Obj.Sht)
				return true;
			else
				return false;
		}
		friend istream& operator>>(istream& Obj, Command& ObjC)
		{
			Obj >> ObjC.Cmd >> ObjC.Sht;
			return Obj;
		}
		~Command()
		{
			Cmd.clear();
			Sht.clear();
		}
	};
	class CmdCenter
	{
		vector<Command> Commands;
	public:
		CmdCenter() {}
		void NewCommand(Command NewCommand);
		void LoadCommand(string Address);
		int  FindCommand(string Uncheck);
		int  FindCommand(Command Uncheck);
	};
	void CmdCenter::NewCommand(Command NewCommand)
	{
		Commands.push_back(NewCommand);
	}
	void CmdCenter::LoadCommand(string Address)
	{
		Address += ".txt";
		Command Temp("", "");
		fstream File;
		File.open(Address, ios::in);
		for (; !File.eof();)
			File >> Temp;
		File.close();
	}
	int CmdCenter::FindCommand(string Uncheck)
	{
		for (int n = 0; n != Commands.size(); n++)
		{
			if (Commands[n] == Uncheck)
				return n;
		}
		return -1;
	}
	int CmdCenter::FindCommand(Command Uncheck)
	{
		for (int n = 0; n != Commands.size(); n++)
		{
			if (Commands[n] == Uncheck)
				return n;
		}
		return -1;
	}
}
