#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <ctime>
#include <fstream>


using namespace std;


char* Classical_Multiplication(char* num_1, char* num_2){
	char* result;
	int x = strlen(num_1);
	int y = strlen(num_2);
	int max_bit = 0;
	
	(x>y) ? max_bit = x : max_bit = y;
	
	result = new char [2*max_bit+1];
	int r = 2 * max_bit;
	result[r] = '\0';
	
	
	for(int i = 0; i < r; i++){
		result[i] = '0';
	}
	
	int a = abs(x-y);
	
	char carry = '0';
	for(int j = y-1; j >= 0; j--){
		if(num_2[j] == '1' ){
			for(int k = x-1; k >= 0; k--){
				
				if(result[k+j+1+a] == '0'){
					if( num_1[k] == '0'){
						if( carry == '0'){
							result[k+j+1+a] = '0';
							carry = '0';
						}
						else if( carry == '1'){
							result[k+j+1+a] = '1';
							carry = '0';
						}
					}

					else if( num_1[k] == '1'){
						if( carry == '0'){
							result[k+j+1+a] = '1';
							carry = '0';
						}
						else if( carry == '1'){
							result[k+j+1+a] = '0';
							carry = '1';
						}
					}
				}
				
				else if(result[k+j+1+a] == '1'){
					if( num_1[k] == '0'){
						if( carry == '0'){
							result[k+j+1+a] = '1';
							carry = '0';
						}
						else if( carry == '1'){
							result[k+j+1+a] = '0';
							carry = '1';
						}
					}
					
					else if( num_1[k] == '1'){
						if( carry == '0'){
							result[k+j+1+a] = '0';
							carry = '1';
						}
						else if( carry == '1'){
							result[k+j+1+a] = '1';
							carry = '1';
						}
					}
				}
			}
			if( carry == '1'){
				result[j+a] = '1';
			}
			carry = '0';
		}
	}
	
	return result;
}



char* shift_binary_string( char* str, int step = 1){
	int size = strlen(str);
	
	for(int i = 0; i < size; i++){
		if( i < size-step ){
			str[i] = str[i+step];
		}
		else {
			str[i] = '0';
		}
	}
	return str;
}


char* add_binary_strings( char* str, char* str2){
	int addend = strlen(str);
	int adder = strlen(str2);
	
	if( addend < adder ){
		cout << "ERROR :   Addend order is smaller than adder order..!!!\n\n";
		return '\0';
	}
	
	char carry = '0';

	for(int k = adder-1; k >= 0; k--){		
		if(str[k+addend-adder] == '0'){
			if( str2[k] == '0'){
				if( carry == '0'){
					str[k+addend-adder] = '0';
					carry = '0';
				}
				else if( carry == '1'){
					str[k+addend-adder] = '1';
					carry = '0';
				}
			}

			else if( str2[k] == '1'){
				if( carry == '0'){
					str[k+addend-adder] = '1';
					carry = '0';
				}
				else if( carry == '1'){
					str[k+addend-adder] = '0';
					carry = '1';
				}
			}
		}
		
		else if(str[k+addend-adder] == '1'){
			if( str2[k] == '0'){
				if( carry == '0'){
					str[k+addend-adder] = '1';
					carry = '0';
				}
				else if( carry == '1'){
					str[k+addend-adder] = '0';
					carry = '1';
				}
			}
			
			else if( str2[k] == '1'){
				if( carry == '0'){
					str[k+addend-adder] = '0';
					carry = '1';
				}
				else if( carry == '1'){
					str[k+addend-adder] = '1';
					carry = '1';
				}
			}
		}
	}
	
	if( carry == '1'){
		for(int m = addend-adder-1; m >= 0; m--){
			if(str[m] == '0'){
				str[m] = '1';
				break;
			}
			str[m] = '0';
		}
	}

	carry = '0';
	return str;
}



