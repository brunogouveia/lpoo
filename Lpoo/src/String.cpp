/*
 * String.cpp
 *
 *  Created on: 04/03/2013
 *      Author: bruno_gouveia
 */
#include "String.h"
#include <ctype.h>
#include <stdio.h>

String::String(const char * string) {
	int stringLen = 0;

	while (string[stringLen] != '\0')
		stringLen++;

	data = new (stringLen) StringData(string);
}

String::String(const String& string) {
	/*O construtor de cópia só referencia a mesma string*/
	data = string.data;
	string.data->refCount++;
}
String::~String() {
	if (data != NULL) {
		this->data->refCount--;
		if (this->data->refCount == 0)
			delete data;
	}
}

int String::length() const {
	return (data == NULL) ? 0 : data->len;
}

int String::compare(const String& string) const {

	int minLength = (length() < string.length()) ? length() : string.length();

	for (int i = 0; i < minLength; i++)
		if ((*this)[i] < string[i])
			return -1;
		else if ((*this)[i] > string[i])
			return 1;

	if (length() < string.length())
		return -1;
	else if (length() > string.length())
		return 1;
	else
		return 0;

}

int String::compare(const char * string) const {

	int stringLength = 0;

	while (string[stringLength] != '\0')
		stringLength++;

	int minLength = (length() < stringLength) ? length() : stringLength;

	for (int i = 0; i < minLength; i++)
		if ((*this)[i] < string[i])
			return -1;
		else if ((*this)[i] > string[i])
			return 1;

	if (length() < stringLength)
		return -1;
	else if (length() > stringLength)
		return 1;
	else
		return 0;

}

String& String::operator=(const String& string) {
	if (data != NULL) {
		data->refCount--;
		if (this->data->refCount == 0)
			delete data;
	}
	data = string.data;
	string.data->refCount++;
	return *this;
}

String& String::operator=(const char * string) {
	if (data != NULL) {
		data->refCount--;
		if (this->data->refCount == 0) {
			delete data;
		}
	}

	int stringLen = 0;
	while (string[stringLen] != '\0')
		stringLen++;

	data = new (stringLen) StringData(string);
	return *this;
}

bool String::operator==(const String& string) const {

	if (length() == string.length()) {
		for (int i = 0; i < length(); i++)
			if (string[i] != (*this)[i])
				return false;
		return true;
	}
	return false;

}

bool String::operator==(const char* string) const {

	int stringLen = 0;

	while (string[stringLen] != '\0')
		stringLen++;

	if (length() == stringLen) {
		for (int i = 0; i < length(); i++)
			if (string[i] != (*this)[i])
				return false;
		return true;
	}
	return false;

}

String& String::operator+(const String& string) const {

	int i;
	StringData * data = new (string.length() + length()) StringData();
	String * nString = new String(data);
	char * dataBuffer = data->buffer();
	data->len = length() + string.length();
	/*O numero de referencias fica em 0, porque esse novo objeto será
	 * recebido por alguem, e o operador de atribuição incrementará
	 * o número de referencias ficando em 1.*/
	data->refCount = 0;

	for (i = 0; i < length(); i++)
		dataBuffer[i] = (*this)[i];

	for (; i < (length() + string.length()); i++)
		dataBuffer[i] = string[i - length()];
	dataBuffer[i] = '\0';

	return *nString;

}

String& String::operator+(const char* string) const {

	int stringLen = 0;

	while (string[stringLen] != '\0')
		stringLen++;

	int i;
	StringData * data = new (stringLen + length()) StringData();
	String * nString = new String(data);
	char * dataBuffer = data->buffer();
	data->len = length() + stringLen;
	/*O numero de referencias fica em 0, porque esse novo objeto será
	 * recebido por alguem, e o operador de atribuição incrementará
	 * o número de referencias ficando em 1.*/
	data->refCount = 0;

	for (i = 0; i < length(); i++)
		dataBuffer[i] = (*this)[i];

	for (; i < stringLen + length(); i++)
		dataBuffer[i] = string[i - length()];
	dataBuffer[i] = '\0';

	return *nString;

}

String& String::operator+=(const String& string) {
	*this = *this + string;
	return *this;
}
String& String::operator+=(const char* string) {
	*this = *this + string;
	return *this;
}

bool String::operator <(const String& string) const {
	return compare(string) < 0;
}
bool String::operator <(const char * string) const {
	return compare(string) < 0;
}

bool String::operator >(const String& string) const {
	return compare(string) > 0;
}
bool String::operator >(const char * string) const {
	return compare(string) > 0;
}

String& String::toLower() {
	for (int i = 0; i < length(); i++)
		(this->data->buffer())[i] = tolower((*this)[i]);
	return *this;
}
String& String::toUpper() {
	for (int i = 0; i < length(); i++)
		(this->data->buffer())[i] = toupper((*this)[i]);
	return *this;
}
char String::operator[](int i) const {
	return *(data->buffer() + i);
}
char String::operator[](int i) {
	return *(data->buffer() + i);
}

void String::print() const {
	if (data != NULL)
		printf("%s\n", data->buffer());
}

char * const String::toChar() const {
	return (data != NULL) ? data->buffer() : NULL;
}
