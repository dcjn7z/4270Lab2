#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

void addRegister(char *reg,uint32_t *numberPtr,char *regID){
	uint32_t adder = 0;
	if(strcmp(reg,"ze")==0){
		adder=0;}
	else if(strcmp(reg,"at")==0){
		adder=1;}
	else if(strcmp(reg,"v0")==0){
		adder=2;}
	else if(strcmp(reg,"v1")==0){
		adder=3;}
	else if(strcmp(reg,"a0")==0){
		adder=4;}
	else if(strcmp(reg,"a1")==0){
		adder=5;}
	else if(strcmp(reg,"a2")==0){
		adder=6;}
	else if(strcmp(reg,"a3")==0){
		adder=7;}
	else if(strcmp(reg,"t0")==0){
		adder=8;}
	else if(strcmp(reg,"t1")==0){
		adder=9;}
	else if(strcmp(reg,"t2")==0){
		adder=10;}
	else if(strcmp(reg,"t3")==0){
		adder=11;}
	else if(strcmp(reg,"t4")==0){
		adder=12;}
	else if(strcmp(reg,"t5")==0){
		adder=13;}
	else if(strcmp(reg,"t6")==0){
		adder=14;}
	else if(strcmp(reg,"t7")==0){
		adder=15;}
	else if(strcmp(reg,"s0")==0){
		adder=16;}
	else if(strcmp(reg,"s1")==0){
		adder=17;}
	else if(strcmp(reg,"s2")==0){
		adder=18;}
	else if(strcmp(reg,"s3")==0){
		adder=19;}
	else if(strcmp(reg,"s4")==0){
		adder=20;}
	else if(strcmp(reg,"s5")==0){
		adder=21;}
	else if(strcmp(reg,"s6")==0){
		adder=22;}
	else if(strcmp(reg,"s7")==0){
		adder=23;}
	else if(strcmp(reg,"t8")==0){
		adder=24;}
	else if(strcmp(reg,"t9")==0){
		adder=25;}
	else if(strcmp(reg,"$k0")==0){
		adder=26;}
	else if(strcmp(reg,"$k1")==0){
		adder=27;}
	else if(strcmp(reg,"$gp")==0){
		adder=28;}
	else if(strcmp(reg,"$sp")==0){
		adder=29;}
	else if(strcmp(reg,"$fp")==0){
		adder=30;}
	else if(strcmp(reg,"$ra")==0){
		adder=31;}
	else{
		printf("Error on register translation %s\n",reg);}

	if(strcmp(regID,"rs")==0){
		adder=adder<<21;}
	else if(strcmp(regID,"rt")==0){
		adder=adder<<16;}
	else if(strcmp(regID,"rd")==0){
		adder=adder<<11;}
	else{
		printf("Error on registerID %s\n",regID);}

	printf("Reg = %s RegID = %s\n", reg, regID);
	printf("Instruction before adder= %x\n",*numberPtr);
	printf("adder= %x\n", adder);
	*numberPtr=*numberPtr+adder;
	printf("Instruction after adder= %x\n",*numberPtr);

	return;
}
void addImmediate(int immediate,uint32_t *numberPtr){
	*numberPtr = *numberPtr + immediate;	
}
void addTarget(int target,uint32_t *numberPtr){
	*numberPtr = *numberPtr + target;
}

void writeHexToFile(uint32_t hexNumber,char* outputfile){
	FILE* fp2 = fopen(outputfile,"a");
	if(fp2==NULL){
		printf("Error opening output file\n");}
	fprintf(fp2, "%08x\n",hexNumber);
	fclose(fp2);
	return;
	}


