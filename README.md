# miniTWOWScoreCalculatorButInCpp1
Since I am used in C++ the most, I try making a prototype using the language.

# Repository
The repository of this program can be found here:

https://github.com/GH-TpaeFawzen/miniTWOWScoreCalculatorButInCpp1

# To Users
This is how it works. **This is for single-voting screen without keyword.** If you are using some screens, I'm sorry, but please wait for new update.
1. Download "Prototype1.cpp" and compile the file into execution file. (*I'm sorry, but please prepare C++ compiler.*)
2. Execute the file.
3. It will ask you some questions, so follow those.
4. The file will give you text that you should copy and paste to your spreadsheet.

## Restruction
To use the program, your voting-screen must be like this:
1. There's only a voting screen.
2. It has 2 or more and 26 or less responses.

## Note
If you add "-d" as an option, you can run in debug mode!

Also, **feel free to leave "Issues".**

# To Contributers
Feel free to fork my code and leave me "Issues".

# New Request Definition (added on 2018/08/22)
1. You can choose one of the following options if you get the vote having same characters twice or more times:
	1. Only the higher/highest one will be counted.
	2. Only the lower/lowest one will be counted.
	3. The vote will be invalid.

# Request Definition
1. To use this tool, all the following conditions must be satisfied:
	1. You're using **only a voting screen so no keywords are necessary for votes.**
	2. It has **from 2 to 26 responses.**
	3. From above, **each response has alphabet from letter A in alphabetical order.**
	4. **Each vote has no square brackets.**
	7. **Each voter voted only once.**
	5. ~~**Any votes having same characters twice or more times will be invalid.** e.g. *A*BCDEF*A*~~
	8. **If any invalid characters are containing to the vote, the characters will be removed and it'll be new vote.**
	6. You are using **spreadsheet** or something to make results.
2. You are asked to input how many responses there are and you input the value.
	1. You input the value from 2 to 26, the program goes to the next step.
	6. Otherwise, it shows the error and the program ends.
3. You are asked to input how many votes you received.
4. You are asked to input each vote.
	1. Every time you input, the average and standard deviation will be calculated **unless the vote is invalid.**
5. The program shows the text in the following format to paste your spreadsheet.
	1. alphabet (space) average (space) standard deviation (newline)

~~# What features should be contained on next version
1. You can choose one of the following options if you get the vote having same characters twice or more times:
	1. Only the higher/highest one will be counted.
	2. Only the lower/lowest one will be counted.
	3. The vote will be invalid.~~
