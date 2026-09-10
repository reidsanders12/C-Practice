#include <stdio.h>

struct Item{
	int Id;
	float price;
	int quantity;
};

Item* addItem(Item *inventory, int *currentSize, int *capacity){
	//Adds a new item, resizes the heap if needed
	if(currentSize >= capacity){
		//doubles the capacity
		*capacity = (*capacity == 0) ? 2 : *capacity * 2;
		struct Item *temp = realloc(inventory, (*capacity) * sizeof(struct Item));
		if(temp == NULL){
			printf("Memory reallocation failed!\n");
			return inventory;
		}
	inventory = temp;
	}


	//Prompt the user for new item details
	printf("Enter Item ID: ");
	scanf("%d", &inventory[*currentSize].Id);

	printf("Enter Item Price: ");
	scanf("%f", &inventory[*currentSize].price);

	printf("Enter Item Quantity: ");
	scanf("%d", &inventory[*currentSize].price);


	(*currentSize)++;
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


