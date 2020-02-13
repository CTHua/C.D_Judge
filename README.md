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

__WARNING: This project is NOT designed for general user and IS NOT EXPECTING ANY ONE EXCEPT DEVELOPERS TO EXECUTE!!__  
__Running these compiled executable files may CAUSE DAMAGE TO YOUR PERSONAL FILES!!__  
__SO MAKE SURE YOU KNOW WHAT YOU ARE DOING!!__  
__DO EVERYTHING AT YOUR OWN RISK!!__  

### Ganerate encrypted question files

You must encrypted your own question with following commands:  

```
1keyencrypt test_date(YYYYMMDD) nums_of_questions
```

### Submit answers

```
/home1/student/stud108/s10829/judge/submit "date"
```

## Intro

This is a simple judge system. Only Supports NCCU-ghost(ghost.cs.nccu.edu.tw) currently.  
Planning on making this a website version since we still need more sql and html techniques.  

### 1keyencrypt

1keyencrypt is a C++ compiled executable using [crypt(1)](https://docs.oracle.com/cd/E19253-01/816-5165/crypt-1/index.html) and [md5 package from openssl](https://www.openssl.org/docs/man1.1.0/man3/MD5_Init.html).  


## Submission status

Please visit our [website](http://www.cs.nccu.edu.tw/~s10829/index.html) for current submission status.
