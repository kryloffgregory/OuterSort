import sys
import random
import string
if __name__ == "__main__":
    file = open(sys.argv[1], "w")
    for i in range(int(sys.argv[2])):
        file.write(''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(int(sys.argv[3]))) + '\n')
    file.close()
