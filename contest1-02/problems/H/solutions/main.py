def check(w1, w2):
    if len(w1) != len(w2):
        return False
    d = len(list(filter(lambda c: c[0] != c[1], zip(w1, w2))))
    return d <= 1

commands = [input().split()[1:] for i in range(int(input()))]
answer = list()
for s in input().split('. '):
    s = s.replace('.', '')
    rc = -1
    words = s.split()
    for i in range(len(words)):
        for ci, command in enumerate(commands):
            j = 0
            while i + j < len(words) and j < len(command):
                if not check(words[i + j], command[j]):
                    break
                j += 1
            if j == len(command):
                rc = ci + 1
                break
        if rc != -1:
            break
    answer.append(rc)

print(*answer)
