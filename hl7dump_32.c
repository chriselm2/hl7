// Submission:  Chris Elm
//  cerner_2^5_2020
//
#include <stdio.h>
#include <string.h> 
int main() {    
int i=0, iCount=0;
char buffer[4096], byte, fldsep, headr[10];     
while ((fread(&byte,1,1,stdin))) {
	if (i == 3) {
		if ( buffer[0] == 'M' && buffer[1] == 'S' && buffer[2] == 'H') {
			fldsep=byte;
			buffer[3] = '\0';
			strcpy(headr, buffer);
			iCount=1; } }
    if (byte=='\n' || byte=='\r' ) {
		if (i > 0)
			printf("%s-%02d [%s]\n", headr, iCount, buffer);    
		i=0;
		strcpy(buffer, ""); 
		iCount=0; }
	else if (byte==fldsep) {
		if (iCount == 0) {
			buffer[3] = '\0';
			strcpy(headr, buffer); }
		else 
			printf("%s-%02d [%s]\n", headr, iCount, buffer);    
		iCount++;
		i=0;
		strcpy(buffer, ""); }
	else {
		buffer[i++]=byte;
		buffer[i]='\0';     
		buffer[i + 1]='\0';  } }
return 0; }

/* Uses standard in / out for labeling fields in HL7 - 
 * more useful when used in conjunction with other unix commands
 *
 * cat mess.dat | hl7dump
 * MSH-01 [MSH]
 * MSH-02 [^~\&]
 * MSH-03 [SOURCE]
 * MSH-04 [test]
 * MSH-05 [DEST]
 * MSH-06 [test]
 * MSH-07 [20200916134228]
 * MSH-08 []
 * MSH-09 [ADT^A08]
 * MSH-10 [0.68649500]
 * MSH-11 [P]
 * MSH-12 [2.3]
 * EVN-01 [A08]
 * EVN-02 [20191216134228]
 * PID-01 [1]
 * PID-02 []
 * PID-03 [CERDM0720]
 * 
 */

