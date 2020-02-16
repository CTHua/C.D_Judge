# C.D_Judge

This is a simple judge system.  
Only supports on NCCU-ghost(ghost.cs.nccu.edu.tw) currently.  
Created by [CTHua](https://github.com/CTHua) & [Dark9ive](https://github.com/dark9ive).  

## Get started

Step 1. Clone the project to your own directory using the following command:

```
git clone https://github.com/CTHua/C.D_Judge.git
```

Step 2. Change directory into the cloned folder:

```
cd ./C.D_Judge
```

Step 3. Compile necessary files:

```
make
```

## Usage

__WARNING:   
This project is NOT designed for general user and IS NOT EXPECTING ANY ONE EXCEPT DEVELOPERS TO EXECUTE!!__  
__Running these compiled executable files may CAUSE DAMAGE TO YOUR PERSONAL FILES!!__  
__SO MAKE SURE YOU KNOW WHAT YOU ARE DOING!!__  
__DO EVERYTHING AT YOUR OWN RISK!!__  

### Ganerate encrypted question files

You must encrypted your own question with following commands:  

```
1keycrypt test_date(YYYYMMDD) nums_of_questions
```

### Submit answers

```
/home1/student/stud108/s10829/judge/submit "date"
```

## Intro

This is a simple judge system. Only supports NCCU-ghost(ghost.cs.nccu.edu.tw) currently.  
Planning on making this a website version since we still need more SQL and html techniques.  

### 1keyencrypt

1keyencrypt is a C++ compiled executable using [crypt(1)](https://docs.oracle.com/cd/E19253-01/816-5165/crypt-1/index.html) and [MD5 package from OpenSSL](https://www.openssl.org/docs/man1.1.0/man3/MD5_Init.html).  
The program uses the date to generate a special key, which will later be used on encrypt input files.  
  
The Key is generated by the following process:

1. Get MD5 hash of the input date.  
2. Transform the 128-bit hash result into 16 characters(8 bits per character).  
3. Take the first 8 digits of the transformed characters as the encrypt key.  
4. If there is any null byte(0x00) in the key, change it to 0x01.  

After the key is generated, the script will then encrypt the input and output files using crypt command with the key above.  
  
Although crypt(1) is considered not secure enough, we still use it as our encrypt tool because of its convienience. Plus, the key is hard to be brute-forced since there are about 2<sup>64</sup> combinations in total, and the examinees only know that the key has something to do with the date.Despite of that, we still planned to add a feature of letting the user to set their own password rather than bind   

## Submission status

Please visit our [website](http://www.cs.nccu.edu.tw/~s10829/index.html) for current submission status.
