/*
 *  This file is distributed under the MIT License.
 *  See LICENSE file for details.
 */

#include "zetjsoncpp.h"

namespace zetjsoncpp{

	string intToString(int number){

	   std::stringstream ss;//create a stringstream
	   ss << number;//add number to the stream
	   return ss.str();//return a string with the contents of the stream
	}

	string floatToString(float number){

		char buff[100];
		sprintf(buff, "%f",number);
		string ss = buff;
	   return ss;//return a string with the contents of the stream
	}

	string toLower(const string & str){

		string ret = str;
		for(unsigned short l = 0; l < ret.size();l++)
			ret[l] = tolower(ret[l]);
		return ret;
	}

	bool endsWith(const string & fullString, const string & ending){
		if (fullString.length() >= ending.length()) {
			return (0 == fullString.compare (fullString.length() - ending.length(), ending.length(), ending));
		}

		return false;
	}


	bool isDigit(char c){
		return (('0' <= c) && (c<='9'));
	}

	bool isHexaDigit(char c){
		return ((('0' <= c) && (c<='9')) || ((tolower(c)<='a')&&(tolower(c)<='f')));
	}


	char *ADVANCE_DIGITS(char *aux_p){

		while(isDigit(*aux_p))	aux_p++;
		return aux_p;
	}

	char *ADVANCE_HEXADIGITS(char *aux_p){

		while(isHexaDigit(*aux_p))	aux_p++;
		return aux_p;
	}



	bool isEmpty(const string & str){
		return str.empty();
	}

	int isNumber(const string & test_str_number){
		bool isHexa=false;
		char *str = (char *)test_str_number.c_str();

		switch(*str){
		case '-': str++; // negative numbers ...
				   break;
		case '0':
				  if(tolower(*str+1)=='x')  {
					  isHexa = true;
					  str+=2;
				  }
				  break;
		default:
				break;
		};

		char *start_str = str; // saves position...
		if(isHexa) {
			str = ADVANCE_HEXADIGITS(str);
			if(str == start_str)
				return STRING_IS_INVALID_NUMBER;

			if(*str == ' ' || *str == 0) return STRING_IS_HEXA;
		}else{
			str = ADVANCE_DIGITS(str);
			if(str == start_str)
				return STRING_IS_INVALID_NUMBER;

			if(*str=='.') { // is candidate to double
				str++;
				str = ADVANCE_DIGITS(str);
				if(*str == ' ' || *str == 0)
					return STRING_IS_DOUBLE;

				return STRING_IS_INVALID_NUMBER;
			}

			if(*str == ' ' || *str == 0)
				return STRING_IS_INT;

		}

		return STRING_IS_INVALID_NUMBER;


	}


};
