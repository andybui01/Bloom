import random

# usage: python3 words_gen.py > list.txt

N = 100000 # how many words should be in the resulting list

f = open("scripts/words.txt", "r")
words = f.readlines()

for i in range(N):
    print(words[random.randint(0, 10000 - 1)])

f.close()
