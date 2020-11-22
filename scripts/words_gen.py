import random
import sys

# usage: python3 words_gen.py > list.txt

N = int(sys.argv[1]) # how many words should be in the resulting list

with open("scripts/words.txt", "r") as f:
    words = f.readlines()

    for i in range(N):
        print(words[random.randint(0, 466550 - 1)].rstrip())
