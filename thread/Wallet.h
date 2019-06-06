#pragma once
class Wallet
{
private:
	int m_money;
public:
	void addMoney(int amont);
	void operator()(int amont);
	int getMoney();
public:
	Wallet(int money = 0);
	~Wallet();
};