char* subtract_binary_strings( char* str, char* str2){
	int subtracted = strlen(str);
	int subtractor = strlen(str2);
	
	if( subtracted < subtractor ){
		cout << "ERROR :   subtracted order is smaller than subtractor order!!\n\n";
		return '\0';
	}
	
	char borrow = '0';

	for(int k = subtractor-1; k >= 0; k--){		
		if(str[k+subtracted-subtractor] == '0'){
			if( str2[k] == '0'){
				if( borrow == '0'){
					str[k+subtracted-subtractor] = '0';
					borrow = '0';
				}
				else if( borrow == '1'){
					str[k+subtracted-subtractor] = '1';
					borrow = '1';
				}
			}
			
			
			else if( str2[k] == '1'){
				if( borrow == '0'){
					str[k+subtracted-subtractor] = '1';
					borrow = '1';
				}
				else if( borrow == '1'){
					str[k+subtracted-subtractor] = '0';
					borrow = '1';
				}
			}
		}
		
		else if(str[k+subtracted-subtractor] == '1'){
			if( str2[k] == '0'){
				if( borrow == '0'){
					str[k+subtracted-subtractor] = '1';
					borrow = '0';
				}
				else if( borrow == '1'){
					str[k+subtracted-subtractor] = '0';
					borrow = '0';
				}
			}
			
			else if( str2[k] == '1'){
				if( borrow == '0'){
					str[k+subtracted-subtractor] = '0';
					borrow = '0';
				}
				else if( borrow == '1'){
					str[k+subtracted-subtractor] = '1';
					borrow = '1';
				}
			}
		}
	}

	if( borrow == '1'){
		for(int m = subtracted-subtractor-1; m >= 0; m--){
			if(str[m] == '1'){
				str[m] = '0';
				break;
			}
			str[m] = '1';
		}
	}

	borrow = '0';
	return str;
}



char* remove_Zeroes(char* in){
	int s = strlen(in);
	char* out;

	if(s >= 4){
		bool all_zero = true;
		for(int t = 0; t < s/2; t++){
			if(in[t] == '1'){
				all_zero = false;
				break;
			}
		}
		if(all_zero){
			out = new char [(s/2)+1];
			for(int i = 0; i < s/2; i++){
				out[i] = in[i+(s/2)];
			}
			out[s/2] = '\0';
			delete [] in;
			return out;
		}
	}

	return in;
}


