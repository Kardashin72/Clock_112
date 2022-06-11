#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Clock_ {
private:
	int second;
	int minute;
	int hour;
public:
	//конструктор с параметрами по умолчанию
	Clock_(int h = 0, int m = 0, int s = 0) {
		setHour(h);
		setMinute(m);
		setSecond(s);
	}
	//сеттеры
	void setSecond(int s)
	{
		if (s >= 0 && s < 60)
		{
			second = s;
		}
		else
		{
			second = 0;
		}
	}
	void setMinute(int m)
	{
		if (m >= 0 && m < 60)
		{
			minute = m;
		}
		else
		{
			minute = 0;
		}
	}
	void setHour(int h)
	{
		if (h >= 0 && h < 24)
		{
			hour = h;
		}
		else
		{
			hour = 0;
		}
	}
	void setClock(int h, int m, int s)
	{
		setSecond(s);
		setMinute(m);
		setHour(h);
	}
	//геттеры
	int getSecond()
	{
		return second;
	}
	int getMinute()
	{
		return minute;
	}
	int getHour()
	{
		return hour;
	}
		
	void printClock() const
	{
		if (hour < 10)
		{
			cout << "0";
		}
		cout << hour << ":";
		if (minute < 10)
		{
			cout << "0";
		}
		cout << minute << ":";
		if (second < 10)
		{
			cout << "0";
		}
		cout << second;
	}
	void addSecond()
	{
		this->second++;
		if (this->second == 60)
		{
			this->second = 0;
			this->minute++;
			if (this->minute == 60)
			{
				this->minute = 0;
				this->hour++;
				if (this->hour == 24)
				{
					this->hour = 0;
				}
			}
		}
	}

	Clock_& operator++() {
		this->addSecond();
		return *this;
	}

	Clock_ operator++(int) {
		Clock_ tmp = *this;
		this->addSecond();
		return tmp;
	}

	Clock_& operator+=(const Clock_& cl) {
		this->hour += cl.hour;
		this->minute += cl.minute;
		this->second += cl.second;
		int time_s = this->hour * 3600 + this->minute * 60 + this->second;
		this->hour = (time_s / 3600) % 24;
		this->minute = (time_s % 3600) / 60;
		this->second = time_s % 3600 % 60;
		return *this;
	}

	Clock_& operator-=(const Clock_& cl) {
		this->hour -= cl.hour;
		this->minute -= cl.minute;
		this->second -= cl.second;
		int time_s = this->hour * 3600 + this->minute * 60 + this->second;
		this->hour = (time_s / 3600) % 24;
		this->minute = (time_s % 3600) / 60;
		this->second = time_s % 3600 % 60;
		return *this;
	}

	friend bool operator==(const Clock_& a, const Clock_& b);
	friend bool operator!=(const Clock_& a, const Clock_& b);
	friend bool operator>(const Clock_& a, const Clock_& b);
	friend bool operator<(const Clock_& a, const Clock_& b);
	friend ostream& operator<<(const ostream& out, const Clock_& cl);
	friend istream& operator>>(const ostream& in, Clock_& cl);


};

bool operator==(const Clock_& a, const Clock_& b)
{
	if (a.hour != b.hour)
		return false;
	if (a.minute != b.minute)
		return false;
	if (a.second != b.second)
		return false;

	return true;
}

bool operator!=(const Clock_& a, const Clock_& b)
{
	if (a.hour != b.hour)
		return true;
	if (a.minute != b.minute)
		return true;
	if (a.second != b.second)
		return true;

	return false;
}

bool operator>(const Clock_& a, const Clock_& b)
{
	if (a.hour > b.hour)
		return true;
	if (a.minute > b.minute)
		return true;
	if (a.second > b.second)
		return true;

	return false;
}

bool operator<(const Clock_& a, const Clock_& b)
{
	if (a.hour < b.hour)
		return true;
	if (a.minute < b.minute)
		return true;
	if (a.second < b.second)
		return true;

	return false;
}

ostream& operator<<(ostream& out, const Clock_& cl)
{
	cl.printClock();
	return out;

}

istream& operator>>(istream& in, Clock_& cl)
{
	int h, m, s;
	cout << "Enter the time (HH:MM:SS): " << endl;
	in >> h >> m >> s;
	cl.setClock(h, m, s);
	return in;
}

void main()
{
	Clock_ a(06, 59, 55);
	Clock_ a1;
	cin >> a1;


	while (1)
	{
		system("cls");
		cout << a1;
		a1++;
		Sleep(1000);
	}
}
	