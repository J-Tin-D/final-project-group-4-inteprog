#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

//HOW TO MERGE?


bool isDigitsPrice(const string& str) {
    for (char ch : str) {
        if (isalpha(ch) && ch != '.') {
            return false;
        }
    }
    return true;
}

float exceptionHandlePrice(){
	bool isValid = false;
	string input;
	float digit;
	while(!isValid){

		try{
		getline(cin, input);
		if(!isDigitsPrice(input)){
			throw (42);
		}
        digit = stof(input);
        isValid = true;
		}	
		
		
		catch (const int& errorNum){
			cin.clear();
			cout<<"Error: Please Only Enter a Valid Number."<<endl;
			cout<<"Input: ";
		}
		catch (invalid_argument&) {
                        cout << "Invalid input. Please enter a number." << endl;
                        cin.clear();
                        		cout<<"Input: ";
     	}
      catch (out_of_range&) {
    	cerr << "Input too large." << endl;
    	cin.clear();
    			cout<<"Input: ";
    }
}
	return digit;
}

bool isDigits(const string& str) {
    for (char ch : str) {
        if (!isdigit(ch)) {
            return false;
        }
    }
    return true;
}


bool isString(const string& name) {	
    for (char ch : name) {
        if (ch == ' ') {
            return false;
        }
    }
    return !name.empty();
}


string capital(string input){
    string _input;
    
    for (int i = 0; i < input.length(); i++)
        input[i] = toupper(input[i]);

    return input;
}


int exceptionHandle(){
	bool isValid = false;
	int digit;
	string input;
	while(!isValid){

	
		try{
		getline(cin,input);
		if(!isDigits(input)){
			throw (42);
		}
        digit = stoi(input); 
        isValid = true;
		}	
		
		
		catch (const int& errorNum){
			cin.clear();
			cout<<"Error: Please Only Enter a Valid Number."<<endl;
			cout<<"Input: ";
		}
		catch (invalid_argument&) {
                        cout << "Invalid input. Please enter a number." << endl;
                        cin.clear();
                        		cout<<"Input: ";
     	}
      catch (out_of_range&) {
    	cerr << "Input too large." << endl;
    	cin.clear();
    			cout<<"Input: ";
    }
	}
	
	return digit;
}

class Items{
    private:
        string name;
        string id;
        int quantity = 0;
        //NEW CODE START - ITEM ATTRIBUTES
        string type;
        double price;
        string category;
        //NEW CODE END 
    public:    
        // NEW CODE START - UPDATED CONSTRUCTOR
        Items(string name_, string id_, int quantity_, string type_ = "N/A", double price_ = 0.0, string category_ = "N/A"): 
            name(name_), id(id_), quantity(quantity_), type(type_), price(price_), category(category_){}
        //NEW CODE END 
        
        string getName(){    return name;    }
        string getID(){        return id;    }
        int getQuantity(){    return quantity;}
        
        // NEW CODE START - ITEM GETTERS/SETTERS
        string getType(){    return type; }
        double getPrice(){    return price; }
        string getCategory(){ return category; }
        void setPrice(double p) { price = p; }
        void setType(string t) { type = t; }
        void setCategory(string c) { category = c; }
        //NEW CODE END 

        void setQuantity(int x){
            quantity = x;
        }
        
        
};

class Inventory{
    private: 
        int count = 0;
        Items* items[100];
        Inventory(): count(0) {}
        Inventory(const Inventory&) = delete; 
    public: 
        static Inventory& getInstance(){
            static Inventory instance;
            return instance;
        }
        
        int getCount(){
            return count;
        }
        
        
        
        bool isDuplicateId(string input){
            for(int i=0;i<count;i++){
                if(input == items[i]->getID());
                    return true;
            }
            return false;
        }
        
        
        // NEW CODE START - UPDATED ADDITEM
        void addItem(string name, string id, int quantity, string type = "N/A", double price = 0.0, string category = "N/A"){
            Items* item = new Items(name,id,quantity,type,price,category);
            items[count++] = item;
            cout<<"Item Added Successfully."<<endl;
        }
        //NEW CODE END 
        
        // Original addItem
        /*void addItem(string name, string id, int quantity){
            Items* item = new Items(name,id,quantity);
            items[count++] = item;
            cout<<"Item Added Successfully."<<endl;
        }*/
        
        void listItem(){
            cout<<"INVENTORY LIST"<<endl;
            cout<<"=================================="<<endl;
            cout<<"Name\t\tID\t\tQuantity\t\tPrice\t\tType\t\tCategory"<<endl;
            for(int i=0;i<count;i++){
                cout<<items[i]->getName()<<"\t\t"<<items[i]->getID()<<"\t\t"<<items[i]->getQuantity()<<"\t\t\t"<<items[i]->getPrice()<<"\t\t"
				<<items[i]->getType()<<"\t\t"<<items[i]->getCategory()<<endl;
            }
        }