int main (int argc, char *argv[]) {

	char *inputfile = argv[1];
	char *outputfile = argv[2];
	printf("%s\n",argv[1]);
	printf("%s\n",argv[2]);

	char instructionID[6];
	uint32_t hexInstruction=0;
	char rs[6],rt[6],rd[6];
	uint32_t immed=0;
	uint32_t target=0;
	uint32_t sa=0;

	FILE* fp=fopen(inputfile,"r");
	if(fp==NULL){
		printf("Error opening input file\n");}
	
	fscanf(fp,"%s",instructionID);
	printf("Instruction = %s\n",instructionID);

	while (strcmp(instructionID,"syscall")!=0){
		hexInstruction=0;	
	//**	if( strcmp(instructionID,"add")==0 ){
			hexInstruction = hexInstruction+0x00000020;
			fscanf(fp,"$%s, $%s, $%s",rd,rs,rt);
			addRegister(rs,numberPtr,rs);
			addRegister(rt,numberPtr,rt);
			addRegister(rd,numberPtr,rd);}
	
		else if( strcmp(instructionID,"sll")==0 ){
			hexInstruction = hexInstruction+0x00000000;
			fscanf(fp,"$%s, $%s, 0x%x",rd,rt,&sa);
			addRegister(rt,numberPtr,rt);
			addRegister(rd,numberPtr,rd);
			*numberPtr=*numberPtr +(sa<<6);
			}
	
		else if( strcmp(instructionID,"srl")==0 ){
			*numberPtr = *numberPtr+0x00000002;
			fscanf(fp,"$%s, $%s, 0x%x",rd,rt,&sa);
			addRegister(rt,numberPtr,rt);
			addRegister(rd,numberPtr,rd);
			*numberPtr=*numberPtr+(sa<<6);}

		else if( strcmp(instructionID,"sra")==0 ){
			*numberPtr = *numberPtr+0x00000003;
			fscanf(fp,"$%s, $%s, 0x%x",rd,rt,&sa);
			addRegister(rt,numberPtr,rt);
			addRegister(rd,numberPtr,rd);
			*numberPtr=*numberPtr+(sa<<6);}
	
		else if( strcmp(instructionID,"jr")==0 ){
			*numberPtr = *numberPtr+0x00000008;
			fscanf(fp,"$%s",rs);
			addRegister(rs,numberPtr,rs);}
	
		else if( strcmp(instructionID,"jalr")==0 ){
			*numberPtr = *numberPtr+0x00000009;
			fscanf(fp,"$%s\n,JALR $%s, $%s",rs,rd,rs);
			addRegister(rs,numberPtr,rs);
			addRegister(rt,numberPtr,rt);
			addRegister(rd,numberPtr,rd);}
		
		else if( strcmp(instructionID,"mfhi")==0 ){
		*numberPtr = *numberPtr+0x00000010;
		fscanf(fp,"$%s",rd);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"mthi")==0 ){
		*numberPtr = *numberPtr+0x00000011;
		fscanf(fp,"$%s",rs);
		addRegister(rs,numberPtr,rs);}

	else if( strcmp(instructionID,"mflo")==0 ){
		*numberPtr = *numberPtr+0x00000012;
		fscanf(fp,"$%s",rd);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"mtlo")==0 ){
		*numberPtr = *numberPtr+0x00000013;
		fscanf(fp,"$%s",rs);
		addRegister(rs,numberPtr,rs);}

	else if( strcmp(instructionID,"mult")==0 ){
		*numberPtr = *numberPtr+0x00000018;
		fscanf(fp,"$%s, $%s",rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);}

	else if( strcmp(instructionID,"multu")==0 ){
		*numberPtr = *numberPtr+0x00000019;
		fscanf(fp,"$%s, $%s",rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);}

	else if( strcmp(instructionID,"div")==0 ){
		*numberPtr = *numberPtr+0x0000001a;
		fscanf(fp,"$%s, $%s",rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);}

 	else if( strcmp(instructionID,"divu")==0 ){
		*numberPtr = *numberPtr+0x0000001b;
		fscanf(fp,"$%s, $%s",rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);}

	else if( strcmp(instructionID,"addu")==0 ){
		*numberPtr = *numberPtr+0x00000021;
		fscanf(fp,"$%s, $%s, $%s",rd,rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"sub")==0 ){
		*numberPtr = *numberPtr+0x00000022;
		fscanf(fp,"$%s, $%s, $%s",rd,rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"subu")==0 ){
		*numberPtr = *numberPtr+0x00000023;
		fscanf(fp,"$%s, $%s, $%s",rd,rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"and")==0 ){
		*numberPtr = *numberPtr+0x00000024;
		fscanf(fp,"$%s, $%s, $%s",rd,rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"or")==0 ){
		*numberPtr = *numberPtr+0x00000025;
		fscanf(fp,"$%s, $%s, $%s",rd,rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"xor")==0 ){
		*numberPtr = *numberPtr+0x00000026;
		fscanf(fp,"$%s, $%s, $%s",rd,rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"nor")==0 ){
		*numberPtr = *numberPtr+0x00000027;
		fscanf(fp,"$%s, $%s, $%s",rd,rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"slt")==0 ){
		*numberPtr = *numberPtr+0x0000002a;
		fscanf(fp,"$%s, $%s, $%s",rd,rs,rt);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addRegister(rd,numberPtr,rd);}

	else if( strcmp(instructionID,"bltz")==0 ){
		*numberPtr = *numberPtr+0x04000000;
		fscanf(fp,"$%s, 0x%x",rs,&immed);
		addRegister(rs,numberPtr,rs);
		addImmediate(immed,numberPtr);}
	
	else if( strcmp(instructionID,"bgez")==0 ){
		*numberPtr = *numberPtr+0x04010000;
		fscanf(fp,"$%s, 0x%x",rs,&immed);
		addRegister(rs,numberPtr,rs);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"j")==0 ){
		*numberPtr = *numberPtr+0x08000000;
		fscanf(fp,"0x%x",&target);
		addTarget(target,numberPtr);}

	else if( strcmp(instructionID,"jal")==0 ){
		*numberPtr = *numberPtr+0x0c000000;
		fscanf(fp,"0x%x",&target);
		addTarget(target,numberPtr);}

	else if( strcmp(instructionID,"beq")==0 ){
		*numberPtr = *numberPtr+0x10000000;
		fscanf(fp,"$%s,$%s, 0x%x",rs,rt,&immed);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}
	
	else if( strcmp(instructionID,"bne")==0 ){
		*numberPtr = *numberPtr+0x14000000;
		fscanf(fp,"$%s, $%s, 0x%x",rs,rt,&immed);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"blez")==0 ){
		*numberPtr = *numberPtr+0x18000000;
		fscanf(fp,"$%s, 0x%x",rs,&immed);
		addRegister(rs,numberPtr,rs);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"bgtz")==0 ){
		*numberPtr = *numberPtr+0x1c000000;
		fscanf(fp,"$%s, 0x%x",rs,&immed);
		addRegister(rs,numberPtr,rs);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"bgez")==0 ){
		*numberPtr = *numberPtr+0x04010000;
		fscanf(fp,"$%s, 0x%x",rs,&immed);
		addRegister(rs,numberPtr,rs);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"addi")==0 ){
		*numberPtr = *numberPtr+0x20000000;
		fscanf(fp,"$%s, $%s, 0x%x",rt,rs,&immed);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}
	**//
	else if(strcmp(instructionID,"addiu")==0){
		hexInstruction = hexInstruction + 0x24000000;
		fscanf(fp, "%s %s %x",rt,rs,&immed);
		printf(" rt = %s, rs = %s, immed = %x\n",rt,rs,immed);
		addRegister(rs,&hexNumber,rs);
		addRegister(rt,&hexNumber,rt);
		addRegister(rd,&hexNumber,rd);}

