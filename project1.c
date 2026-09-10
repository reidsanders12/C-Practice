#include <stdio.h>

struct Item{
	int Id;
	float price;
	int quantity;
};

Item* addItem(Item *inventory, int *currentSize, int *capacity){
	//Adds a new item, resizes the heap if needed
	return inventory;
}

float calculateTotalValue(const Item *inventory, int size){
	//Computes the total financial value of all items combined
	return 0.0f;
}

int findMostExpensive(const Item *inventory, int size){
	//Returns the index of the item with the highest price
	return -1;
}

void freeInventory(Item *inventory){
	//Safely releases all heap memory
}

int main(void){
	//implementing all the functions
	return 0;
}


