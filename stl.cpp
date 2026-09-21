#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <ctime>
#include <unordered_set>
#include <unordered_map>

using namespace std;

struct product
{
	int productID;
	string name;
	string category;
};

struct order{
	int orderID;
	int productID;
	int quantity;
	string customerID;	
	time_t orderdate;
};

int main()
{
	vector<product> products = {
		{101, "laptop", "electronics"},
		{102, "smartphone", "electronics"},
		{103, "coffe_maker", "Home_item"},
		{104, "blender", "Home_item"},
		{105, "desk_lamp", "Home"}
	};
	
	deque<string> recentcustomers = {"C001", "C002", "C003"};
	recentcustomers.push_back("C004");
	recentcustomers.push_back("C005");
	
	list<order> orderhistory;
	orderhistory.push_back({1, 101, 1, "C001", time(0)});
	orderhistory.push_back({2, 102, 2, "C002", time(0)});
	orderhistory.push_back({3, 103, 1, "C003", time(0)});
	
	set<string> categories;
	for(const auto &product : products){
		categories.insert(product.category);
	}
	
	map<int, int> productstocks = {
		{101, 30},
		{102, 30},
		{103, 40},
		{104, 50},
		{105, 100}
	};
	
	multimap<string, order> customerorders;
	for(const auto &ord : orderhistory){
		customerorders.insert({ord.customerID, ord});
	}
	
	unordered_map<string, string> customerdata = {
		{"C001", "Alice"},
		{"C002", "Bob"},
		{"C003", "Karan"},
		{"C004", "Darshan"},
		{"C005", "Dhruv"}
	};
	
	unordered_set<int> uniqueproductIDs;
	for(const auto &product : products)
	{
		uniqueproductIDs.insert(product.productID);
	}

	return 0;
}
