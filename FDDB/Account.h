#pragma once
#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
#include <string>
#include < ctime >
using namespace std;
namespace ManiAccount
{
	enum class  IDNames
	{
		EMPTY,
		READ_ONLY,
		VISITOR,
		USER,
		MANAGER,
		ADMINISTRATOR
	};
	class Account
	{
		IDNames Account_Identity;
		string Account_name;
		string Account_password;
		string Account_uniqueID;
		string Account_EntryCode;
		void Encrypt()
		{
			;
		}
		void GenerateUniID();
	public:
		Account() :Account_Identity(IDNames::EMPTY)
		{}
		void SignUp(string UserName, string UserPasW, IDNames UserIdentity = IDNames::USER);
		Account(IDNames inID, string inAccount, string inPassword)
		{
			SignUp(inAccount, inPassword, inID);
		}
		Account(Account& Other)
		{
			this->Account_name = Other.Account_name;
			this->Account_password = Other.Account_password;
		}
		void User_NameChange(string newUserName);
		void User_PasWChange(string newPassword);
		bool User_Login(Account& Uncheck);
		void Account_Delete(Account& Operator);
		void Identity_Upgrade();
		void Identity_Degrade();
		void Identity_Remove();
		bool Identity_Set(Account& Other, IDNames NewIdentity);
		void Identity_Change(IDNames NewIdentity);
		IDNames Identity_Get()
		{
			return this->Account_Identity;
		}
		bool operator == (Account& Uncheck)
		{
			User_Login(Uncheck);
		}
	};
	void Account::GenerateUniID()
	{
		time_t Temp = time(0);
		char* Time = new char[26];
		ctime_s(Time, 26, &Temp);
		unsigned int result = 0;
		for (int n = 26 - 13; n != 26; n++)
			result = 5 * result + abs(Time[n] - 48);
		Account_uniqueID = to_string(result);
	}
	void Account::SignUp(string UserName, string UserPasW, IDNames UserIdentity)
	{
		this->Account_Identity = UserIdentity;
		this->Account_name = UserName;
		this->Account_password = UserPasW;
		GenerateUniID();
		Encrypt();
	}
	void Account::User_NameChange(string newUserName)
	{
		this->Account_name = newUserName;
	}
	void Account::User_PasWChange(string newPassword)
	{
		this->Account_password = newPassword;
	}
	bool Account::User_Login(Account& Uncheck)
	{
		if (Uncheck.Account_name == this->Account_name && Uncheck.Account_password == this->Account_uniqueID)
			return true;
		else
			return false;
	}
	void Account::Account_Delete(Account& Operator)
	{
		if (Operator.Account_Identity == IDNames::ADMINISTRATOR)
		{
			this->Account_Identity = IDNames::EMPTY;
			this->Account_name.clear();
			this->Account_password.clear();
			this->Account_uniqueID.clear();
			this->Account_EntryCode.clear();
		}
	}
	void Account::Identity_Upgrade()
	{
		int Middle = static_cast<int>(Account_Identity) + 1;
		Account_Identity = static_cast<IDNames>(Middle);
	}
	void Account::Identity_Degrade()
	{
		int Middle = static_cast<int>(Account_Identity) - 1;
		Account_Identity = static_cast<IDNames>(Middle);
	}
	void Account::Identity_Remove()
	{
		this->Account_Identity = IDNames::EMPTY;
	}
	bool Account::Identity_Set(Account& Other, IDNames NewIdentity)
	{
		if (this->Account_Identity == IDNames::ADMINISTRATOR)
		{
			Other.Account_Identity = NewIdentity;
			return true;
		}
		else
			return false;
	}
	void Account::Identity_Change(IDNames NewIdentity)
	{
		this->Account_Identity = NewIdentity;
	}
}

#endif