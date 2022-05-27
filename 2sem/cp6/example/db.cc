#include "db.h"
#include <stdio.h>

StorageContext context = {
	.storagePath="storage.bin",
	.fs=fopen("storage.bin", "ab")
};


bool checkStrCondition(struct SimpleStringCondition* cond, const char* value)
{
	if(!cond)
	{
		return false;
	}

	switch(cond->op)
	{
		case LESS:
		case LESS_E:
		case GREAT:
		case GREAT_E:
		case EQUAL:

	}
}


bool checkIntCondition(struct SimpleIntCondition* cond, unsigned short value)
{
	if(!cond)
	{
		return false;
	}

	switch(cond->op)
	{
		case LESS:
		case LESS_E:
		case GREAT:
		case GREAT_E:
		case EQUAL:	
	}
}


unsigned filterByCondition(struct Person* buffer, unsigned bufferSize, struct Query* q)
{

	unsigned rawsCount = bufferSize;
	for(unsigned i = 0; i < bufferSize; ++i) {

		if(!checkStrCondition(q->name, buffer[i].name))
		{
			continue;
		}
		if(!checkStrCondition(q->surname, buffer[i].surname))
		{
			continue;
		}
		if(!checkIntCondition(q->gender, buffer[i].gender))
		{
			continue;
		}
		if(!checkIntCondition(q->mark, buffer[i].mark))
		{
			continue;
		}
		// remove from buffer
		--rawsCount;
	}
	return rawsCount;

}


bool insert(const struct Person* p)
{
	return fwrite(p, sizeof(struct Person), 1, context.fs) == 1;
}

// query ex: name="Nikta" mark=4
// name=, <, >, <=, >=
// surname=, <, >, <=, >=
// gender=, <, >, <=, >=
// mark=, <, >, <=, >=
unsigned remove(const struct Query* q)
{
	closeStorage();
	FILE* f = fopen(context.storagePath, "rb");
	FILE* tempStorage = fopen("temp.bin", "ab");

	unsigned bufferSize = 100;
	unsigned recordsRead = 0;
	struct QueryResult q = {};
	struct Person buffer[bufferSize];

	while((recordsRead = fread(&buffer, sizeof(struct Person), bufferSize, f)) > 0)
	{

		unsigned rawsCount = filterByCondition(&buffer, bufferSize, q);
		fwrite(buffer, sizeof(struct Person), rawsCount, tempStorage);

	}

	fclose(f);
	fclose(tempStorage);
	rename("temp.bin", context.storagePath);
	openStorage();
}


struct QueryResult select()
{
	closeStorage();
	FILE* f = fopen(context.storagePath, "rb");
	struct QueryResult qr;

	/*
		task here
	*/

	fclose(f);
	openStorage();
	return qr;
}


void openStorage()
{
	context.fs = fopen("storage.bin", "ab");
}

void closeStorage()
{
	fclose(context.fs);
	context.fs = NULL;
}