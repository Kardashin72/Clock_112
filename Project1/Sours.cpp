#include <iostream>
#include <string>

using namespace std;

class Clock_ {
private:
	int second;
	int minute;
	int hour;
public:
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
	int hetHour()
	{
		return hour;
	}
		
	void printClock()
	{
		/*if (hour < 10)
		{
			cout << "0" << hour << ":" << minute << ":" << second << endl;
		}*/
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


};

void main()
{
	Clock_ a;
	a.setClock(24, 66, 66);
	a.printClock();
}