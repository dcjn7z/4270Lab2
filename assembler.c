#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void scanInstructionID(FILE* fp, char* instructionPtr){
	if (fp==NULL){
		printf("File failed\n");}
	fscanf(fp,"%s",instructionPtr);
	printf("%s\n",instructionPtr);
	return;
	}

void addRegister(char *reg,uint32_t *numberPtr,char *regID){
	uint32_t adder = 0;
	if(strcmp(reg,"zero")==0){
		adder=0;}
	else if(strcmp(reg,"a0")==0){
		adder=4;}

	if(strcmp(regID,"rs")==0){
		adder=adder<<21;}
	else if(strcmp(regID,"rt")==0){
		adder=adder<<16;}
	else{
		adder=adder<<11;}
	printf("%x\n",*numberPtr);
	printf("%x\n", adder);
	*numberPtr=*numberPtr+adder;

	return;
}
void addIntermediate(int intermediate, int *numberPtr){
	
}
void addTarget(int target,int *numberPtr){

}

void convertFileToHex(uint32_t *numberPtr,char * instructionID,FILE* fp){
	char rs[4],rt[4],rd[4];
	uint32_t immed=0;
	uint32_t target=0;

	if( strcmp(instructionID,"add")==0 ){
		*numberPtr = *numberPtr+0x00000020;
		fscanf(fp,"$%s, $%s, $%s",rs,rt,rd);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addRegister(rd,numberPtr,rd);}
	
	if(strcmp(instructionID,"addiu")==0){
		*numberPtr = *numberPtr + 0x24000000;
		fscanf(fp, "$%s, $%s, %x",rt,rs,&immed);
		printf("%s\n%s\n%x\n",rt,rs,immed);}
}

void writeHexToFile(uint32_t hexNumber,char* outputfile){
	FILE* fp2 = fopen(outputfile,"a");
	fprintf(fp2, "%x\n",hexNumber);
	fclose(fp2);
	return;
	}


int main (void) {

	printf("Enter input file\n");
	char inputfile[64];
	scanf("%s",inputfile);
	
	printf("Enter output file\n");
	char outputfile[64];
	scanf("%s", outputfile);

	char instructionID[6];
	uint32_t hexInstruction=0;
	
	FILE* fp=fopen(inputfile,"r");
	
	scanInstructionID(fp,instructionID);

	while (strcmp(instructionID,"syscall")!=0){
		convertFileToHex(&hexInstruction,instructionID,fp);
		writeHexToFile(hexInstruction,outputfile);
		scanInstructionID(fp, instructionID);
		}
	
	fclose(fp);
	return 1;
	}


