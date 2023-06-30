#include <bits/stdc++.h>`

#define scanlld(longvalue) scanf("%lld", &longvalue)
#define printlld(longvalue) printf("%lld\n", longvalue)

#define scanlf(longvalue) scanf("%lf", &longvalue)
#define printlf(longvalue) printf("%lf\n", longvalue)
#define scanc(letter) scanf("%c", &letter)
#define printc(letter) printf("%c", letter)

#define scans(name) scanf("%s", name)
#define prints(name) printf("%s", name)

#define printnewline printf("\n")

#define ll long long

#define printcase(indexing,ans) printf("Case %lld: %lld\n", indexing, ans)

#define pb(x) push_back(x)

#define bug printf("BUG\n")

using namespace std;

long long int flag;
ll signedin;
ll checked;
ll tick;
string username, password;
bool seat[32][13][25][20][3];
ll dest;

const std::string currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y at %X", &tstruct);

    return buf;
}

class log_in
{
public:

    static int usertotal;
    map < string, string > userid;

    void process()
    {
        userid.clear();

        fstream file;

        file.open("UserID.txt", ios :: in);

        while(!file.eof())
        {
            file >> username;
            file >> password;

            userid[username] = password;
        }

        file.close();


    }

    void signup()
    {
        cout << "Type Username: ";
        cin >> username;

        if(userid[username] == "")
        {
            cout << "Enter Password: ";
            cin >> password;
            userid[username] = password;
            cout << endl;

            fstream file;
            file.open("UserID.txt", ios :: app);
            file << endl << username << " " << password;
            file.close();
        }
        else
        {
            cout << "This Username is not available" << endl << endl;
        }

    }

	 void input()
	 {
	 	cout << "Enter Username: ";
	 	cin >> username;
	 	cout << "Enter Password: ";
	 	cin >> password;

	 	checked = 1;

	 	if(userid[username] == password)
	 	{
	 		flag = 1;
	 		signedin = 1;
	 	}
	 	else
	 	{
	 		flag = 0;
	 	}
	 }
};

class func: public log_in
{
	long long int day, months, year;
	long long int hour, minute;
	string destination;
	long long int i, j, k, l, m, n, o, p;
	long long int countseat;
	int totalseat;
public:

    void open()
    {
        fstream file;
        bool in;

        file.open("Seats.txt", ios :: in);

        for(i = 0; i < 32; i++)
        {
            for(j = 0; j < 13; j++)
            {
                for(k = 0; k < 25; k++)
                {
                    for(l = 0; l < 20; l++)
                    {
                        for(m = 0; m < 3; m++)
                        {
                            file >> in;
                            seat[i][j][k][l][m] = in;
                        }
                    }
                }
            }
        }

        file.close();
    }

	void getdate()
	{
		cout << "Enter Date:" << endl << "Day: ";
		cin >> day;
		cout << "Month: ";
		cin >> months;
		cout << "Year: ";
		cin >> year;
	}

	void getitme()
	{
		cout << "Enter Time: (hour): ";
		cin >> hour;
	}

	void getdest()
	{
		cout << "Enter Destination: ";
		cin >> destination;

		if(destination == "Rajshahi")
        {
            dest = 0;
        }
        else if(destination == "Dhaka")
        {
            dest = 1;
        }
        else if(destination == "Chittagong")
        {
            dest = 2;
        }
	}
	void seatsearch()
	{
	    countseat = 0;

		for(i = 0; i < 20; i++)
		{
			if(seat[day][months][hour][i][dest] == false)
			{
				countseat++;
			}
		}

		cout << "Total available seat for Destination: " << destination << " at " << hour << ":" << "00" << " is: " << countseat << endl;
	}

	void getseat()
	{
		int temp;

		cout << "Number of seat needed: ";
		cin >> totalseat;

		if(totalseat > countseat)
		{
			cout << "Not enough ticket." << endl;
			tick = 0;
		}
		else
        {
            tick = 1;
        }

		cout << "Availble seats are: ";
		temp = 0;

		for(i = 0; i < 20; i++)
		{
			if(seat[day][months][hour][i][dest] == false)
			{
				cout << i + 1;
				temp++;

				if(temp < totalseat && i != 19)
				{
					cout << ", ";
				}

				if(temp == totalseat)
				{
					break;
				}
			}
		}

		cout << "." << endl;
	}

	void print()
	{
		cout << "Press 1 to Confirm: ";
		cin >> j;

		if(j)
		{
		    cout << endl;
			cout << "Username: " << username << endl;

			cout << "Date: " << day << " / " << months << endl;

			cout << "Time: " << hour << " : " << "00" << endl;

			cout << "Bought seats are: ";
			long long int temp = 0;

			for(i = 0; i < 20; i++)
			{
				if(seat[day][months][hour][i][dest] == false)
				{
					cout << i + 1;
					temp++;

					seat[day][months][hour][i][dest] = true;

					if(temp < totalseat && i != 19)
					{
						cout << ", ";
					}

					if(temp == totalseat)
					{
						break;
					}
				}
			}

			cout << "." << endl;

			cout << "Price: " << totalseat * 450 << endl;

			cout << "Ticket buying time: " << currentDateTime() << endl;

			cout << endl;
		}
	}

	void close()
	{
	    ofstream file;

	    file.open("Seats.txt");

	    for(i = 0; i < 32; i++)
        {
            for(j = 0; j < 13; j++)
            {
                for(k = 0; k < 25; k++)
                {
                    for(l = 0; l < 20; l++)
                    {
                        for(m = 0; m < 3; m++)
                        if(seat[i][j][k][l][m])
                        {
                           file << "1" << endl;
                        }
                        else
                        {
                            file << "0" << endl;
                        }
                    }
                }
            }
        }

	    file.close();

	}
};

int main()
{
    long long int i, j, k, l, m, n, o;
    long long int testcase;
    long long int input, tag;

    log_in a;
    func d;

    a.process();
    d.open();

    while(1)
    {
        cout << "Press 1 for Sign Up and Press 2 for Sign In: ";
        cin >> tag;

        if(tag == 1)
        {
            signedin = 0;
            a.signup();
        }
        else
        {
            if(signedin == 1)
            {
                cout << "You are already signed in. If you want to sign out, press 1. Else press any key: " << endl;
                cin >> tag;
                if(tag == 1)
                {
                    signedin = 0;
                }

                cout << endl;
            }
            else
            {
                a.input();
            }


            if(flag && signedin == 1)
            {
                d.getdate();
                d.getitme();
                d.getdest();
                d.seatsearch();
                d.getseat();
                if(tick)
                {
                    d.print();
                    d.close();
                }
                else
                {
                    cout << endl;
                }
            }
            else if(checked == 1)
            {
                cout << "Sorry. Username and Password didn't match. Try Again." << endl << endl;
            }

        }
    }


    return 0;
}

