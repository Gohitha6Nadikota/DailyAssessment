'''Consider the following dialog.

- Father, what is the lack of logic?
- Bunny.
- Where?
- Day./>/>/>

As you see, father's answers have no logic demonstrating the son the notion of "lack of logic" using live example :D

Let's try to formalize things. Note that both father's answers have no common letters with the corresponding questions. 
Probably this is the reason. Let's say that the answer has no logic if it has no common letters with the question.
 Your task is to write a bot that will answer annoying comments of contestants at codechef using this definition.
  Note that letter denotes a lowercase or uppercase English alphabet (ASCII code from 65 to 90 or from 97 to 122).

Namely, you will be given several questions and you need to produce answers to these questions that have no logic.
 Note that lowercase and uppercase letters are considered the same when treating "no common letters" rule. 
 Also note that this rule concerns only letters. The answer should contain at least one letter.
 If it is impossible to produce such answer then output "~" (tilde sign, quotes are for clarity).'''

t=int(input())
l=[]
for i in range(t):
    s=input()
    s=s.upper()
    di={}
    for x in s:
        if x not in di:
            di[x]=1
    c=1
    for i in range(65,91):
        if chr(i) not in di:
            print(chr(i),end="")
            c=0
    if c==1:
        print("~",end="")
    print()
        