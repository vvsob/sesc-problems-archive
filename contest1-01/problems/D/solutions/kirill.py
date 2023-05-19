from collections import deque
import sys
#СПАСИБО ОЛЕЖА ЗА ВЕСЕЛУЮ ЗАДАЧУ

def fin(): return sys.stdin.readline().strip("\r\n")
def fout(s): return sys.stdout.write(str(s) + " ")

# f = open("catapult.in", mode='r')
# of = open("catapult.out", mode='w')

# def fin(): return f.readline().strip("\r\n")
# def fout(s): return of.write(str(s) + " ")


class SlidingWindow:
    def __init__(self):
        self.d = deque()
        self.d: deque
        self.left = 0
        self.r = 0

    def push_back(self, x):
        while len(self.d) > 0 and self.d[-1][0] >= x:
            self.d.pop()
        self.d.append((x, self.r))
        self.r += 1

    def pop_front(self):
        if self.d[0][1] == self.left:
            self.d.popleft()
        self.left += 1

    def get_min(self):
        return 1e13 if len(self.d) == 0 else self.d[0][0]


def sliding_window_minimums(iterable, window_size):
    window = SlidingWindow()
    for i in range(window_size + 1):
        window.push_back(iterable[i])
    yield window.get_min()
    for i in range(len(iterable)):
        if i < window_size:
            if i + window_size + 1 >= len(iterable):
                yield window.get_min()
            else:
                window.push_back(iterable[i + window_size + 1])
                yield window.get_min()
            continue
        if i + window_size + 1 >= len(iterable):
            window.pop_front()
            yield window.get_min()
        else:
            window.push_back(iterable[i+window_size+1])
            window.pop_front()
            yield window.get_min()


def max_strategy(size, ra, sights):
    for i in range(1, size // 2):
        sights[i] = sights[i] + sights[i - 1]
        sights[size - i - 1] = sights[size - i - 1] + sights[size - i]
    if size % 2 != 0:
        sights[size // 2] = max(sights[size // 2 - 1], sights[size // 2 + 1]) + sights[
            size // 2]
    return list(sliding_window_minimums(sights, ra))


def main():
    n, d = list(map(int, fin().split()))
    lst = list(map(int, fin().split()))
    if n == 1:
        fout(1)
        fout(lst[0])
    else:
        ans = max_strategy(n, d, lst)[:-1]
        fout(ans.index(max(ans)) + 1)
        fout(max(ans))


if __name__ == '__main__':
    main()