//**	
	else if( strcmp(instructionID,"slti")==0 ){
		*numberPtr = *numberPtr+0x28000000;
		fscanf(fp,"%s, %s, 0x%x",rt,rs,&immed);
		addRegister(rs,numberPtr,rs);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"andi")==0 ){
		*numberPtr = *numberPtr+0x04010000;
		fscanf(fp,"$%s, 0x%x",rs,&immed);
		addRegister(rs,numberPtr,rs);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"ori")==0 ){
		*numberPtr = *numberPtr+0x34000000;
		fscanf(fp,"$%s, $%s, 0x%x",rt,rs,&immed);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rs);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"xori")==0 ){
		*numberPtr = *numberPtr+0x38000000;
		fscanf(fp,"$%s, $%s, 0x%x",rt,rs,&immed);
		addRegister(rs,numberPtr,rs);
		addRegister(rt,numberPtr,rs);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"lui")==0 ){
		*numberPtr = *numberPtr+0x3c000000;
		fscanf(fp,"$%s, 0x%x",rt,&immed);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"lb")==0 ){
		*numberPtr = *numberPtr+0x80000000;
		fscanf(fp,"$%s, 0x%x",rt,&immed);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"lh")==0 ){
		*numberPtr = *numberPtr+0x84000000;
		fscanf(fp,"$%s, 0x%x",rt,&immed);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"lw")==0 ){
		*numberPtr = *numberPtr+0x8c000000;
		fscanf(fp,"$%s, 0x%x",rt,&immed);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"sb")==0 ){
		*numberPtr = *numberPtr+0xa0000000;
		fscanf(fp,"$%s, 0x%x",rt,&immed);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"sh")==0 ){
		*numberPtr = *numberPtr+0xa4000000;
		fscanf(fp,"$%s, 0x%x",rt,&immed);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}

	else if( strcmp(instructionID,"sw")==0 ){
		*numberPtr = *numberPtr+0xa8000000;
		fscanf(fp,"$%s, 0x%x",rt,&immed);
		addRegister(rt,numberPtr,rt);
		addImmediate(immed,numberPtr);}
**//
	
	else{
		printf("Error, invalid operation %s\n",instructionID);}


		writeHexToFile(hexInstruction,outputfile);
		fscanf(fp,"%s",instructionID);
		printf("Instruction = %s\n",instructionID);
		}
	}
	uint32_t hexInstruction=0x0000000c;
	writeHexToFile(hexInstruction,outputfile);
	fclose(fp);
	return 1;
}


