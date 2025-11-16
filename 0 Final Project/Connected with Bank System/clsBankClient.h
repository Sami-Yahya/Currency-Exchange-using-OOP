#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
using namespace std;

class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
    bool _MarkForDelete = false;

    static clsBankClient _GetEmptyClientObject()
    {
        return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
    {
        vector<string> vClientData;
        vClientData = clsString::Split(Line, Seperator);

        return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
            vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));
    }

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
    {
        string stClientRecord = "";
        stClientRecord += Client.FirstName + Seperator;
        stClientRecord += Client.LastName + Seperator;
        stClientRecord += Client.Email + Seperator;
        stClientRecord += Client.Phone + Seperator;
        stClientRecord += Client.AccountNumber() + Seperator;
        stClientRecord += Client.PinCode + Seperator;
        stClientRecord += to_string(Client.AccountBalance);

        return stClientRecord;
    }

    static vector<clsBankClient> _LoadClientsDataFromFile()
    {
        vector <clsBankClient> vClients;

        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                vClients.push_back(Client);
            }

            MyFile.close();
        }

        return vClients;
    }

    static void _SaveClientsDataToFile(vector<clsBankClient> const & vClients)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out); //overwrite

        string DataLine;

        if (MyFile.is_open())
        {
            for (clsBankClient const &C : vClients)
            {
                if (C._MarkForDelete == false)
                {
                    DataLine = _ConvertClientObjectToLine(C);
                    MyFile << DataLine << endl;
                }
            }

            MyFile.close();
        }
    }

    void _Update()
    {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : vClients)
        {
            if (C.AccountNumber() == AccountNumber())
            {
                C = *this;
                break;
            }
        }

        _SaveClientsDataToFile(vClients);
    }

    void _AddNew()
    {
        _AddDataLineToFile(_ConvertClientObjectToLine(*this));
    }

    void _AddDataLineToFile(string DataLine)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::out | ios::app); //append mode

        if (MyFile.is_open())
        {
            MyFile << DataLine << endl;

            MyFile.close();
        }
    }

    string _PrepareTransferLogLine(double Amount, clsBankClient DestinationClient, string UserName, string Seperator = "#//#")
    {
        string TransferLog = "";
        TransferLog += clsDate::GetSystemDateTimeString() + Seperator;
        TransferLog += _AccountNumber + Seperator;
        TransferLog += DestinationClient.AccountNumber() + Seperator;
        TransferLog += to_string(Amount) + Seperator;
        TransferLog += to_string(_AccountBalance) + Seperator;
        TransferLog += to_string(DestinationClient.AccountBalance) + Seperator;
        TransferLog += UserName;

        return TransferLog;
    }

    void _RegisterTransferLog(double Amount, clsBankClient DestinationClient, string UserName)
    {
        string stDataLine = _PrepareTransferLogLine(Amount, DestinationClient, UserName);

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::out | ios::app); //append mode

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    string _PrepareTransactionHistoryLine(double Amount, string Seperator = "#//#")
    {
        string HistoryLine = "";
        HistoryLine += clsDate::GetSystemDateTimeString() + Seperator;
        HistoryLine += _AccountNumber + Seperator;
        HistoryLine += FullName() + Seperator;
        HistoryLine += to_string(Amount);

        return HistoryLine;
    }

    struct stTransferLogRecord;
    static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line, string Seperator = "#//#")
    {
        stTransferLogRecord TransferLogRecord;
        vector<string> vTransferDateLine = clsString::Split(Line, Seperator);

        TransferLogRecord.DateTime = vTransferDateLine[0];
        TransferLogRecord.sourceAccNum = vTransferDateLine[1];
        TransferLogRecord.destinAccNum = vTransferDateLine[2];
        TransferLogRecord.Amount = stod(vTransferDateLine[3]);
        TransferLogRecord.sourceBalance = stod(vTransferDateLine[4]);
        TransferLogRecord.destinBalance = stod(vTransferDateLine[5]);
        TransferLogRecord.UserName = vTransferDateLine[6];

        return TransferLogRecord;
    }

    struct stTransHistoryRecord;
    static stTransHistoryRecord _ConvertHistoryLineToRecord(string Line, string Seperator = "#//#")
    {
        stTransHistoryRecord TransactionHistoryRecord;
        vector<string> vHistoryDataLine = clsString::Split(Line, Seperator);

        TransactionHistoryRecord.DateTime = vHistoryDataLine[0];
        TransactionHistoryRecord.AccountNumber = vHistoryDataLine[1];
        TransactionHistoryRecord.FullName = vHistoryDataLine[2];
        TransactionHistoryRecord.Amount = stod(vHistoryDataLine[3]);

        return TransactionHistoryRecord;
    }

