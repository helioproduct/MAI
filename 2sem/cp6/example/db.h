#ifndef _DB_H_
#define _DB_H_
#include <stdbool.h>
#include <stdio.h>

enum Gender : unsigned short { WOMAN=0, MAN };

struct Person {

	char name[50];
	char surname[50];
	enum Gender gender;
	unsigned short mark;

};


struct StorageContext {
	const char storagePath[50];
	FILE* fs;
};


/* CRUD */
bool insert(const struct Person* p); // Create
struct QueryResult select(); // Task
unsigned update(const struct Query* q, struct Person* newValues); // Update is optional
unsigned remove(const struct Query* q); // Delete

void openStorage();
void closeStorage();


// QueryStuff
enum Operator : unsigned short { LESS=0, LESS_E, GREAT, GREAT_E, EQUAL };

struct SimpleNumericCondition {
	enum Operator op;
	unsigned short value;
};

struct SimpleStringCondition {
	enum Operator op;
	char value[50]
};

struct Query {
	struct SimpleStringCondition* name; 
	struct SimpleStringCondition* surname;
	struct SimpleNumericCondition* gender; 
	struct SimpleNumericCondition* mark;
};

name = {LESS, 'NIKITA'}, mark={EQUAL, 4} surname={EQUAL, 'NIKITA'}

struct QueryResult {
	struct Person* data;
	unsigned length;
};


#endif