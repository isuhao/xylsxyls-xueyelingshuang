#pragma once
#include "Person.h"
#include <afx.h>

class Collect{
public:
	static int GetPersonInfo(Person* person,HWND hwnd);
    static int GetQueryInfo(Person* person, HWND hwnd);
    static void ShowPerson(Person* person, HWND hwnd);
private:
    static int CheckName(Person* person);
    static int CheckBirth(Person* person);
    static int CheckSex(Person* person);
    static int CheckMarriage(Person* person);
    static int CheckEducation(Person* person);
};