void scanInstructionID(char * inputfile, char** instructionPtr){
	FILE* fp=fopen(inputfile,"r");
	fscanf(fp,"%s",instructionPtr);
	fclose(fp);
	return;
	}

void convertFileToHex(char * inputfile, uint32_t * numberPtr,char * instructionID){
	FILE* fp=fopen(inputfile,"r");

	if( strcmp(instructionID,"add")==0 ){
		*numberPtr = *numberPtr+0x00000020;
		char rs[4],rt[4],rd[4];
		fscanf(fp,"$%s, $%s, $%s",rs,rt,rd);
		fclose(fp);

		addRType(rs,rt,rd,numberPtr);
	}
	
	if(strcmp(instructionID,"addiu")==0){
		*numberPtr = *numberPtr + 0x24000000;
		char rs[4], rt[4];
		uint32_t immed=0;
		fscanf(fp, "$%s, $%s, 0x%x",rt,rs,immed);
		fclose(fp);
		
void addRegister(char *reg, int *numberPtr){

}
void addIntermediate(int intermediate, int *numberPtr){

}
void addTarget(int target,int *numberPtr){

}

void writeHexToFile(uint32_t hexNumber,char* outputfile){
	FILE* fp = fopen(outputfile,"a");
	fprintf(fp, "%x\n",hexNumber);
	fclose(fp);
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

	scanInstructionID(inputfile, &instructionID);

	while (instructionID!="syscall"){
		convertFileToHex(inputfile,instructionID);
		writeHexToFile(hexInstruction,outputfile);
		fscanf(input,"%s",instructionID);
		}
	
	printf("syscall\n");

	fclose(inputfile);

	return 1;
	}


