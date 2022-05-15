#include <iostream>
using namespace std;

class User
{
private:
	string username;
	string password;
public:
	//constructors
	User()
	{
		username[0] = '\0';
		password[0] = '\0';
	}
	User(string newName, string newPassword)
	{
		username = newName;
		password = newPassword;
	}
	User(const User& newUser)
	{
		username = newUser.username;
		password = newUser.password;

	}
	//setters
	void setUsername(string newName)
	{
		username = newName;
	}
	void setPassword(string newPassword)
	{
		password = newPassword;
	}
	//getters
	string getUsername()
	{
		return username;
	}
	string getPassword()
	{
		return password;
	}
	// Print Function
};
class Passenger :public User
{
private:
	string passengerName;
	string nationality;
	long long int passportNo;
	int ticketsBooked;
	int* ticketId;
public:

	//Constructors
	Passenger()
	{
		passengerName[0] = '\0';
		nationality[0] = '\0';
		passportNo = 0;
		ticketsBooked = 0;
		ticketId = 0;
	}
	Passenger(string newName, string newPassword, string newPassengerName, string newNationality,
		long long int newPassportNo, int totaltickets, int* newticketid) : User(newName, newPassword)
	{
		passengerName = newPassengerName;
		nationality = newNationality;
		passportNo = newPassportNo;
		ticketsBooked = totaltickets;
		ticketId = new int[ticketsBooked];
		for (int i = 0; i < ticketsBooked; i++)
		{
			ticketId[i] = newticketid[i];
		}
	}
	Passenger(const User& newUser, const Passenger& newPassenger) :User(newUser)
	{
		passengerName = newPassenger.passengerName;
		nationality = newPassenger.nationality;
		passportNo = newPassenger.passportNo;
		ticketsBooked = newPassenger.ticketsBooked;
		ticketId = new int[ticketsBooked];
		for (int i = 0; i < ticketsBooked; i++)
		{
			ticketId[i] = newPassenger.ticketId[i];
		}
	}


	//Setters
	void SetPassengerName(string newPassengerName)
	{
		passengerName = newPassengerName;
	}
	void SetNationality(string newNationality)
	{
		nationality = newNationality;
	}
	void SetPassportNo(long long int newPassportNo)
	{
		passportNo = newPassportNo;
	}
	void SetTicketsBooked(int totaltickets)
	{
		ticketsBooked = totaltickets;
	}
	void SetTicketIds(int* newticketid)
	{
		ticketId = new int[ticketsBooked];
		for (int i = 0; i < ticketsBooked; i++)
		{
			ticketId[i] = newticketid[i];
		}
	}

	//Getters
	string GetPassengerName()
	{
		return passengerName;
	}
	string GetNationality()
	{
		return nationality;
	}
	long long int GetPassportNo()
	{
		return passportNo;
	}
	int GetTicketsBooked()
	{
		return ticketsBooked;
	}
	int* GetTicketIds()
	{
		return ticketId;
	}
};
class Admin : public User
{
private:
	string adminName;
public:

	//constructors
	Admin()
	{
		adminName[0] = '\0';

	}
	Admin(string newName, string newPassword, string newAdminName) :User(newName, newPassword)
	{
		adminName = newAdminName;
	}
	Admin(const User& newUser, const Admin& newAdmin) :User(newUser)
	{
		adminName = newAdmin.adminName;
	}
	//setter
	void SetAdminName(string newAdminName)
	{
		adminName = newAdminName;
	}

	//getter
	string GetAdminName()
	{
		return adminName;
	}
};
class Ticket
{
private:
	int ticketID;
	int passportNumber;
public:
	Ticket()
	{
		ticketID = 0;
		passportNumber = 0;
	}
	Ticket(int newID, int newPass)
	{
		ticketID = newID;
		passportNumber = newPass;
	}
	void setID(int newID)
	{
		ticketID = newID;
	}
	void setPassportNumber(int newPass)
	{
		passportNumber = newPass;
	}
	int getID()
	{
		return ticketID;
	}
	int getPassportNumber()
	{
		return passportNumber;
	}
};
class Date
{
public:
	int day;
	int month;
	int year;

	Date()
	{
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int newDay, int newMonth, int newYear)
	{
		day = newDay;
		month = newMonth;
		year = newYear;
	}
};
class Time
{
public:
	int hour;
	int minutes;
	int seconds;

