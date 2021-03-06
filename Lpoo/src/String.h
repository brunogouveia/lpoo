#include <stdlib.h>
#include <new>
#include <stdio.h>
#include <iostream>

class StringData {
	private:
		friend class String;
		int refCount;
		int len;
		int maxLen;
		~StringData() {
		}
		StringData() {
			len = 0;
			refCount = 1;
		}
		StringData(const char * string) {
			char * data = buffer();

			len = 0;
			while (string[len] != '\0' && len < (maxLen - 1)) {
				data[len] = string[len];
				len++;
			}
			data[len] = '\0';
			refCount = 1;
		}
		char* buffer() {
			return reinterpret_cast<char*>(reinterpret_cast<char*>(this) + sizeof(StringData));
		}

	public:
		void* operator new(size_t size, int maxLen) {
			/*
			 aloca espaço na memória para o objeto da classe StringData, além do espaço para  (len + 1),
			 que contém a própria string e  o ‘ \0’
			 */
			StringData * obj = reinterpret_cast<StringData*>(::operator new(size + round4(maxLen + 1)));
			obj->maxLen = round4(maxLen + 1);
			return obj;
			//return ::operator new(size + round4(maxLen + 1));
			/*
			 Usando o operador new agora:
			 new (len) StringData( “Args” )
			 */
		}
		static int round4(int len) {
			return ((((int) (len / 4)) + 1) * 4);
		}

		/*
		 Quando se sobrecarrega o operador new, deve-se sobrecarregar o operador delete, contendo parametros similares. Isso é necessário pois, caso haja algum problema durante o new, um delete será chamado usando os mesmos parametros
		 */
		void operator delete(void* obj) {
			::operator delete(obj); //nome qualificado por causa do operador de escopo (:: )
		}
		void operator delete(void* obj, int size) throw () {
			::operator delete(obj); //nome qualificado por causa do operador de escopo (:: )
		}
};

class String {
	private:
		StringData * data;

		String(StringData * data) {
			this->data = data;
		}
	public:
		String() {
			data = NULL;
		}
		String(const String&);
		String(const char *);
		~String();
		int length() const;
		int compare(const String&) const;
		int compare(const char*) const;
		String& operator =(const String&);
		String& operator =(const char *);
		bool operator ==(const String&) const;
		bool operator ==(const char*) const;
		String& operator +(const String&) const;
		String& operator +(const char*) const;
		String& operator +=(const String&);
		String& operator +=(const char*);
		bool operator <(const String&)const;
		bool operator <(const char*)const;
		bool operator >(const String&)const;
		bool operator >(const char*)const;
		String& toLower();
		String& toUpper();
		char operator [ ](int) const;
		char operator [ ](int);
		void print() const;
		char * const toChar() const;
};