bool  appropriate_for_removing_Zeroes(char* in){
	int s = strlen(in);
	
	if(s >= 4){
		for(int t = 0; t < s/2; t++){
			if(in[t] == '1'){
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}



char*  Multiply_by_Divide_and_Conquer(char* str, char* str2, int depth){
	char* result;
	int multiplicand = strlen(str);    //  -->  n
	int multiplier = strlen(str2);     //  -->  n
	int n = multiplicand;
	
	
	if( multiplicand < multiplier ){
		cout << "\nERROR :   Multiplicand order is smaller than multiplier order!!\n\n";
		return '\0';
	}
	
	if( multiplicand != multiplier ){
		cout << "\nWARNING :   Multiplicand and multiplier do not have the same order!!\n\n";
		cout << "Multiplicand: " << multiplicand << "\tMultiplier: " << multiplier << endl << endl;
	}
	
	
	if(multiplicand == 1){

		if( (strcmp(str, "1") == 0)  &&  (strcmp(str2, "1") == 0) ){
			char* ret = new char [3];
			strcpy(ret, "01");
			return ret;
		}
		
		else {
			char* ret2 = new char [3];
			strcpy(ret2, "00");
			return ret2;
		}
	}

	result = new char [2*n+1];
	
	for(int i = 0; i < 2*n; i++){
		result[i] = '0';
	}
	result[2*n] = '\0';
	
	
	char *xL, *xR, *yL, *yR;
	xL = new char [(n/2)+1];
	xR = new char [(n/2)+1];
	yL = new char [(n/2)+1];
	yR = new char [(n/2)+1];
	
	strncpy( xL, str,        (n/2) );
	strncpy( xR, str+(n/2),  (n/2) );
	strncpy( yL, str2,       (n/2) );
	strncpy( yR, str2+(n/2), (n/2) );
	
	xL[n/2] = '\0';
	xR[n/2] = '\0';
	yL[n/2] = '\0';
	yR[n/2] = '\0';

	char *P1, *P2, *P3, *SumX, *SumY, *term_1, *term_2, *term_3;
	
	SumX = new char [n+1];
	SumY = new char [n+1];
	term_1 = new char [2*n+1];
	term_3 = new char [n+1];
	
	for(int i = 0; i < n; i++){
		SumX[i] = '0';
		SumY[i] = '0';
	}
	SumX[n] = '\0';
	SumY[n] = '\0';

	for(int i = 0; i < 2*n; i++){
		term_1[i] = '0';
	}
	term_1[2*n] = '\0';
	
	if(n > 2){
		term_2 = new char [2*n+1];
		for(int i = 0; i < 2*n; i++){
			term_2[i] = '0';
		}
		term_2[2*n] = '\0';
	}
	else if(n == 2){
		term_2 = new char [(3*n/2)+2];
		for(int i = 0; i < (3*n/2)+1; i++){
			term_2[i] = '0';
		}
		term_2[(3*n/2)+1] = '\0';
	}

	for(int i = 0; i < n; i++){
		term_3[i] = '0';
	}
	term_3[n] = '\0';

	P1 = Multiply_by_Divide_and_Conquer(xL, yL, depth+1);
	P2 = Multiply_by_Divide_and_Conquer(xR, yR, depth+1);
	
	SumX = add_binary_strings( SumX, xL);
	SumX = add_binary_strings( SumX, xR);
	
	SumY = add_binary_strings( SumY, yL);
	SumY = add_binary_strings( SumY, yR);
	
	if( (strlen(SumX) == 2)  &&  (strlen(SumY) == 2) ){
		if( ( SumX[0] == '0' )  &&  ( SumY[0] == '0' ) ){
			char x = SumX[1];
			char y = SumY[1];
			
			delete [] SumX;
			delete [] SumY;
			
			SumX = new char [2];
			SumX[0] = x;
			SumX[1] = '\0';
			
			SumY = new char [2];
			SumY[0] = y;
			SumY[1] = '\0';
		}
	}

	bool check_1, check_2;
	check_1 = appropriate_for_removing_Zeroes(SumX);
	check_2 = appropriate_for_removing_Zeroes(SumY);
	if( check_1 && check_2 ){
		P3 = Multiply_by_Divide_and_Conquer(remove_Zeroes(SumX), remove_Zeroes(SumY), depth+1);
	}
	else {
		P3 = Multiply_by_Divide_and_Conquer(SumX, SumY, depth+1);
	}

	term_1 = add_binary_strings(term_1, P1);
	term_1 = shift_binary_string(term_1, n);

	term_2 = add_binary_strings(term_2, P3);
	term_2 = subtract_binary_strings(term_2, P1);
	term_2 = subtract_binary_strings(term_2, P2);
	term_2 = shift_binary_string(term_2, n/2);

	term_3 = add_binary_strings(term_3, P2);

	result = add_binary_strings(result, term_1);
	result = add_binary_strings(result, term_2);
	result = add_binary_strings(result, term_3);
	
	return result;
}


clock_t t1, t2, t3, t4;

int main(int argc, char *argv[]){

	if( argc != 2 ){
		cout << "\nIncorrect entry!!\n";
		return 0;
	}

	char* file_name;
	file_name = new char [strlen(argv[1]) + 1];
	strcpy(file_name, argv[1]);
	
	srand(time(NULL));
	
	char *result_1;
	char *result_2;
	int length;

	char *number_1, *number_2;

	cout << "\nHow many bit numbers do you want to generate?\n(2, 4, 8, 16, 32, 64, 128, 256, 512 or 1024):  ";
	
	while(true){
		cin >> length;
		if( (length==2) || (length==4) || (length==8) || (length==16) || (length==32) || (length==64) || (length==128) || (length==256) || (length==512) || (length==1024) || (length==2048) || (length==4096)){
			break;
		}
		cout << "\nWRONG ENTRY, try again (2, 4, 8, 16, 32, 64, 128, 256, 512 or 1024):  ";
	}

	cout << endl << endl;

	number_1 = new char [length+1];
	for(int i = 0; i < length; i++){
		number_1[i] = '0' + (rand()%2);
	}
	number_1[length] = '\0';
	
	
	number_2 = new char [length+1];
	for(int j = 0; j < length; j++){
		number_2[j] = '0' + (rand()%2);
	}
	number_2[length] = '\0';

	t1 = clock();
	result_1 = Classical_Multiplication(number_1, number_2);
	t2 = clock();

	t3 = clock();
	result_2 = Multiply_by_Divide_and_Conquer(number_1, number_2, 0);
	t4 = clock();

	ofstream textFile;
	textFile.open(file_name);

	textFile << endl << length << "-bit x " << length << "-bit" << endl << "-------------------" << endl;
	textFile << "Number-1 :  " << number_1 << "\nNumber-2 :  " << number_2 << endl << endl << endl << endl;

	textFile << "RESULT:" << endl << "-------------------" << endl;
	textFile << "Classical:  " << result_1 << endl;
	textFile << "Karatsuba:  " << result_2 << endl << endl << endl << endl;

	textFile << "DURATION:" << endl << "-------------------" << endl;
	textFile << "Classical :  " << t2-t1 << " millisecond" << endl;
	textFile << "Karatsuba :  " << t4-t3 << " millisecond" << endl;
	
	cout << "-> Outcomes successfully written to output file" << endl;
	
	if( strcmp(result_1, result_2) == 0 ){
		cout << "-> Both results are the same";
	}

	cout << endl << endl;
	getchar();
	return 0;
}