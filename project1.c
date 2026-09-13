#include <stdio.h>
#include <stdlib.h>



struct Item{
	int Id;
	float price;
	int quantity;
};

struct Item* addItem(struct Item *inventory, int *currentSize, int *capacity){
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
	scanf("%d", &inventory[*currentSize].quantity);


	(*currentSize)++;
	return inventory;
}

float calculateTotalValue(const struct Item *inventory, int size){
	//Computes the total financial value of all items combined
	float total = 0.0f;
	for(int i = 0; i < size; i++){
		total += inventory[i].price * inventory[i].quantity;
	}
	return total;
}

int findMostExpensive(const struct Item *inventory, int size){
	//Returns the index of the item with the highest price
	int maxIndx = 0;
	int max;

	for(int i = 0; i < size; i++){
		max = inventory[maxIndx].price;
		if(inventory[i].price > max){
			maxIndx = i;
		}
	}
	return maxIndx;
}

void freeInventory(struct Item *inventory){
	//Safely releases all heap memory
	free(inventory);
}

int main(void){
	//implementing all the functions
	struct Item *inventory = NULL;
	int currentSize = 0;
	int capacity = 0;
	int choice;


	do{
		printf("\n-----Inventory Menu-----\n");
		printf("1. Add Item\n");
		printf("2. View Inventory Report\n");
		printf("3. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);

		if(choice == 1){
			inventory = addItem(inventory, &currentSize, &capacity);
		}else if(choice == 2){
			if(currentSize == 0){
				printf("Inventory is currently empty.\n");
			}else{
				float totalValue = calculateTotalValue(inventory, currentSize);
				int maxIndex = findMostExpensive(inventory,currentSize);

				printf("\n--- Report ---\n");
				printf("Total Inventory Value $%.2f\n", totalValue);
				printf("Most Expensive Item -> ID: %d | Price: $%.2f | Qty: %d\n", inventory[maxIndex].Id, inventory[maxIndex].price, inventory[maxIndex].quantity);

			}
		}
	}while(choice != 3);

	freeInventory(inventory);
	inventory = NULL;
	printf("Memory freed successfully. Exiting program.\n");

	return 0;
}


