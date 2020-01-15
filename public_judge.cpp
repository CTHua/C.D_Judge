#include<iostream>
#include<string.h>
#include<stdlib.h>
#define max_buffer 100
#define N 6

using namespace std;
string key="meow";
string GetStdoutFromCommand(string cmd){
	string data;
	FILE * stream;
	char buffer[max_buffer];

	stream = popen(cmd.c_str(), "r");
	if(stream){
		while(!feof(stream)){
			if(fgets(buffer, max_buffer, stream) != NULL){
				data.append(buffer);
			}
		}
		pclose(stream);
	}
	return data;
}

int main()
{
//	string key(argv[1]);
	system("clear");
	printf("\033[0;33m*********************************************************************\n\n\n             cos-box-NCCU 1st cp1 mock test online judge\n\n\n*********************************************************************\033[0m \n\n");
	system("rm -rf ./.judge 2>/dev/null; mkdir ./.judge");
	system("cp -r /home1/student/stud108/s10829/judge/io/ans ./.judge/ans");
	system("cp -r /home1/student/stud108/s10829/judge/io/question ./.judge/question");
	system("gcc ./main.c -o ./.judge/cp1.out -lm");
	system("cp ./main.c /home1/student/stud108/s10829/judge/upload/code/$USER.c");
	system("cp ./main.c /home1/student/stud108/s10815/judge/upload/code/$USER.c");
	string results;
	results.append(GetStdoutFromCommand("whoami"));
	string uploadtime = GetStdoutFromCommand("date");
	results.append("Submit Time: " + uploadtime);
	results.append("|");
	int correct = 0;
	for(int a = 1; a <= N; a++){
		FILE* executefile;
		executefile = fopen("./.judge/cp1.out", "r");
		if(executefile == NULL){
			printf("\033[0;36mTest %d: CE(Compilation Error)\033[0m \n", a);
			results.append(" CE |");
			continue;
		}
		else{
			fclose(executefile);
		}
		string decrypt = "crypt "+ key + "<./.judge/question/question" + to_string(a) + ".crypt >./.judge/question.decrypt 2>/dev/null";
		system(decrypt.c_str());
		string exitcode = GetStdoutFromCommand("timeout -s 9 1s ./.judge/cp1.out <./.judge/question.decrypt 1>./.judge/ans.out; echo $?");
		if(strcmp(exitcode.c_str(), "0\n") != 0){
			if(strcmp(exitcode.c_str(), "137\n") == 0){
				printf("\033[0mTest %d: TLE(Time Limit Exceed)(1 sec)\033[0m \n", a);
				results.append(" TLE |");
				continue;
			}
			printf("\033[0;35mTest %d: RE(Runtime Error)\033[0m \n", a);
			results.append(" RE |");
			continue;
		}
		string CorrectAnsCrypt = GetStdoutFromCommand("cat <./.judge/ans/ans" + to_string(a) + ".crypt");
		string StudAnsCrypt = GetStdoutFromCommand("crypt " + key + "<./.judge/ans.out 2>/dev/null");
		if(strcmp(CorrectAnsCrypt.c_str(), StudAnsCrypt.c_str()) == 0){
			printf("\033[0;32mTest %d: AC(Accept)\033[0m \n", a);
			results.append(" AC |");
			correct++;
		}
		else{
			printf("\033[0;31mTest %d: WA(Wrong Answer)\033[0m \n", a);
			results.append(" WA |");
		}
	}
	results.append(" " + to_string(min(max(0, 20*correct-10), 100))+ " |\n");
	FILE* resultfile = fopen("./.judge/results", "w");
	fwrite(results.c_str(), 1, results.size(), resultfile);
	fclose(resultfile);
	system("cp ./.judge/results /home1/student/stud108/s10829/judge/upload/score/$USER");
	system("cp ./.judge/results /home1/student/stud108/s10815/judge/upload/score/$USER");
	system("rm -rf ./.judge");
	printf("\n\033[0mSubmission succesful!\n\n");
	printf("\033[0;35m--------------------\n| Your score is %d! |\n--------------------\n\n\033[0;33mSubmit time: %s\n", min(max(0, 20*correct-10), 100), uploadtime.c_str());
	return 0;
}