        void deleteItem(string input){
            string key = input;    
            
            if(count == 0){
                cout<<"No Items On Inventory"<<endl;
                return;
            }
            
            for(int i = 0;i<count;i++){
                if(key == items[i]->getID()){
                    delete items[i];
                    count-=1;
                    cout<<"Item Successfully Deleted."<<endl;
                    return;
                }
            }    
            cout<<"Item Not Found"<<endl;    
        }
                
        void removeItem(string input){
        	int quant;
        	string name;
            string key = input;
            if(count == 0){
                cout<<"No Items on inventory"<<endl;
                return;
            }
            
            cout<<"Remove/Buy Item: ";
            for(int i=0;i<count;i++){
                if(key == items[i]->getID()){
                    string input;
                    cout<<"Enter Quantity of "<<items[i]->getName()<<" To Remove: ";
                    quant = exceptionHandle();
                    bool valid =  false;
                
                    while(quant > items[i]->getQuantity()){
                        cout<<"Error: Request Exceeds Current Quantity ["<<quant<<"/"<<items[i]->getQuantity()<<"]"<<endl;
                        cout<<"New Input: ";
                        quant = exceptionHandle();
                    }
            
                    
                }
                items[i]->setQuantity(items[i]->getQuantity()-quant);
                name = items[i]->getName();
            }
            cout<<quant<<" Removed."<<endl;
            return;
        }
        
        void addQuantity(string input){
        	int num;
            string key = input;
            string input_;
            for(int i=0;i<count;i++){
                if(key == items[i]->getID()){
                    cout<<"Enter Quantity of "<<items[i]->getName()<<" to Add"<<endl;
                    int quant = exceptionHandle();
                    num = quant;
                    items[i]->setQuantity(items[i]->getQuantity()+quant);
                }
            }
            cout<<num<<" items added."<<endl;
        }
            
            
        void initializeInventory(){
            string name;
            string id;
            int quantity;
            string category;
            string type;
            float price;
            string text;
            int number;
            string text_[100][100];
            ifstream ReadFile("DoNotOpen.txt");
            getline(ReadFile,text);
            
            try{
                number = stoi(text);
            }
            catch(invalid_argument&){
                
            }
            count = number;        
            
            
            for(int i=0;i<count;i++){
                for(int x=0;x<6;x++){
                    getline(ReadFile,text);
                    text_[x][i] = text;    
                    try{
                        number = stoi(text_[2][i]);
                    }
                    catch(invalid_argument&){
                    }
                    try{price = stof(text_[4][i]);
					}
					catch(invalid_argument&){
					}
                    name = text_[0][i];
                    id = text_[1][i];
                    quantity = number;
                    type = text_[3][i];
                    category = text_[5][i];
                }

                Items* item = new Items(name,id,quantity,type,price,category);
                items[i] = item;
            }
        }
        
        void saveInventory(){
            ofstream WriteFile("DoNotOpen.txt");
            
            WriteFile<<count<<endl;
            
            for(int i=0;i<count;i++){
                WriteFile<<items[i]->getName()<<endl;
                WriteFile<<items[i]->getID()<<endl;
                WriteFile<<items[i]->getQuantity()<<endl;
                WriteFile<<items[i]->getType()<<endl;
                WriteFile<<items[i]->getPrice()<<endl;
                WriteFile<<items[i]->getCategory()<<endl;
            }
            
            WriteFile.close();
        }
        
        // NEW CODE START - SEARCH FUNCTION
        void searchById(const string& id) {
            cout << "SEARCH RESULTS" << endl;
            cout << "==================================" << endl;
            cout << "Name\tID\tQuantity\tType\tPrice\tCategory" << endl;
            bool found = false;
            for(int i = 0; i < count; i++) {
                if(items[i]->getID() == id) {
                    cout << items[i]->getName() << "\t" 
                         << items[i]->getID() << "\t" 
                         << items[i]->getQuantity() << "\t"
                         << items[i]->getType() << "\t"
                         << items[i]->getPrice() << "\t"
                         << items[i]->getCategory() << endl;
                    found = true;
                    break;
                }
            }
            if(!found) {
                cout << "No item found with ID: " << id << endl;
            }
        }
        //NEW CODE END
        