public:

	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

    bool IsEmpty()
    {
        return (_Mode == enMode::EmptyMode);
    }

    // Read Only Property
    string AccountNumber()
    {
        return _AccountNumber;
    }

    // Set & Get Properties
    void setPinCode(string PinCode)
    {
        _PinCode = PinCode;
    }

    string getPinCode()
    {
        return _PinCode;
    }

    __declspec(property(get = getPinCode, put = setPinCode)) string PinCode;

    void setAccountBalance(float AccountBalance)
    {
        _AccountBalance = AccountBalance;
    }

    float getAccountBalance()
    {
        return _AccountBalance;
    }

    __declspec(property(get = getAccountBalance, put = setAccountBalance)) float AccountBalance;


    /*
        No UI related code iside object.
    void Print()
    {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << FirstName;
        cout << "\nLastName    : " << LastName;
        cout << "\nFull Name   : " << FullName();
        cout << "\nEmail       : " << Email;
        cout << "\nPhone       : " << Phone;
        cout << "\nAcc. Number : " << _AccountNumber;
        cout << "\nPassword    : " << _PinCode;
        cout << "\nBalance     : " << _AccountBalance;
        cout << "\n___________________\n";
    }*/

    struct stTransferLogRecord
    {
        string DateTime;
        string sourceAccNum;
        string destinAccNum;
        double Amount;
        double sourceBalance;
        double destinBalance;
        string UserName;
    };

    struct stTransHistoryRecord
    {
        string DateTime;
        string AccountNumber;
        string FullName;
        double Amount = 0;
    };

    static clsBankClient Find(string AccountNumber)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static clsBankClient Find(string AccountNumber, string PinCode)
    {
        fstream MyFile;
        MyFile.open("Clients.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
                {
                    MyFile.close();
                    return Client;
                }
            }

            MyFile.close();
        }

        return _GetEmptyClientObject();
    }

    static bool IsClientExist(string AccountNumber)
    {
        clsBankClient Client1 = clsBankClient::Find(AccountNumber);

        return (!Client1.IsEmpty());
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

    enSaveResults Save()
    {
        switch (_Mode)
        {
        case enMode::EmptyMode:
        {
            return enSaveResults::svFaildEmptyObject;
        }
        case enMode::UpdateMode:
        {
            _Update();

            return enSaveResults::svSucceeded;
        }
        case enMode::AddNewMode:
        {
            //This will add new record to file or database
            if (clsBankClient::IsClientExist(_AccountNumber))
            {
                return enSaveResults::svFaildAccountNumberExists;
            }
            else
            {
                _AddNew();

                //We need to set the mode to update after add new
                _Mode = enMode::UpdateMode;

                return enSaveResults::svSucceeded;
            }
        }
        }
    }

    static clsBankClient GetAddNewClientObject(string AccountNumber)
    {
        return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
    }

    bool Delete()
    {
        vector<clsBankClient> _vClients = _LoadClientsDataFromFile();

        for (clsBankClient &C : _vClients)
        {
            if (C.AccountNumber() == _AccountNumber)
            {
                C._MarkForDelete = true;
                _SaveClientsDataToFile(_vClients);

                *this = _GetEmptyClientObject();
                return true;
            }
        }

        return false;
    }

    static vector<clsBankClient> GetClientsList()
    {
        return _LoadClientsDataFromFile();
    }

    static double GetTotalBalances()
    {
        vector<clsBankClient> vClients = _LoadClientsDataFromFile();
        double TotalBalances = 0;
        
        for (clsBankClient C : vClients)
        {
            TotalBalances += C.AccountBalance;
        }

        return TotalBalances;
    }

    void Deposit(double Amount)
    {
        _AccountBalance += Amount;
        Save();
    }

    /*void Withdraw(double Amount)
    {
        _AccountBalance -= Amount;
        Save();
    }*/

    bool Withdraw(double Amount)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            _AccountBalance -= Amount;
            Save();
            return true;
        }
    }

    bool Transfer(double Amount, clsBankClient &DestinationClient, string UserName)
    {
        if (Amount > _AccountBalance)
        {
            return false;
        }
        else
        {
            Withdraw(Amount);
            DestinationClient.Deposit(Amount);
            _RegisterTransferLog(Amount, DestinationClient, UserName);
            return true;
        }
    }

    void SaveToTransHistoy(double Amount)
    {
        string stDataLine = _PrepareTransactionHistoryLine(Amount);

        fstream MyFile;
        MyFile.open("TransactionsHistory.txt", ios::out | ios::app); //append mode

        if (MyFile.is_open())
        {
            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }

    static vector<stTransferLogRecord> GetTransferLogList()
    {
        vector<stTransferLogRecord> vTransferLog;

        fstream MyFile;
        MyFile.open("TransferLog.txt", ios::in); //read mode
        
        if (MyFile.is_open())
        {
            string Line;
            stTransferLogRecord TransferLogRecord;

            while (getline(MyFile, Line))
            {
                TransferLogRecord = _ConvertTransferLogLineToRecord(Line);

                vTransferLog.push_back(TransferLogRecord);
            }

            MyFile.close();
        }

        return vTransferLog;
    }

    static vector<stTransHistoryRecord> GetTransactionsHistoryList()
    {
        vector<stTransHistoryRecord> vHistory;

        fstream MyFile;
        MyFile.open("TransactionsHistory.txt", ios::in); //read Mode

        if (MyFile.is_open())
        {
            string Line;
            stTransHistoryRecord TransHistoryRecord;

            while (getline(MyFile, Line))
            {
                TransHistoryRecord = _ConvertHistoryLineToRecord(Line);

                vHistory.push_back(TransHistoryRecord);
            }

            MyFile.close();
        }

        return vHistory;
    }

};