	Time()
	{
		hour = 0;
		minutes = 0;
		seconds = 0;
	}
	Time(int newHours, int newMinutes, int newSeconds)
	{
		hour = newHours;
		minutes = newMinutes;
		seconds = newSeconds;
	}
};
class Airline
{
private:
	string airlineName;
	int airlineID;
public:
	Airline()
	{
		airlineName = '\0';
		airlineID = 0;
	}
	Airline(string newName, int newID)
	{
		airlineName = newName;
		airlineID = newID;
	}
	void setAirlineName(string newName)
	{
		airlineName = newName;
	}
	void setAirlineID(int newID)
	{
		airlineID = newID;
	}
	string getAirlineName()
	{
		return airlineName;
	}
	int getAirlineID()
	{
		return airlineID;
	}
};
class InternationalFlight :virtual public Airline 
{
private:
	string country;
public:
	InternationalFlight() : Airline()
	{
		country = '\0';
	}
	InternationalFlight(string newName, int newID, string newCountry = "Nothing set") : Airline(newName, newID)
	{
		country = newCountry;
	}
	void setCountry(string newCountry)
	{
		country = newCountry;
	}
	string getCountry()
	{
		return country;
	}
};
class LocalFlight : virtual public Airline 
{
private: 
	string city;
public:
	LocalFlight() : Airline()
	{
		city = '\0';
	}
	LocalFlight(string newName, int newID, string newCity = "Nothing set") : Airline(newName, newID)
	{
		city = newCity;
	}
	void setCity(string newCity)
	{
		city = newCity;
	}
	string getCity()
	{
		return city;
	}
};
class Plane : public InternationalFlight, public LocalFlight
{
private:
	Ticket* ticketArray;
	char statusOfFlight;	//O for ontime, D for delayed, M for Missed
	int availableTickets;
	int flightNumber;
	Time departureTime;
	Time arrivalTime;
	Date flightDate;
public:
	Plane()
	{
		ticketArray = NULL;
		statusOfFlight = '\0';
		availableTickets = 0;
		flightNumber = 0;
		flightDate.day = 0;
		flightDate.month = 0;
		flightDate.year = 0;
		departureTime.hour = 0;
		departureTime.minutes = 0;
		departureTime.seconds = 0;
		arrivalTime.hour = 0;
		arrivalTime.minutes = 0;
		arrivalTime.seconds = 0;
	}
	Plane(Ticket* newArr, char newStatus, int newTickets, int newFlightNumber, Time newDeptTime, Time newArrTime, Date newDate,string newName,
		int newID): InternationalFlight(newName, newID), LocalFlight(newName,newID)
	{
		ticketArray = newArr;
		statusOfFlight = newStatus;
		availableTickets = newTickets;
		flightNumber = newFlightNumber;
		flightDate.day = newDate.day;
		flightDate.month = newDate.month;
		flightDate.year = newDate.year;
		departureTime.hour = newDeptTime.hour;
		departureTime.minutes = newDeptTime.minutes;
		departureTime.seconds = newDeptTime.seconds;
		arrivalTime.hour = newArrTime.hour;
		arrivalTime.minutes = newArrTime.minutes;
		arrivalTime.seconds = newArrTime.seconds;
	}

	// Setters
	void setTicketArr(Ticket* newArr)
	{
		ticketArray = newArr;
	}
	void setStatusOfFlight(char newStatus)
	{
		statusOfFlight = newStatus;
	}
	void setAvailableTickets(int newAvailableTickets)
	{
		availableTickets = newAvailableTickets;
	}
	void setFlightNumber(int newFlight)
	{
		flightNumber = newFlight;
	}
	void setDepartureTime(Time newDeptTime)
	{
		departureTime.hour = newDeptTime.hour;
		departureTime.minutes = newDeptTime.minutes;
		departureTime.seconds = newDeptTime.seconds;
	}
	void setArrivalTime(Time newArrivalTime)
	{
		arrivalTime.hour = newArrivalTime.hour;
		arrivalTime.minutes = newArrivalTime.minutes;
		arrivalTime.seconds = newArrivalTime.seconds;
	}
	void setDate(Date newDate)
	{
		flightDate.day = newDate.day;
		flightDate.month = newDate.month;
		flightDate.year = newDate.year;
	}

	// Getters
	Ticket* getTickets()
	{
		return ticketArray;
	}
	char getStatusOfFlight()
	{
		return statusOfFlight;
	}
	int getAvailableTickets()
	{
		return availableTickets;
	}
	int getFlightNumber()
	{
		return flightNumber;
	}
	Time getDepartureTime()
	{
		return departureTime;
	}
	Time getArrivalTime()
	{
		return arrivalTime;
	}
	Date getDate()
	{
		return flightDate;
	}
};

int main()
{
	// Testing definitions
	Ticket* newArray = new Ticket[3];
	Ticket* new2Array;
	Time DeptTime, ArrTime;
	ArrTime.hour = 1;
	Date newDate;
	for (int counter = 0;counter < 3;counter++)
	{
		newArray[counter].setID(counter);
		newArray[counter].setPassportNumber(counter + 10);
	}
	Plane obj1(newArray,'O',15,500,DeptTime,ArrTime,newDate,"Turkish",300);
	new2Array = obj1.getTickets();
	for (int counter = 0;counter < 3;counter++)
	{
		cout << new2Array[counter].getID()<<"    "<<new2Array[counter].getPassportNumber() << endl;
	}
	cout << obj1.getAirlineID()<<"    " << obj1.getAirlineName() << endl;
	cout << obj1.getCity() << "     " << obj1.getCountry() << endl;
	cout << obj1.getAvailableTickets()<< endl;
	cout << obj1.getFlightNumber() << "   " << obj1.getStatusOfFlight() << endl;

	return 0;
}