        // NEW CODE START - SORT FUNCTION
        void sortItems(int sortOption) {
            for(int i = 0; i < count-1; i++) {
                for(int j = 0; j < count-i-1; j++) {
                    bool shouldSwap = false;
                    switch(sortOption) {
                        case 1: shouldSwap = items[j]->getType() > items[j+1]->getType(); break;
                        case 2: shouldSwap = items[j]->getPrice() > items[j+1]->getPrice(); break;
                        case 3: shouldSwap = items[j]->getCategory() > items[j+1]->getCategory(); break;
                        case 4: shouldSwap = items[j]->getQuantity() > items[j+1]->getQuantity(); break;
                    }
                    
                    if(shouldSwap) {
                        Items* temp = items[j];
                        items[j] = items[j+1];
                        items[j+1] = temp;
                    }
                }
            }
		           
            cout << "SORTED INVENTORY" << endl;
            cout << "==================================" << endl;
            cout << "Name\t\tID\t\tQuantity\t\tType\t\tPrice\t\tCategory" << endl;
            for(int i = 0; i < count; i++) {
                cout << items[i]->getName() << "\t\t" 
                     << items[i]->getID() << "\t\t" 
                     << items[i]->getQuantity() << "\t\t"
                     << items[i]->getType() << "\t\t"
                     << items[i]->getPrice() << "\t\t"
                     << items[i]->getCategory() << endl;
            }
        }
        //NEW CODE END
        
        
        void printReceipt(){
            time_t timestamp;
            time(&timestamp);
            struct tm * myTime = localtime(&timestamp);    
            
            ofstream Record("Records.txt");
            
            Record << "\tINVENTORY RECORDS "<<endl;
            Record <<asctime(myTime)<<endl;
            Record << "=================================="<<endl;
            Record << "Item\t\tID\t\tQuantity\t\tPrice\t\tType\t\tCategory"<<endl;
            for(int i=0;i<count;i++){
                Record<<items[i]->getName()<<"\t\t"<<items[i]->getID()<<"\t\t"<<items[i]->getQuantity()<<"\t\t\t"<<items[i]->getPrice()<<"\t\t"<<items[i]->getType()<<"\t\t"
				<<items[i]->getCategory()<<endl;
            }
        }    
        
    string setID(){
    bool valid = false;
    string input;
    cout<<"Item ID: ";
    while(!valid)
    {
        getline(cin, input);
            for(int i=0;i<count;i++){
    		if(items[i]->getID() == input){
    			cout<<"Error: Duplicate ID. Try Again: ";
    			getline(cin,input);
    		 	continue;
			}
		}
        valid = isString(input);
        if(valid == false)
            cout<<"Input Error. No Spaces Allowed. Try Again: ";
    }
    
    input = capital(input);
    return input;
}

};

Inventory& inventory = Inventory::getInstance();

string setName(){
    bool valid = false;
    string input;
    cout<<"Item Name: ";
    while(!valid)
    {
        getline(cin, input);
        valid = isString(input);
        if(valid == false)
            cout<<"Input Error. No Spaces Allowed. Try Again: ";
    }
    input = capital(input);
    return input;
}



void searchControl(){
	cout << "Enter ID to search: ";
		string searchId;
		getline(cin, searchId);
		inventory.searchById(capital(searchId));
}

void swapControl(){
	cout << "Sort by:" << endl;
		cout << "[1] Type" << endl;
		cout << "[2] Price" << endl;
		cout << "[3] Category" << endl;
		cout << "[4] Stock Amount" << endl;
		cout << "Input: ";
		int sortOption;
		sortOption = exceptionHandle();
		if(sortOption >= 1 && sortOption <= 4) {
			inventory.sortItems(sortOption);
		} else {
			cout << "Invalid sort option!" << endl;
		}
}

int setQuantity(){
    string input;
    int quant;
    cout<<"Quantity: ";
    quant = exceptionHandle();
    return quant;
}

//NEW CODE START - UPDATED READYITEM
void readyItem(){
    cout<<"Add Item"<<endl;
    string name = setName();
    string id = inventory.setID();
    int quantity = setQuantity();
    
    string type, category;
    double price;
    
    cout<<"Item Type: ";
    getline(cin, type);
    cout<<"Item Price: ";
    price = exceptionHandlePrice();
    cout<<"Item Category: ";
    getline(cin, category);
    
    inventory.addItem(name, id, quantity, type, price, category);
}



void deleteConfirm(){
    string input;
    string input_;
    cout<<"Enter ID of Item to Remove: ";
    getline(cin,input);
    cout<<"Are you Sure you want to Delete This Item?[Y/N]: ";
    getline(cin,input_);
    input_ = capital(input_);
    if(input_ == "Y" || input_ == "N"){
        if(input_ == "Y"){
            inventory.deleteItem(input);
        }
        else{
            cout<<"Deletion Cancelled."<<endl;
            return;
        }
    }
}