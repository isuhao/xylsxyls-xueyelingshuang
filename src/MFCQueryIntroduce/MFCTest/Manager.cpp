#include <SDKDDKVer.h>
#include "Manager.h"
#include "Collect.h"
#include "ErrorInfo.h"
#include "Storage.h"

void Manager::SearchInfo(HWND hwnd, Search* search){
	Collect::GetSearchInfo(search, hwnd);
}

vector<Person> Manager::Find(const Search& search){
	return Storage::FindFromtxt(search);
}

void Manager::ShowDlg(vector<Person> vecPerson){

}

void Manager::ShowError(int error){
	AfxMessageBox(errorInfo.storage[error].toValue<string>().c_str());
}

void Manager::ShowPerson(HWND hwnd, Person* person){
    Storage::GetFromtxt(person);
    Collect::ShowPerson(person, hwnd);
}

void Manager::SavePerson(Person* person){
    Storage::SaveTotxt(person);
}