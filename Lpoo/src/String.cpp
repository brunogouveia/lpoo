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

	data = string.data;
	string.data->refCount++;
}
String::~String() {
	this->data->refCount--;
	if (this->data->refCount == 0)
		delete data;
}

String& String::operator=(const String string) {
	data->refCount--;
	if (this->data->refCount == 0)
		delete data;
	data = string.data;
	string.data->refCount++;
	return *this;
}

String& String::operator=(const char * string) {
	data->refCount--;
	if (this->data->refCount == 0)
		delete data;

	int stringLen = 0;
	while (string[stringLen] != '\0')
		stringLen++;

	data = new (stringLen) StringData(string);
	return *this;
}

int String::length() const {
	return data->len;
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

int String::compare(const String& string) const {

	int min = (length() < string.length()) ? length() : string.length();

	for (int i = 0; i < min; i++)
		if (string[i] < (*this)[i])
			return -1;
		else if (string[i] > (*this)[i])
			return 1;

	if (length() < string.length())
		return -1;
	else if (length() > string.length())
		return 1;
	else
		return 0;

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

int String::compare(const char* string) const {

	int stringLen = 0;

	while (string[stringLen] != '\0')
		stringLen++;

	int min = (length() < stringLen) ? length() : stringLen;

	for (int i = 0; i < min; i++)
		if (string[i] < (*this)[i])
			return -1;
		else if (string[i] > (*this)[i])
			return 1;

	if (length() < stringLen)
		return -1;
	else if (length() > stringLen)
		return 1;
	else
		return 0;

}

String& String::operator+(const String& string) const {

	int i;
	StringData * data = new (string.length() + length()) StringData();
	String * nString = new String(data);
	data->len = length() + string.length();
	data->refCount = 0;

	for (i = 0; i < length(); i++)
		(*nString)[i] = (*this)[i];

	for (; i < (length() + string.length()); i++)
		(*nString)[i] = string[i - length()];
	(*nString)[i] = '\0';

	return *nString;

}

String String::operator+(const char* string) const {

	int stringLen = 0;

	while (string[stringLen] != '\0')
		stringLen++;

	int i;
	StringData * data = new (stringLen + length()) StringData();
	String * nString = new String(data);
	data->len = length() + stringLen;
	data->refCount = 0;

	for (i = 0; i < length(); i++)
		(*nString)[i] = (*this)[i];

	for (; i < stringLen + length(); i++)
		(*nString)[i] = string[i - length()];
	(*nString)[i] = '\0';

	return *nString;

}

String String::operator+=(const String& string) {
	*this = *this + string;
	return *this;
}
String& String::operator+=(const char* string) {
	*this = *this + string;
	return *this;
}

bool String::operator <(const String& string) {
	return compare(string) < 0;
}
bool String::operator <(const char * string) {
	return compare(string) < 0;
}

bool String::operator >(const String& string) {
	return compare(string) > 0;
}
bool String::operator >(const char * string) {
	return compare(string) > 0;
}

String String::toLower() {
	for (int i = 0; i < length(); i++)
		(*this)[i] = tolower((*this)[i]);
	return *this;
}
String String::toUpper() {
	for (int i = 0; i < length(); i++)
		(*this)[i] = toupper((*this)[i]);
	return *this;
}
char String::operator[](int i) const {
	return *(data->buffer() + i);
}
char& String::operator[](int i) {
	return *(data->buffer() + i);
}

void String::print() const {
	printf("%s\n", data->buffer());
}
