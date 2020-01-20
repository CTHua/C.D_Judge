#include<iostream>
#include<string.h>
#include<stdlib.h>
#include "./hash.h"
#define max_buffer 100
#define N 6  //num of question

using namespace std;

//get stdout from command 
string GetStdoutFromCommand(string cmd)
{
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
//end 

int main(int argc,char** argv)//command : submit date ( argv[1]=date )
{
	string date(argv[1]); 
	string key(getkey(argv[1]));
	//clear the screen
	system("clear");
	printf("\033[0;33m*********************************************************************\n\n\n");
	printf("                       C.D. online judge system                      \n\n\n");
    printf("                    Created by Dark9ive & C.T.Hua                    \n\n\n");
	printf("*********************************************************************\033[0m \n\n");
	//end clear
	//remove ./.judge & copy /io to ./.judge
	system("rm -rf ./.judge 2>/dev/null; mkdir ./.judge");
	string cpio;
	cpio.append("cp -r /home1/student/stud108/s10829/judge/io/" + date + " ./.judge/io");
	system(cpio.c_str());
	//end remove
	system("gcc ./main.c -o ./.judge/cp1.out -lm");  //compile main.c
	//mkdir /date/USER name/
		//29
	string mkdir_29 = "mkdir /home1/student/stud108/s10829/judge/upload/";
	mkdir_29.append(date + "/$USER/ 2>/dev/null");
	system(mkdir_29.c_str());
	string code_29 = "cp ./main.c /home1/student/stud108/s10829/judge/upload/";
	code_29.append(date + "/$USER/");
	system(code_29.c_str());
		//end 29
		//15
	string mkdir_15 = "mkdir /home1/student/stud108/s10815/judge/upload/";
	mkdir_15.append(date + "/$USER/ 2>/dev/null");
	system(mkdir_15.c_str());
	string code_15 = "cp ./main.c /home1/student/stud108/s10815/judge/upload/";
	code_15.append(date + "/$USER/");
	system(code_15.c_str());
		//end 15
	//end mkdir
	
	//write line 1 of score file  ( submit time )
	string results;
	string uploadtime = GetStdoutFromCommand("date +%Y/%m/\%d\\ %T");
	results.append(uploadtime);
	//end write	

	//main funtion
	int correct = 0;
	for(int a = 1; a <= N; a++)
	{
		FILE* executefile;
		executefile = fopen("./.judge/cp1.out", "r");
		if(executefile == NULL)   //check compile fail or not
		{
			printf("\033[0;36mTest %d: CE(Compilation Error)\033[0m \n", a);
			results.append(to_string(a) + " CE \n");
			continue;
		}
		else fclose(executefile);
		//decrypt question
		string decrypt = "crypt \""+ key + "\" <./.judge/io/" + to_string(a) + ".in >./.judge/question.decrypt 2>/dev/null";
		system(decrypt.c_str());
		//end decrypt question
		//excute ./cp1.out
		string exitcode = GetStdoutFromCommand("timeout -s 9 1s ./.judge/cp1.out <./.judge/question.decrypt 1>./.judge/ans.out; echo $?");
		//end excute
		//check TLE or RE
		if(strcmp(exitcode.c_str(), "0\n") != 0)
		{
			if(strcmp(exitcode.c_str(), "137\n") == 0)
			{
				printf("\033[0mTest %d: TLE(Time Limit Exceed)(1 sec)\033[0m \n", a);
				results.append(to_string(a) + " TLE \n");
				continue;
			}
			printf("\033[0;35mTest %d: RE(Runtime Error)\033[0m \n", a);
			results.append(to_string(a) + " RE \n");
			continue;
		}
		//end check TLE or RE
		//check AC or WA
		string CorrectAnsCrypt = GetStdoutFromCommand("cat <./.judge/io/" + to_string(a) + ".out");
		string StudAnsCrypt = GetStdoutFromCommand("crypt \"" + key + "\" <./.judge/ans.out 2>/dev/null");
		if(strcmp(CorrectAnsCrypt.c_str(), StudAnsCrypt.c_str()) == 0)
		{
			printf("\033[0;32mTest %d: AC(Accept)\033[0m \n", a);
			results.append(to_string(a) + " AC \n");
			correct++;
		}
		else
		{
			printf("\033[0;31mTest %d: WA(Wrong Answer)\033[0m \n", a);
			results.append(to_string(a) + " WA \n");
		}	
		//end check AC or WA
	}
	//write down result
	FILE* resultfile = fopen("./.judge/results", "w");
	fwrite(results.c_str(), 1, results.size(), resultfile);
	fclose(resultfile);
	//end write down
	//copy result to s10829 & s10815
	string score_29 = "cp ./.judge/results /home1/student/stud108/s10829/judge/upload/";
	score_29.append(date + "/$USER/score");
	system(score_29.c_str());
	string score_15 = "cp ./.judge/results /home1/student/stud108/s10815/judge/upload/";
	score_15.append(date + "/$USER/score");
	system(score_15.c_str());
	//end copy
	system("rm -rf ./.judge"); //remove ./.judge

	//print successful . score . submit time 
	printf("\n\033[0mSubmission successful!\n\n");
	printf("\033[0;35m--------------------\n| Your score is %d! |\n--------------------\n\n\033[0;33mSubmit time: %s\n", min(max(0, 20*correct-10), 100), uploadtime.c_str());
	//end print
	return 0;
}
